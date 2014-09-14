//You will have to implement the methods roomsMatch, daysMatch, fixTime

//Here is my struct for keeping track of the scheduled sections. The code 
//below assumes this structure. You will have to dynamically create an
//array of this structure and call it 'scheduledSections'. See below.
struct Scheduled_Sections 
{
  int section_id;
  string prefix;
  int course_number;
  int startTime;
  int endTime;
  int days[4];
  Room room;
};

Scheduled_Sections* scheduledSections;  //You must size the array correctly


int timesOverlap( int scheduledStartTime, int scheduledEndTime, int constraintStartTime, int constraintEndTime, int numMinutes ) 
{
  //Looking for a start time and end time, for the current class, that does
  //not overlap the scheduled start and end time, that are provided
  //Returns -1 if we cannot find a time. Otherwise returns the schedulable start time
  bool scheduled = false;
  while (!scheduled) 
  {
    if ( ( constraintStartTime >= scheduledStartTime && constraintStartTime <= scheduledEndTime ) ||
         ( fixTime(constraintStartTime, numMinutes) >= scheduledStartTime &&
     fixTime(constraintStartTime, numMinutes) <= scheduledEndTime ) ) 
    {
      //Can't start the new section at this time.
      //Advance the start time by numMinutes plus 10 minutes and return.
      //We must now compare this new start time with all scheduled sections
      return fixTime( constraintStartTime, numMinutes+10 );
    } 
    else 
    {
      //This is a possible scheduable start time. We must use the new times for future
      //schedule checks
      break;
    }
  }

  return constraintStartTime;
}

bool scheduleAvailable( Section sectionToSchedule, int roomIndex ) 
{
  int* constraintDays = sectionToSchedule.constraints.days; // see explanation below 
  int constraintStartTime = sectionToSchedule.constraints.earliest_start_time; 
  int originalStartTime = constraintStartTime;
  int constraintEndTime = sectionToSchedule.constraints.latest_end_time;
  int courseLength = sectionToSchedule.course.num_minutes; 
  int currentScheduledCount = scheduledCount;
  Course course = sectionToSchedule.course;

  bool canSchedule = false;
  int scheduleRoomIndex = roomIndex;
  int actualStartTime = constraintStartTime;
  int k=0;

  while ( k < scheduledCount ) 
  {
    if ( canSchedule) 
    {
      //We can schedule, so exit the for loop
      break;
    }

    //Check if there is a conflict with an already scheduled section
    Scheduled_Sections scheduledSection = scheduledSections[k];
    int scheduledStartTime = scheduledSection.startTime;
    int scheduledEndTime = scheduledSection.endTime;
    int* scheduledDays = scheduledSection.days;
    Room scheduledRoom = scheduledSection.room;
    
    actualStartTime  = constraintStartTime;

    int possibleStartTime = constraintStartTime;

    while ( true ) 
    {
      if ( scheduleRoomIndex < 0 ) 
      {
        //Have tried all the rooms. This section cannot be scheduled
        canSchedule = false;
        break;
      }

      if ( roomsMatch( scheduledRoom, rooms[scheduleRoomIndex] ) ) 
      {
        //The needed room matches the already scheduled room
        if ( daysMatch( scheduledDays, constraintDays ) ) 
        {
          //Days match. Check the times. If the days don't match, no overlap.
          possibleStartTime = timesOverlap( scheduledStartTime, scheduledEndTime,
                   actualStartTime, constraintEndTime, 
                   courseLength );
          if ( possibleStartTime != actualStartTime ) 
          {
            //The start time has changed, we must start over with
            //checking scheduled sections, using this new start tim,
            //only if the end time is within the constraintEndTime
            if ( fixTime( possibleStartTime, courseLength+10 ) > constraintEndTime ) 
            {
              //This section cannot be scheduled in this room. Try the next
              //bigger room, and start with the first scheduled section
              possibleStartTime = originalStartTime;
              scheduleRoomIndex--;
              break;
            }

            //The new end time is within the constraint end time, so we 
            //exit the while loop, set k back to 0, and try the new times
            //against all the scheduled sections
            break;
          }

          if ( actualStartTime == -1 ) 
          {
            //Cannot schedule in this room. Try the next biggest room
            actualStartTime = originalStartTime;
            scheduleRoomIndex--;
            continue;
          }

          break;
        }
      }//End of if rooms match

      //Current scheduled section does not overlap the needed section. Try the
      //next scheduled section
      break;
    } //end of while

    //Must increment k since we have a for loop now
    k++;

    if ( possibleStartTime != actualStartTime ) 
    {
      //Must start over using this new start time
      canSchedule = false;
      constraintStartTime = possibleStartTime;
      k=0;
    }
  } //end of while k < scheduled count

  if ( ( scheduledCount == 0 || scheduledCount == k ) && scheduleRoomIndex != -1 ) 
  {
    //No scheduled sections, so we can schedule, OR we went through all the
    //sections and found a schedulable time
    canSchedule = true;
  }

  if ( canSchedule ) 
  {
    //We can scheule this section. So do it.
    scheduledSections[scheduledCount].startTime = actualStartTime;
    scheduledSections[scheduledCount].section_id = sectionToSchedule.section_id;
    scheduledSections[scheduledCount].prefix = course.prefix;
    scheduledSections[scheduledCount].course_number = course.course_number;
    scheduledSections[scheduledCount].endTime = fixTime( actualStartTime, course.num_minutes );
    scheduledSections[scheduledCount].room = rooms[scheduleRoomIndex];

    for ( int i=0; i<4; i++ ) 
    {
      //Copy the day values
      scheduledSections[scheduledCount].days[i] = constraintDays[i];
    }
    scheduledCount++;
  }
 
  return canSchedule;
}

bool scheduleSections() 
{
  //Schedule sections from largest room to smallest room - in section size
  //Schedule all classes that can only fit in the largest room, that hasn't
  //yet been scheduled (starting with the largest room). When that is done
  //go to the next largest room, etc. 
  //This function assumes the rooms array is sorted from largest room to
  //smallest room.
  //numRooms is the total number of rooms that exist

  for ( int i=0; i<numRooms-1; i++ ) 
  {
    //Use roomCount-1, since we check two room size values at a time
    int bigRoomSize = rooms[i].max_students;
    int smallRoomSize = rooms[i+1].max_students;

    //We want to schedule all the rooms that have a size greater than
    //smallRoomSize and less than or equal to bigRoomSize
    for ( int j=0; j<lineIndex; j++ ) 
    {
      if ( sections[j].num_students > smallRoomSize && sections[j].num_students <= bigRoomSize ) 
      {
  	   //This is a room we are to schedule
  	   bool scheduled = scheduleAvailable( sections[j], i );
  	   if ( !scheduled ) 
        {
  	      //Have at least one section that cannot be scheduled
  	      cout<<"have a room that can't be scheduled\n";
  	      return false;
	      }
      }
    }
  }

  return true;
}

