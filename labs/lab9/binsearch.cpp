#include <iostream>
#include <fstream>

using namespace std;

int* sortStep(int *, int, int);
void sort(int *, int);
int binsearch(int, int *, int, int);

int main(int argc, char *argv[]){
  int target;
  if(argc < 2){
    cout << "Provide a filename of the data to be searched" << endl;
    return 1;
  }
  ifstream datfile(argv[1], ios::in);
  if( datfile.fail() ){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;
  }
  int count = 0;
  // Count how many integers are in the file
  while(! datfile.fail()){
    int temp;
    datfile >> temp;
    if(!datfile.fail()){
      count++;
    }
  }
  // When we reach the end of the file, the EOF flag is set
  // To be able to read through the file again we need to clear that flag
  datfile.clear();
  //  We also need to set our internal position in the file back to 0
  datfile.seekg(0,ios::beg);

  // Now allocate an array to store the file data and read in the data
  int *data = new int[count];
  for(int i=0; i < count; i++){
    datfile >> data[i];
  }

  datfile.close();

  cout << "Read " << count << " integers from the data file.\n" << endl;
  cout << "Enter the target positive integer to search for: ";
  cin >> target;

  // Uncomment the line below for part 2
  sort(data, count);
  //for (int i = 0; i < count; i++)
  //{
  //  cout << data[i];
  //}
  //cout << endl;

  // Call binary search
  int retval = binsearch(target,data,0,count);

  // Interpret and print the results
  if(retval == -1){
    cout << target << " does not appear in the data." << endl;
  }
  else {
    cout << target << " appears at index " << retval << " in the data." << endl;
  }

  // Deallocate the data array
  delete [] data;
  return 0;
}


// Returns the index in the data array where target is located
//  or -1 if the target value is not in the list
int binsearch(int target, int *data, int start, int end)
{

  int searching = (end+start)/2;
  //cout << searching<< endl;
  int cmp = *(data+searching);

  if (cmp == target)
  {
    return searching;
  }
  else
  {
    if (start != end)
    {
      //cout << "cmp: " << cmp << endl;
      //cout << "target: " << target << endl;
      if (cmp < target)
      {
        start = searching+1;
        return binsearch(target,data,start,end);
      }
      else if (cmp > target)
      {
        end = searching-1;
        return binsearch(target,data,start,end);
      }
    }
  }
  return -1;
  /*

  if( start != end)
  {

    
    cout << cmp << endl;
    if (cmp < target)
    {
      start = searching;
      binsearch(target,data,start,end);
    }
    if (cmp > target)
    {
      end = searching;
      binsearch(target,data,start,end);
    }
    if (cmp == target)
    {
      return searching;
    }
  }
  else
  {
    return -1;
  }
  */
}


// implements a selection sort algorithm to sort
//  the integer values in the 'data' array of size 'len'
// You aren't allowed to change the prototype of this function
void sort(int *data, int len)
{
  //int unsort = 0;
  for (int i = 0; i < len; i++)
  {
    int* swap = sortStep(data,len,i);//Pointer to number to be switched
    int greatVal = *(data+i);//Larger value (original)
    *(data+i) = *swap;
    *swap = greatVal;
  }
  

}

int* sortStep(int *data, int len, int unsort)
{
  int initial = *(data+unsort);//value of integer we're comparing
  int *initPtr = (data+unsort);//Address of integer we're comparing
  for (int j = unsort+1; j < len; j++)
  {
    int cmpVal = *(data+j);
    int* cmpPtr = (data+j);
    if (cmpVal < initial)
    {
      initial = cmpVal;
      initPtr = cmpPtr;

    }
  }
  return initPtr;

}
