#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

struct Room {
string building_code;
int room_number;
int max_students;
};

struct Course {
string prefix;
int course_number;
int num_minutes;
int num_lectures;
};

struct Section_Constraints{
int days[4]; // see explanation below
int earliest_start_time;
int latest_end_time;
};

struct Section {
int section_id;
int section_number;
int num_students;
Course course;
Section_Constraints constraints;
};

struct Scheduled_Sections {
  int section_id;
  string prefix;
  int course_number;
  int startTime;
  int endTime;
  int days[4];
  Room room;
  Section section;
};


//Global Variables
static const size_t npos = -1;
int numRooms = 0;
int lineIndex = 0;
int scheduledCount = 0;
Room *rooms;
Course *courses;
Section *sections;
Section_Constraints *allConstraints;
Scheduled_Sections *scheduledSections;

//Prototypes
bool sortWay(const Room &lhs, const Room &rhs);//Sorts in descending order
void sortRooms();
bool roomsMatch(Room scheduledRoom, int scheduleRoomIndex);
bool daysMatch(int* scheduledDays, int* constraintDays);
int timesOverlap( int scheduledStartTime, int scheduledEndTime, int constraintStartTime, int constraintEndTime, int numMinutes );
bool scheduleAvailable( Section sectionToSchedule, int roomIndex );
bool scheduleSections();
bool classWay(const Scheduled_Sections &lhs, const Scheduled_Sections &rhs);
bool classWay2(const Scheduled_Sections &lhs, const Scheduled_Sections &rhs);
void sortClass();
bool roomWay(const Scheduled_Sections &lhs, const Scheduled_Sections &rhs);
bool roomWay2(const Scheduled_Sections &lhs, const Scheduled_Sections &rhs);
void sortRoom();

