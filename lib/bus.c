#include "bus.h"
#include "utils.h"
#include <unistd.h> // TODO: TODO_CROSSPLAT

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
  debug("%s\n", "Bus has been initialized.");
  return -1;
}


int
bus_destroy(void)
{
  debug("%s\n", "The bus has been destroyed.");
  return -1;
}


int
bus_register(function_callback_bus fn)
{
  debug("%s\n", "Registered callback function.");
  return -1;
}


int
bus_add(struct bus_event event)
{
  debug("%s\n", "Event was added to queue.");
  return -1;
}


int
bus_unregister(function_callback_bus fn)
{
  debug("%s\n", "Function was unregistered.");
  return -1;
}


// Private functions.
// ==================


int
bus_event_remove(size_t index)
{
  debug("%s\n", "Event was removed from queue.");
  return -1;
}


void *
target_watch_event(void * args)
{
  for (;;) {
    debug("%s\n", "HELLO FROM EVENT WATCHER");
    sleep(1); // TODO: TODO_CROSSPLAT
  }
  return NULL;
}
