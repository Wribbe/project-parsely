#ifndef NOTIFY_H
#define NOTIFY_H

#include <stdlib.h>
#include <stdio.h>
#include "bus.h"

enum state_file_event {
  FILE_NEW,
  FILE_MOV,
  FILE_DEL
};

void
notify_on_change(const char * path);


#endif