//Main reads the file and dynamically allocates arrays. After sorting the rooms, it schedules the classes, if possible, 
//then prints out the schedule ordered by the course sections and then by the classroom. 
int main()
{

	string file;
	fstream fin;
	stringstream ss;

	string line;
	string lines[100];

	int sectCount;
	string day;

	cout << "Enter the name of your file with '.txt': ";
	cin >> file;

	fin.open(file.c_str());


	while (fin.fail())
	{
    	cout << "Hmm...can't find your file. Please enter it again: " << endl;
		file.clear();
		cin >> file;
		fin.open (file.c_str());
	}

    getline(fin,line);

    if (fin.fail())
	{
		cout << "Your file is improperly formatted...";
		exit(EXIT_FAILURE);
	}

    while (!fin.fail() && line.size() != 0)
    {
		//if (line.size() != 0)//Not a blank line
		//{
		
			if (line.find("--") != 0)//Not a comment
			{
				lines[numRooms] = line;//Stores text in array lines[]
				numRooms++;
			}
		//}
		getline(fin,line);
	}//Done reading line
	
	rooms = new Room[numRooms]; //Creates rooms array the size of # of lines
	//Ask about how structs work in this case
	for (int i = 0; i < numRooms; i++) //places lines array into rooms array
	{
		ss << lines[i];
		ss >> rooms[i].building_code >> rooms[i].room_number >> rooms[i].max_students;
		if (ss.fail())
		{
			cout << "Looks like your file is improperly formatted..." << endl;
			exit(EXIT_FAILURE);
		}
		ss.clear();
	}

//Start reading sections
	getline(fin,line);

    if (fin.fail())
	{
		cout << "Your file is improperly formatted...";
		exit(EXIT_FAILURE);
	}

    while (!fin.fail() && line.size() != 0)
    {
		if (line.find("--") != 0)//Not a comment
		{
			lines[lineIndex] = line;
			lineIndex++;
		}
	
		getline(fin,line);
	}
	
	courses = new Course[lineIndex]; 
	sections = new Section[lineIndex];
	allConstraints = new Section_Constraints[lineIndex];
	scheduledSections = new Scheduled_Sections[lineIndex];  //For later use
	//Creates course array the size of # of lines
	//Ask about how structs work in this case
	for (int i = 0; i < lineIndex; i++) //places lines array into rooms array
	{
		ss << lines[i];
		ss >> sections[i].section_id >> courses[i].prefix >> courses[i].course_number >> sections[i].section_number
		>> courses[i].num_minutes >> courses[i].num_lectures >> sections[i].num_students;
		if (ss.fail())
		{
			cout << "Looks like your file is improperly formatted..." << endl;
			exit(EXIT_FAILURE);
		}
		ss.clear();
	}

//Do last part of file
	getline(fin,line);
	lineIndex = 0;//Reset lineIndex to 0 so this section counts correctly
	
    if (fin.fail())
	{
		cout << "Your file is improperly formatted...";
		exit(EXIT_FAILURE);
	}

    while (!fin.fail() && line.size() != 0)
    {
		//if (line.size() != 0)//Not a blank line
		//{
		
			if (line.find("--") != 0)//Not a comment
			{
				lines[lineIndex] = line;
				lineIndex++;
			}
		//}
		getline(fin,line);
	}
	
	for (int i = 0; i < lineIndex; i++) //places lines array into rooms array
	{
		int j = 0;
		ss << lines[i];
		ss >> sectCount;
		///add: for int k i <lineindex...
		//if sect count == 
		//need it to check all sections in case it's out of order
		if (sectCount == sections[i].section_id)
		{
			ss >> day;
			if (ss.fail())
			{
				cout << "Looks like your file is improperly formatted..." << endl;
				exit(EXIT_FAILURE);
			}
			if (day.find('M') != string::npos)
			{
				allConstraints[i].days[j] = 1;
				j++;
			}
			else
			{
				j++;
			}
			if (day.find('T') != string::npos)
			{
				allConstraints[i].days[j] = 1;
				j++;
			}
			else
			{
				j++;
			}
			if (day.find('W') != string::npos)
			{
				allConstraints[i].days[j] = 1;
				j++;
			}
			else
			{
				j++;
			}
			if (day.find('R') != string::npos)
			{
				allConstraints[i].days[j] = 1;
				j++;
			}
			else
			{
				j++;
			}
			ss >> allConstraints[i].earliest_start_time >> allConstraints[i].latest_end_time;
			if (ss.fail())
			{
				cout << "Looks like your file is improperly formatted..." << endl;
				exit(EXIT_FAILURE);
			}
		}
		ss.clear();
	}
	fin.close();//Done reading file
	//Copies information to sections array
	for (int i = 0; i < lineIndex; i++)
	{
		sections[i].course.prefix = courses[i].prefix;
		sections[i].course.course_number = courses[i].course_number;
		sections[i].course.num_minutes = courses[i].num_minutes;
		sections[i].course.num_lectures = courses[i].num_lectures;

		for (int j = 0; j < 4; j++)
		{
			sections[i].constraints.days[j] = allConstraints[i].days[j];
		}

		sections[i].constraints.earliest_start_time = allConstraints[i].earliest_start_time;
		sections[i].constraints.latest_end_time = allConstraints[i].latest_end_time;
	}

	sortRooms();

	if (scheduleSections() == true)
	{
		sortClass();

		cout << "SCHEDULE BY CLASS" << endl << "~~~~~~~~~~~~~~~~~" << endl << endl;
		cout << scheduledSections[0].prefix << " " << scheduledSections[0].course_number << endl;
		cout << "~~~~~~~~" << endl;
		for (int i = 1; i < lineIndex; i++)
		{
			cout << "Course ID: " << scheduledSections[i-1].section_id << endl;
			cout << "Section #: " << scheduledSections[i-1].section.section_number << endl;
			cout << "# Students: " << scheduledSections[i-1].section.num_students << endl;
			cout << "Room: " << scheduledSections[i-1].room.building_code << " " << scheduledSections[i-1].room.room_number << endl;
			cout << "Capacity: " << scheduledSections[i-1].room.max_students << endl;
			cout << "Meeting day/Time: ";
			if (scheduledSections[i-1].days[0] == 1)
			{
				cout << "M";
			}
			if (scheduledSections[i-1].days[1] == 1)
			{
				cout << "T";
			}
			if (scheduledSections[i-1].days[2] == 1)
			{
				cout << "W";
			}
			if (scheduledSections[i-1].days[3] == 1)
			{
				cout << "R";
			}
			cout << " " << scheduledSections[i-1].startTime << " - " << scheduledSections[i-1].endTime << endl << endl;

			if (scheduledSections[i].prefix != scheduledSections[i-1].prefix || scheduledSections[i].course_number != scheduledSections[i-1].course_number)
			{
				cout << scheduledSections[i].prefix << " " << scheduledSections[i].course_number << endl;
				cout << "~~~~~~~~" << endl << endl;
			}
		}
		sortRoom();

		cout << "SCHEDULE BY ROOM" << endl << "~~~~~~~~~~~~~~~~~" << endl << endl;
		cout << scheduledSections[0].room.building_code << " " << scheduledSections[0].room.room_number;
		cout <<", CAPACITY=" << scheduledSections[0].room.max_students << endl << endl;

		for (int i = 1; i < lineIndex; i++)
		{
			if (scheduledSections[i-1].days[0] == 1)
			{
				cout << "M";
			}
			if (scheduledSections[i-1].days[1] == 1)
			{
				cout << "T";
			}
			if (scheduledSections[i-1].days[2] == 1)
			{
				cout << "W";
			}
			if (scheduledSections[i-1].days[3] == 1)
			{
				cout << "R";
			}
			cout << " " << scheduledSections[i-1].startTime << " - " << scheduledSections[i-1].endTime;
			cout << " " << scheduledSections[i-1].prefix << " " << scheduledSections[i-1].course_number << " ";
			cout << scheduledSections[i-1].section.section_number << " " << scheduledSections[i-1].section_id;
			cout << " # of Students: " << scheduledSections[i-1].section.num_students << endl;

			if (scheduledSections[i].room.building_code != scheduledSections[i-1].room.building_code || scheduledSections[i].room.room_number != scheduledSections[i-1].room.room_number)
			{
				cout << endl << scheduledSections[i].room.building_code << " " << scheduledSections[i].room.room_number;
				cout <<", CAPACITY=" << scheduledSections[i].room.max_students << endl;
				cout << "~~~~~~~~" << endl;
			}
		}


	}

	return 0;
	
}

