#ifndef BUS_H
#define BUS_H

#include <pthread.h>
#include <stdio.h>

struct bus_event {
  int type_event;
};

typedef void (*function_callback_bus)(struct bus_event * event);

int
bus_init(void);

int
bus_register(function_callback_bus fn);

int
bus_unregister(function_callback_bus fn);

int
bus_add(struct bus_event event);

int
bus_destroy(void);

#endif
