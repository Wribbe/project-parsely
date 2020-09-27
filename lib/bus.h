#ifndef BUS_H
#define BUS_H


#include <pthread.h>
#include <stdio.h>
#include <stdint.h>


typedef uint16_t TYPE_EVENT_ENUM;
extern TYPE_EVENT_ENUM EVENT_FILE;
extern TYPE_EVENT_ENUM EVENT_KEY;
extern TYPE_EVENT_ENUM EVENT_ALL;


struct bus_event {
  TYPE_EVENT_ENUM bitflag_event_type;
};


typedef void (*function_callback_bus)(struct bus_event * event);


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


char *
str_event_type(struct bus_event * event);


#endif
