#include <iostream>
#include "test.h"
#include "fasttime.h"

/*





*/
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

//////////////////////////////////////////////////////////////////////

/*


從組語層面來看，在原本的程式碼裡面會先檢查我們的 a, b, c 有沒有 partial overlap， 假如有的話
就執行簡單的 non-vectorized code ，假如沒有的話，就執行 vectorized code --> partially vectorized

Q: partial overlap 會有什麼問題嗎？ 

__restrict




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




//////////////////////////////////////////////////////////////////////


*/


//*

// 2-3 adding the __builtin_assume_aligned 

void test1(float* __restrict a, float* __restrict b, float* __restrict c, int N) {

  //std::cout << sizeof(float) << std::endl;

  __builtin_assume(N == 1024);

  //vmovups
  /*
  a = (float *)__builtin_assume_aligned(a, 16);
  b = (float *)__builtin_assume_aligned(b, 16);
  c = (float *)__builtin_assume_aligned(c, 16);
  */

  //vmovaps
  //*
  a = (float *)__builtin_assume_aligned(a, 32);
  b = (float *)__builtin_assume_aligned(b, 32);
  c = (float *)__builtin_assume_aligned(c, 32);
  //*/


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
