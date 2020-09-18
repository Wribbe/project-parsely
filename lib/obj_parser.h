#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H

#include <stdlib.h>
#include <stdio.h>


struct result_parsed {
  size_t size_data;
  char * data;
};


struct result_parsed
parse(const char * filepath);


#endif
