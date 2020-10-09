#include "PPintrin.h"

// 這邊的 pp 系列的操作，我猜是想要模擬每個 pp 系列的 function 都是在 one cycle 做完的 (雖然這邊還是用 for 迴圈來實做)

// implementation of absSerial(), but it is vectorized using PP intrinsics
void absVector(float *values, float *output, int N)
{
  __pp_vec_float x;
  __pp_vec_float result;
  __pp_vec_float zero = _pp_vset_float(0.f);
  __pp_mask maskAll, maskIsNegative, maskIsNotNegative;

  //  Note: Take a careful look at this loop indexing.  This example
  //  code is not guaranteed to work when (N % VECTOR_WIDTH) != 0.
  //  Why is that the case?
  for (int i = 0; i < N; i += VECTOR_WIDTH)
  {

    // All ones
    maskAll = _pp_init_ones();

    // All zeros
    maskIsNegative = _pp_init_ones(0);

    // Load vector of values from contiguous memory addresses
    _pp_vload_float(x, values + i, maskAll); // x = values[i];

    // maskAll --> vector 上的每個元素都會做動作
    // maskIsNegative --> 假如 x 上的某個元素大於 0 ，則將 maskIsNegative 相對應的 bit 設為 1
    //
    // Set mask according to predicate
    _pp_vlt_float(maskIsNegative, x, zero, maskAll); // if (x < 0) {

    // Execute instruction using mask ("if" clause)
    _pp_vsub_float(result, zero, x, maskIsNegative); //   output[i] = -x;

    // Inverse maskIsNegative to generate "else" mask
    maskIsNotNegative = _pp_mask_not(maskIsNegative); // } else {

    // Execute instruction ("else" clause)
    _pp_vload_float(result, values + i, maskIsNotNegative); //   output[i] = x; }

    // Write results back to memory
    _pp_vstore_float(output + i, result, maskAll);
  }
}

// 給我的感覺很像是在寫組語
// 把 mask 當作 if-else 以及 while 的 flag 來使用
//
void clampedExpVector(float *values, int *exponents, float *output, int N)
{
  //
  // PP STUDENTS TODO: Implement your vectorized version of
  // clampedExpSerial() here.
  //
  // Your solution should work for any value of
  // N and VECTOR_WIDTH, not just when VECTOR_WIDTH divides N
  //


  // out of loop, (const)
  __pp_vec_int   allIntOne;
  __pp_vec_int   intZero = _pp_vset_int(0);
  __pp_mask maskAll;
  __pp_vec_float threashold = _pp_vset_float(9.999999f); 
  __pp_vec_float floatZero = _pp_vset_float(0.f);
  __pp_vec_float floatOne  = _pp_vset_float(1.f);



  // normal variable
  __pp_vec_float x;
  __pp_vec_int   y;
  __pp_vec_int   vecCount;

  __pp_mask maskIsNegative, maskIsNotNegative;
  __pp_mask maskIsZero, maskIsNotZero, maskCountMoreThanZero, maskForMultiply;
  __pp_mask maskBiggerThanThreashold;

  __pp_vec_float result;



  allIntOne  = _pp_vset_int(1);
  maskAll = _pp_init_ones(); 

  // 就我的感覺來說， SIMD 的寫法跟一般的 serial 寫法很像，只是 SIMD 在每一輪迴圈可以在 single cycle 
  //   處理複數個資料
  for (int i = 0; i < N; i += VECTOR_WIDTH)
  {

    // 為了處理 N % VECTOR_WIDTH 的情況
    if(i + VECTOR_WIDTH < N) {
      maskAll = _pp_init_ones(); 
    } else {
      int tooMuch = i + VECTOR_WIDTH - N;
      maskAll = _pp_init_ones(VECTOR_WIDTH - tooMuch); 
    }

    // initialize some masks
    maskIsZero = _pp_init_ones(0);
    maskIsNotZero = _pp_init_ones(0);
    maskBiggerThanThreashold = _pp_init_ones(0);
    maskForMultiply = _pp_init_ones(0);

    _pp_vload_float(x, values + i, maskAll);  // x = values[i];
    _pp_vload_int(y, exponents+i, maskAll);   // y = exponents[i];

    result = _pp_vset_float(1.f);

    // 應該可以把 mask 通通收集(and)起來再一次做完 ?
    //   G : 好像也是沒差欸
    _pp_veq_int(maskIsZero, intZero, y, maskAll);  // if(y == 0) { 
    //_pp_vstore_float(output + i, result, maskIsZero);  

    //}
    maskIsNotZero = _pp_mask_not(maskIsZero);      // else {

    // 為了處理 N % VECTOR_WIDTH != 0 && N < VECTOR_WIDTH 的情況
    maskIsNotZero = _pp_mask_and(maskIsNotZero, maskAll); 

    _pp_vmove_int(vecCount, y, maskAll);

    _pp_vgt_int(maskForMultiply, vecCount, intZero, maskIsNotZero);   

    while(_pp_cntbits(maskForMultiply) > 0) {
      
      _pp_vmult_float(result, result, x, maskForMultiply);

      _pp_vsub_int(vecCount, vecCount, allIntOne, maskAll);
      _pp_vgt_int(maskForMultiply, vecCount, intZero, maskIsNotZero);

      //printf("hihi\n");

    }

    _pp_vgt_float(maskBiggerThanThreashold, result, threashold, maskAll);
    _pp_vmove_float(result, threashold, maskBiggerThanThreashold);
    _pp_vstore_float(output+i, result, maskAll);

    //}

  }

}

// returns the sum of all elements in values
// You can assume N is a multiple of VECTOR_WIDTH
// You can assume VECTOR_WIDTH is a power of 2
float arraySumVector(float *values, int N)
{

  //
  // PP STUDENTS TODO: Implement your vectorized version of arraySumSerial here
  //

  for (int i = 0; i < N; i += VECTOR_WIDTH)
  {
  }

  return 0.0;
}
