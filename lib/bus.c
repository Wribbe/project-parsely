#include "bus.h"

#define MAX_CONSUMERS 256
#define MAX_EVENTS 512

function_callback_bus CONSUMERS[MAX_CONSUMERS] = {0};
function_callback_bus * function_last = CONSUMERS;


// Public functions.
// =================

int
bus_init(void)
{
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


// Private functions.
// ==================


int
bus_event_remove(size_t index)
{
  return -1;
}


int
bus_unregister(function_callback_bus fn)
{
  return -1;
}
