#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main (int argc, char *argv[]) {

	
	omp_set_num_threads(4);
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		printf("ID : %d\n", ID);
	}


	return 0;
}
