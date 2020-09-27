#include "obj_parser.h"
#include "utils.h"

char *
file_read(const char * path)
{
  FILE * fh = fopen(path, "r");
  if(fh == NULL) {
    error("Could not open file: %s", path);
  }
  return NULL;
}


struct result_parsed
parse(const char * filepath)
{
  char * data = file_read(filepath);
  return (struct result_parsed){0};
}
