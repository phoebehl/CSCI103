#include <iostream>
#include <cmath>

using namespace std;
int main(){

  int angle;
  int check;
  double rad;
  const double pi = 3.1415926;

  cout << "Enter an angle between 15 and 75: ";
  cin >> angle;
  rad = angle*(pi/180.0);

  for ( int i=1; i <= 30; i++ ){
    check = i*tan(rad);
      if ( check >= 20 && check <= 30 ){
        	cout << "********************";
      }
      else {
            for ( int j=1; j <= i*tan(rad); j++ ){
             cout << "*";
        	}	
            }
      cout << endl;
    }
  return 0;
}
