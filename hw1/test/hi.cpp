#include <cstdlib>
#include <cstdio>
#include <iostream>

#define VECTOR_WIDTH 10

template <typename T>
struct __pp_vec {
  T value[VECTOR_WIDTH];
};

#define __pp_vec_float __pp_vec<float>

int main (int argc, char *argv[]) {
  // using template + macro
  __pp_vec_float ppf;
  ppf.value[0] = 1.23;
  
  // using template
  __pp_vec<float> ppf2;
  ppf2.value[0] = 2.22;
  
  printf("%f\n", ppf2.value[0]);

  return 0;
}







