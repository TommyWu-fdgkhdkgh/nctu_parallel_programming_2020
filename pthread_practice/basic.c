#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// pthread create
// pthread join
//


void *hello(void *data) {
  printf("hello world!\n");
  return NULL;
}

int main (int argc, char *argv[]) {

  pthread_t *thread = (pthread_t *)malloc(sizeof(pthread_t));

  printf("before pthread_create()\n");
  int result = pthread_create(thread, NULL, &hello, NULL); 
  void **status;
  result = pthread_join(*thread, status);
  printf("after pthread_create()\n");




  return 0;
}
