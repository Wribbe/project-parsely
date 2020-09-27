#include "utils.h"

pthread_mutex_t mutex_print = PTHREAD_MUTEX_INITIALIZER;

#define SIZE_BUFFER_STAMP 64
char buffer_stamp[SIZE_BUFFER_STAMP] = {0};

void
printf_stamped(const char * prefix, const char * fmt, ...)
{
  time_t time_date = time(NULL);
  struct timespec time_nsec = {0}; // TODO: TODO_CROSSPLAT
  clock_gettime(CLOCK_REALTIME, &time_nsec);

  pthread_mutex_lock(&mutex_print);

  size_t size_written_stamp = strftime(
    buffer_stamp,
    SIZE_BUFFER_STAMP,
    "%Y-%d-%m %H:%M:%S",
    localtime(&time_date)
  );

  size_t remaining = SIZE_BUFFER_STAMP-size_written_stamp;
  if (size_written_stamp && remaining) {
    snprintf(
      &buffer_stamp[size_written_stamp],
      remaining,
      ".%09li",
      time_nsec.tv_nsec
    );
  }

  printf("[%s][%s]: ", prefix, buffer_stamp);

  va_list vas;
  va_start(vas, fmt);
  vprintf(fmt, vas);
  va_end(vas);

  pthread_mutex_unlock(&mutex_print);
}
