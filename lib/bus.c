#include "bus.h"
#include "utils.h"
#include <unistd.h> // TODO: TODO_CROSSPLAT

#define MAX_CONSUMERS 256
#define MAX_EVENTS 512

function_callback_bus CONSUMERS[MAX_CONSUMERS] = {0};
function_callback_bus * consumers_end = CONSUMERS;

struct bus_event EVENTS[MAX_EVENTS] = {0};
struct bus_event * events_end = EVENTS;

pthread_t thread_watcher = 0;
pthread_cond_t condition_event_added = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex_events = PTHREAD_MUTEX_INITIALIZER;

void *
target_watch_event(void * args);

void
bus_copy_event_to(struct bus_event * from, struct bus_event * to);


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
  *consumers_end++ = fn;
  debug("%s\n", "Registered consumer callback function.");
  return -1;
}


int
bus_unregister(function_callback_bus fn)
{
  size_t i = 0;
  for (function_callback_bus * p = CONSUMERS; p<consumers_end; p++,i++) {
    if (*p == fn) {
      CONSUMERS[i] = *consumers_end--;
    }
  }
  debug("%s\n", "Function was unregistered.");
  return -1;
}


int
bus_add(struct bus_event * event)
{
  debug("%s\n", "Waiting to get event queue mutex.");
  pthread_mutex_lock(&mutex_events);
  bus_copy_event_to(event, events_end++);
  debug("%s\n", "Event was added to queue.");

  pthread_cond_broadcast(&condition_event_added);
  debug("%s\n", "Addition has been broadcast.");
  pthread_mutex_unlock(&mutex_events);
  return -1;
}



// Private functions.
// ==================

void
bus_copy_event_to(struct bus_event * from, struct bus_event * to)
{
  to->type_event = from->type_event;
}


void *
target_watch_event(void * args)
{
  for(;;) {
    pthread_mutex_lock(&mutex_events);
    while (EVENTS == events_end) {
      debug("%s\n", "No events in queue, sleeping.");
      pthread_cond_wait(&condition_event_added, &mutex_events);
    }
    debug("There are %ld new events!\n", events_end-EVENTS);
    for (struct bus_event * e = EVENTS; e < events_end; e++) {
      for (function_callback_bus * c = CONSUMERS; c < consumers_end; c++) {
        (*c)(e);
      }
    }
    events_end = EVENTS;
    pthread_mutex_unlock(&mutex_events);
  }
  return NULL;
}
