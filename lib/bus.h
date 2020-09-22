#ifndef BUS_H
#define BUS_H

#include <pthread.h>

struct bus_event {
  int type_event;
};

typedef void (*bus_callback_function)(struct bus_event * event);

int
bus_register(bus_callback_function fn);

int
bus_add(struct bus_event event);

#endif
