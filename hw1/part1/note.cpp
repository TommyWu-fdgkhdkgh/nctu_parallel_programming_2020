// Return a mask initialized to 1 in the first N lanes and 0 in the others
__pp_mask _pp_init_ones(int first = VECTOR_WIDTH);

_pp_init_ones 的預設值是 VECTOR_WIDTH

__pp_mask ==> __pp_vec<bool>

