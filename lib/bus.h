#ifndef BUS_H
#define BUS_H

#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

struct bus_event {
  int type_event;
};

typedef void (*function_callback_bus)(struct bus_event * event);

typedef uint16_t TYPE_EVENT_ENUM;
extern TYPE_EVENT_ENUM EVENT_FILE;
extern TYPE_EVENT_ENUM EVENT_KEY;

int
bus_init(void);

int
bus_register(function_callback_bus fn, TYPE_EVENT_ENUM bitflag_events);

int
bus_unregister(function_callback_bus fn);

int
bus_add(struct bus_event * event);

int
bus_destroy(void);

#endif
