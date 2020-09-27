#ifndef UTILS_H
#define UTILS_H

#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#define UNUSED(x) (void)x

void
vprintf_stamped(const char * prefix, const char * fmt, ...);

#define debug(fmt, ...) vprintf_stamped("D", fmt, __VA_ARGS__)
#define error(fmt, ...) vprintf_stamped("!", fmt, __VA_ARGS__)

#endif
