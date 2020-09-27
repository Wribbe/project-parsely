#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

#include "obj_parser.h"
#include "notify.h"
#include "bus.h"
#include "utils.h"


void
callback_a(struct bus_event  * event)
{
  debug("Callback a got an event of type %s.\n", str_event_type(event));
}


void
callback_b(struct bus_event  * event)
{
  debug("Callback b got an event of type %s.\n", str_event_type(event));
}

void
callback_c(struct bus_event  * event)
{
  debug("Callback c got an event of type %s.\n", str_event_type(event));
}

void
callback_d(struct bus_event  * event)
{
  debug("Callback d got an event of type %s.\n", str_event_type(event));
}


int
main(void)
{
  DIR * d = opendir(".");
  struct dirent * dir = NULL;
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }

  struct result_parsed obj = parse("res/cube.obj");
  UNUSED(obj);

  bus_init();

  bus_register(callback_a, "callback_a", EVENT_FILE);
  bus_register(callback_b, "callback_b", EVENT_KEY);
  bus_register(callback_c, "callback_c", EVENT_KEY | EVENT_FILE);

  bus_add(&(struct bus_event){EVENT_FILE});
  bus_add(&(struct bus_event){EVENT_KEY});
  bus_add(&(struct bus_event){EVENT_ALL});

  bus_unregister(callback_b);

  bus_add(&(struct bus_event){EVENT_FILE});
  bus_add(&(struct bus_event){EVENT_KEY});
  bus_add(&(struct bus_event){EVENT_ALL});

  bus_register(callback_d, "callback_d", EVENT_KEY);

  bus_add(&(struct bus_event){EVENT_FILE});
  bus_add(&(struct bus_event){EVENT_KEY});
  bus_add(&(struct bus_event){EVENT_FILE});
  bus_add(&(struct bus_event){EVENT_FILE});
  bus_add(&(struct bus_event){EVENT_KEY});
  bus_add(&(struct bus_event){EVENT_ALL});
  bus_add(&(struct bus_event){EVENT_FILE});

  notify_on_change(".");
}
