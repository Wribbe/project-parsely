#ifndef UTILS_H
#define UTILS_H

#include <pthread.h>

extern pthread_mutex_t mutex_print;

#define debug(s, ...) pthread_mutex_lock(&mutex_print); \
  printf("[D]: "s, __VA_ARGS__); \
  pthread_mutex_unlock(&mutex_print)
#define UNUSED(x) (void)x

#endif
