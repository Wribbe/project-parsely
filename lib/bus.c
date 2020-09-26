#include "bus.h"
// TODO: Make cross-platform.
#include <unistd.h>

#define MAX_CONSUMERS 256
#define MAX_EVENTS 512

function_callback_bus CONSUMERS[MAX_CONSUMERS] = {0};
function_callback_bus * function_last = CONSUMERS;

struct bus_event EVENTS[MAX_EVENTS] = {0};
struct bus_event * event_last = EVENTS;

pthread_t thread_watcher = 0;
pthread_cond_t condition_event_added = PTHREAD_COND_INITIALIZER;

void *
target_watch_event(void * args);


// Public functions.
// =================

int
bus_init(void)
{
  thread_watcher = pthread_create(
    &thread_watcher,
    NULL,
    target_watch_event,
    NULL
  );
  printf("Bus has been finalized.\n");
  return -1;
}


int
bus_destroy(void)
{
  return -1;
}


int
bus_register(function_callback_bus fn)
{
  return -1;
}


int
bus_add(struct bus_event event)
{
  return -1;
}


int
bus_unregister(function_callback_bus fn)
{
  return -1;
}


// Private functions.
// ==================


int
bus_event_remove(size_t index)
{
  return -1;
}


void *
target_watch_event(void * args)
{
  // TODO: Make cross-platform.
  for (;;) {
    printf("HELLO FROM EVENT WATCHER\n");
    sleep(1);
  }
  return NULL;
}
