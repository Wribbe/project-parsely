#include "obj_parser.h"

#define ERR(str, ...) \
  fprintf(stderr, "[!] Error: "str", aborting.\n", __VA_ARGS__);\
  exit(EXIT_FAILURE);

char *
file_read(const char * path)
{
  FILE * fh = fopen(path, "r");
  if(fh == NULL) {
    ERR("Could not open file: %s", path);
  }
  return NULL;
}


struct result_parsed
parse(const char * filepath)
{
  char * data = file_read(filepath);
  return (struct result_parsed){0};
}
