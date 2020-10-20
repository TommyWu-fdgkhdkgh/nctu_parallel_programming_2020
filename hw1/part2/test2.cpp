#include <iostream>
#include "test.h"
#include "fasttime.h"

void test2(float *__restrict a, float *__restrict b, float *__restrict c, int N)
{
  __builtin_assume(N == 1024);
  a = (float *)__builtin_assume_aligned(a, 16);
  b = (float *)__builtin_assume_aligned(b, 16);

  float g = 10;

  fasttime_t time1 = gettime();
  for (int i = 0; i < I; i++)
  {
    //pragma 沒用
    #pragma loop distribute(enable)
    for (int j = 0; j < N; j++)
    //for (int j = 1; j < N-1; j++)
    {
      /* max() */
      // old
      // 會是怕 c[j] 跟 b[j] 是在同一個位置，而改變了 b[j] > a[j] 的判斷結果嗎?
      // 而新的寫法是完整的判斷完才給值，就不會有這種不確定性的問題
      //
      // 測試： 去掉 if 後也能 movaps
      
      //c[j] = a[j];
      //*
      //if (b[j] > a[j])
      //  c[j] = b[j];
      //*/

      // 優化失敗
      /*c[j] = b[j];
      if (b[j] <= a[j]) {
        c[j] = a[j];
      }*/

      // 優化成功： for (int j = 1; j < N-1; j++)
      //c[j-1] = a[i] + b[i];
      //a[i+1] = c[j-1];

      // new
      //g += 10;
      //c[j] = a[j]; // 優化失敗
      //c[j] = b[j]; // 優化成功
      /*
      if(b[j] > a[j]) c[j] = b[j];
      else c[j] = a[j];
      */
      
    }
  }

  fasttime_t time2 = gettime();

  double elapsedf = tdiff(time1, time2);
  std::cout << "Elapsed execution time of the loop in test2():\n"
            << elapsedf << "sec (N: " << N << ", I: " << I << ")\n";
}
