#include <iostream>
#include "test.h"
#include "fasttime.h"

/*

void test1(float* a, float* b, float* c, int N) {
  __builtin_assume(N == 1024);

  fasttime_t time1 = gettime();
  for (int i=0; i<I; i++) {
    for (int j=0; j<N; j++) {
      c[j] = a[j] + b[j];
    }
  }
  fasttime_t time2 = gettime();

  double elapsedf = tdiff(time1, time2);
  std::cout << "Elapsed execution time of the loop in test1():\n" 
    << elapsedf << "sec (N: " << N << ", I: " << I << ")\n";
}

*/

/*

// 2-2 addint the __restrict qualifier

void test1(float* __restrict a, float* __restrict b, float* __restrict c, int N) {
  __builtin_assume(N == 1024);


  fasttime_t time1 = gettime();
  for (int i=0; i<I; i++) {
    for (int j=0; j<N; j++) {
      c[j] = a[j] + b[j];
    }
  }
  fasttime_t time2 = gettime();

  double elapsedf = tdiff(time1, time2);
  std::cout << "Elapsed execution time of the loop in test1():\n" 
    << elapsedf << "sec (N: " << N << ", I: " << I << ")\n";

}



*/


//*

// 2-3 adding the __builtin_assume_aligned 

void test1(float* __restrict a, float* __restrict b, float* __restrict c, int N) {
  __builtin_assume(N == 1024);
  a = (float *)__builtin_assume_aligned(a, 16);
  b = (float *)__builtin_assume_aligned(b, 16);
  c = (float *)__builtin_assume_aligned(c, 16);
  
  fasttime_t time1 = gettime();
  for (int i=0; i<I; i++) {
    for (int j=0; j<N; j++) {
      c[j] = a[j] + b[j];
    }
  }
  fasttime_t time2 = gettime();

  double elapsedf = tdiff(time1, time2);
  std::cout << "Elapsed execution time of the loop in test1():\n" 
    << elapsedf << "sec (N: " << N << ", I: " << I << ")\n";

}

//*/
