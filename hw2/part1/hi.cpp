//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <sched.h>
#include <pthread.h>
#include <sys/sysinfo.h>
#include <time.h>
#include "fasttime.h"

#define _GNU_SOURCE

#define NUMBER_OF_TOSSES 1000000000
using namespace std;

void usage(const char *program_name);
void *hello(void *data);

/*typedef struct DATA{
  int left;
  int len;
} dataToTheads;*/

int main (int argc, char *argv[]) {
  int total_cpu = get_nprocs_conf();
  int available_cpu = get_nprocs();

  int cpus = 1; // num of cpu
  long long int tosses = 1; // num of tosses

  int opt;
  static struct option long_options[] = {
    {"cpu", 1, 0, 'c'},
    {"toss", 1, 0, 't'},
    {"help", 0, 0, '?'},
    {0 ,0, 0, 0}
  };

  while ((opt = getopt_long(argc, argv, "c:t:?", long_options, NULL)) != EOF) {
    switch(opt) {
      case 'c' :
        cpus = atoi(optarg);
        if(cpus <= 0) {
          printf("num of cpus need to > 0\n");
	  exit(0);
        } else if(cpus > available_cpu){ 
          printf("the num of available cpu is : %d\n", available_cpu);
          exit(0);
	}
        break;
      case 't' :
        tosses = atoll(optarg);
	if(tosses <= 0) {
          printf("num of tosses need to > 0\n");
	  exit(0);
	}
        break;
      case '?' :
        usage(argv[0]); 
        break;
    }
  }

  printf("cpu : %d\n", cpus);
  printf("tosses : %lld\n", tosses);
  printf("CPU_available : %d\n", get_nprocs_conf());

  // set cpu affinity
  //cpu_set_t *cpu_mask = CPU_ALLOC(available_cpu + 1);
  cpu_set_t cpu_mask;
  //CPU_ZERO_S(CPU_ALLOC_SIZE(available_cpu), cpu_mask);
  CPU_ZERO(&cpu_mask);
  for(int i = 0;i < cpus;i++) {
    CPU_SET(i, &cpu_mask);
  } 
  printf("CPU_COUNT : %d\n", CPU_COUNT(&cpu_mask));
  
  sched_setaffinity(0, sizeof(cpu_mask), &cpu_mask);

  printf("CPU_available after sched_setaffinity : %d\n", get_nprocs_conf());

  pthread_t *thread = (pthread_t *)malloc(sizeof(pthread_t) * cpus);
  if(thread == NULL) {
    printf("malloc pthread error\n");
  } 

  
  fasttime_t time1 = gettime();
  // calculate child_tosses and root_tosses
  long long int child_tosses = tosses / cpus; 
  long long int root_tosses = tosses - child_tosses * (cpus - 1); 

  long long int *dataToThreads = (long long int *)malloc(sizeof(int));
  *dataToThreads = child_tosses;

  // thread create
  for(int i = 0;i < cpus - 1;i++) {
    int result = pthread_create(&thread[i], NULL, &hello, dataToThreads);
  }
  
  // tossing !
  long long int number_in_circle = 0;
  double x = 0;
  double y = 0;
  double distance = 0;
  double pi_estimate;
  
  //srand(1);
  time_t t = time(NULL);
  unsigned int ult = (unsigned int)t;

  printf("root tosses : %lld\n", root_tosses);

  for(long long int toss = 0;toss < root_tosses;toss++) {
    x = (double)rand_r(&ult) / (RAND_MAX + 1.0) * 2 - 1;
    y = (double)rand_r(&ult) / (RAND_MAX + 1.0) * 2 - 1;

    distance = x * x + y * y;

    if(distance <= (double)1) {
      number_in_circle++;
    }
  }

  printf("root number_in_circle : %lld\n", number_in_circle);

  // thread join
  void *retFromThread; // 來自 https://man7.org/linux/man-pages/man3/pthread_create.3.html
  for(int i = 0;i < cpus - 1;i++) {
    int result = pthread_join(thread[i], &retFromThread);
    printf("*retFromThread : %lld\n", (*(long long int *)(retFromThread)));
    number_in_circle += (*(long long int *)(retFromThread));
  }

  pi_estimate = 4 * number_in_circle/((double) tosses); 

  fasttime_t time2 = gettime();
  double elapsedf = tdiff(time1, time2);
  printf("pi : %lf\n", pi_estimate);
  printf("Elapsed execution time : %lf\n", elapsedf);

  return 0;
}

void usage(const char* program_name) {
  printf("program_name : %s\n", program_name);
  printf(" -c --cpu number of cpus you want to use\n");
  printf(" -t --toss number of tosses\n");  
  printf(" -h --help print the usage of the program\n");

  exit(0);
}

void *hello(void *data) {
  long long int child_tosses = *(long long int *)data;
  //free(data);

  printf("hello! chlid_tosses is : %lld\n", child_tosses);

  // tossing !
  long long int number_in_circle = 0;
  double x = 0;
  double y = 0;
  double distance = 0;
  double pi_estimate;

  time_t t = time(NULL);
  unsigned int ult = (unsigned int)t;
  ult += (unsigned int)pthread_self(); // 為了讓每個 thread 的 seed 不相同  

  //srand(1);
  for(long long int toss = 0;toss < child_tosses;toss++) {
    x = (double)rand_r(&ult) / (RAND_MAX + 1.0) * 2 - 1;
    y = (double)rand_r(&ult) / (RAND_MAX + 1.0) * 2 - 1;

    distance = x * x + y * y;

    if(distance <= (double)1) {
      number_in_circle++;
    }
  } 

  long long int *ret = (long long int *)malloc(sizeof(long long int));
  *ret = number_in_circle;

  return ret;
}
