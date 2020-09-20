#include "notify.h"

#include <sys/inotify.h>
#include <unistd.h>
#include <linux/limits.h>

void
notify_on_change(const char * path)
{
  char path_resolved[PATH_MAX] = {0};
  char * path_full = realpath(path, path_resolved);
  printf("Will notify if anything happens in [%s].\n", path_resolved);

  int file_descriptior = inotify_init();
  int watch_descripton = inotify_add_watch(
    file_descriptior,
    path,
    IN_ALL_EVENTS
  );

  size_t size_buff = 4096;
  char buff[size_buff];
  const struct inotify_event * event = NULL;

  ssize_t len = read(file_descriptior, buff, size_buff);
  printf("len: %zd\n", len);

  printf("End of notify_on_change.\n");
}
