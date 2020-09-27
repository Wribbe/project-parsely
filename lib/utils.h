#ifndef UTILS_H
#define UTILS_H

#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#define UNUSED(x) (void)x
#define DEBUG 1


void
printf_stamped(const char * prefix, const char * fmt, ...);


#if DEBUG == 1
  #define debug(fmt, ...) printf_stamped("D", fmt, __VA_ARGS__)
#else
  #define debug(fmt, ...) (void)0
#endif

#define error(fmt, ...) printf_stamped("!", fmt, __VA_ARGS__); \
  exit(EXIT_FAILURE)


#endif
