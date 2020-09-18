#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

#include "obj_parser.h"

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
}