bool sortWay(const Room &lhs, const Room &rhs)
{
	return lhs.max_students > rhs.max_students;
}

void sortRooms()//Sorts rooms in descending room size
{
	sort(rooms, rooms+numRooms, sortWay);
}

bool roomsMatch(Room scheduledRoom, int scheduleRoomIndex)//Checks if building and room number are the same as something already scheduled
{
	bool roomConflict = false;
	if (rooms[scheduleRoomIndex].building_code == scheduledRoom.building_code && rooms[scheduleRoomIndex].room_number == scheduledRoom.room_number)
	{
		roomConflict = true;
	}
	return roomConflict;
}

bool daysMatch(int* scheduledDays, int* constraintDays)//Only checks days if roomsMatch was true
{
	bool dayConflict = false;
	for (int j = 0; j < 4; j++)
	{
		if (*(constraintDays+j) == (*(scheduledDays+j)))
		{
			dayConflict = true;
			break;
		}
	}
	return dayConflict;
}

int fixTime(int constraintStartTime, int numMinutes)//Gives you the endtime of a class
{
	int totMinutes = (constraintStartTime%100)+numMinutes;
	int hours = 0;
	while (totMinutes > 59)
	{
		totMinutes -= 60;
		hours++;
	}
	
	constraintStartTime += ((100*hours)+totMinutes);
	return constraintStartTime;
}

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
      }

      if ( roomsMatch( scheduledRoom, scheduleRoomIndex ) ) 
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
    scheduledSections[scheduledCount].section.section_number = sectionToSchedule.section_number;
    scheduledSections[scheduledCount].section.num_students = sectionToSchedule.num_students;

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
    if (i == numRooms-1)
    {
    	smallRoomSize = 0;
    }

    //We want to schedule all the rooms that have a size greater than
    //smallRoomSize and less than or equal to bigRoomSize
    for ( int j=0; j<lineIndex; j++ ) 
    {
      if ( sections[j].num_students > smallRoomSize && sections[j].num_students <= bigRoomSize ) 
      {
      	if (i == numRooms-1)
      	{
      		bool scheduled = scheduleAvailable( sections[j], i+1);
      		if ( !scheduled ) 
	        {
	  	      //Have at least one section that cannot be scheduled
	          cout << sections[j].section_id << endl;
	  	      cout<<"have a room that can't be scheduled\n";
	  	      return false;
		    }
      	}
  	   //This is a room we are to schedule
      	else
      	{
	  	    bool scheduled = scheduleAvailable( sections[j], i );
	  	    if ( !scheduled ) 
	        {
	  	      //Have at least one section that cannot be scheduled
	          cout << sections[j].section_id << endl;
	  	      cout<<"have a room that can't be scheduled\n";
	  	      return false;
		    }

	    }
      }
      /*
      else if (sections[j].num_students > smallRoomSize && i == numRooms-2)
      {
      	bool scheduled = scheduleAvailable( sections[j], i+1);
      	if ( !scheduled)
      	{
      		cout << sections[j].section_id << endl;
      		cout << "have a room that can't be scheduled\n";
      		return false;
      	}
      }
      */
    }
  }

  return true;
}

//All the following functions are used to sort the scheduled sections array to print out according
//to course and classroom

bool classWay(const Scheduled_Sections &lhs, const Scheduled_Sections &rhs)
{
	return lhs.prefix < rhs.prefix;
}

bool classWay2(const Scheduled_Sections &lhs, const Scheduled_Sections &rhs)
{
	return lhs.course_number < rhs.course_number;
}

void sortClass()
{
	sort(scheduledSections, scheduledSections+numRooms, classWay);
	sort(scheduledSections, scheduledSections+numRooms, classWay2);
}

bool roomWay(const Scheduled_Sections &lhs, const Scheduled_Sections &rhs)
{
	return lhs.room.building_code < rhs.room.building_code;
}

bool roomWay2(const Scheduled_Sections &lhs, const Scheduled_Sections &rhs)
{
	return lhs.room.room_number < rhs.room.room_number;
}

void sortRoom()
{
	sort(scheduledSections, scheduledSections+numRooms, roomWay);
	sort(scheduledSections, scheduledSections+numRooms, roomWay2);
}
