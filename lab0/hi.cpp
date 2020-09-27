#include <iostream>
#include <cstdlib>
#include <cstdio>

#define NUMBER_OF_TOSSES 1000000000
using namespace std;

int main () {

  long long int number_in_circle = 0;	
  double x = 0;
  double y = 0;
  double distance = 0;
  double pi_estimate;

  srand(time(NULL)); 

  for(long long int toss = 0;toss < NUMBER_OF_TOSSES;toss++) {

    x = (double)rand() / (RAND_MAX + 1.0) * 2 - 1;
    y = (double)rand() / (RAND_MAX + 1.0) * 2 - 1;

    distance = x * x + y * y; 
    //cout << "distance : " << distance << endl;

    if(distance <= (double)1) {
      number_in_circle++;      
    }

    pi_estimate = 4 * number_in_circle/((double) toss);
    cout << "toss : " << toss << ", pi_estimate : " << pi_estimate << endl;
  } 

  pi_estimate = 4 * number_in_circle/((double) NUMBER_OF_TOSSES);
  cout << pi_estimate << endl;

  return 0;
}



