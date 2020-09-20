
#include <stdint.h>

#include <windows.h>
#include <tchar.h>
#include <fileapi.h>

#include "notify.h"

void
notify_on_change(const char * path)
{
  size_t size_buff = 2094;
  char path_resolved[size_buff];
  GetFullPathNameA(
    path,
    size_buff,
    path_resolved,
    NULL
  );

  printf("Will notify if anything happens in %s.\n", path_resolved);

  void * handle_changes = FindFirstChangeNotification(
    path,
    FALSE,
    FILE_NOTIFY_CHANGE_FILE_NAME
  );
}
