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
  debug("Callback a got an event of type %d.\n", event->type_event);
}


void
callback_b(struct bus_event  * event)
{
  debug("Callback b got an event of type %d.\n", event->type_event);
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

  bus_init();

  bus_register(callback_a);
  bus_register(callback_b);

  bus_add(&(struct bus_event){.type_event=1});
  bus_add(&(struct bus_event){.type_event=2});

  notify_on_change(".");
}
