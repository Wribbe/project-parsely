#ifndef UTILS_H
#define UTILS_H

#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#define UNUSED(x) (void)x

void
printf_stamped(const char * prefix, const char * fmt, ...);

#define debug(fmt, ...) printf_stamped("D", fmt, __VA_ARGS__)
#define error(fmt, ...) printf_stamped("!", fmt, __VA_ARGS__)

#endif
