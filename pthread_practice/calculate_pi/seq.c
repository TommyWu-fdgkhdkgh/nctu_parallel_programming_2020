#include <stdio.h>
#include <stdlib.h>

//https://zh.wikipedia.org/wiki/%CE%A0%E7%9A%84%E8%8E%B1%E5%B8%83%E5%B0%BC%E8%8C%A8%E5%85%AC%E5%BC%8F


int main(int argc, char *argv[]) {

  
  int n = 10000000;
  int fraction = 1;
  int denominator = 1;
  
  float result = 0.0f;

  for(int i = 0;i < n;i++) {
    result += (float) fraction / denominator; 

    fraction *= -1;
    denominator += 2;
  }

  result *= 4;

  printf("result : %f\n", result);

  return 0;
}
