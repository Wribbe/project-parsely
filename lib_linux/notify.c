#include "notify.h"
#include "utils.h"

#include <sys/inotify.h>
#include <unistd.h>
#include <linux/limits.h>

void
notify_on_change(const char * path)
{
  char path_resolved[PATH_MAX] = {0};
  realpath(path, path_resolved);
  debug("Will notify if anything happens in %s.\n", path_resolved);

  int file_descriptior = inotify_init();
  int watch_descriptor = inotify_add_watch(
    file_descriptior,
    path,
    IN_CREATE | IN_MOVE | IN_DELETE
  );
  UNUSED(watch_descriptor);

  size_t size_buff = 4096;
  char buff[size_buff];
  const struct inotify_event * event = NULL;

  for(;;) {
    ssize_t len = read(file_descriptior, buff, size_buff);
    char * p = buff;
    for (; p < buff+len; p += sizeof(struct inotify_event)+event->len) {
      event = (const struct inotify_event *) p;
      if (event->name) {
        debug("%s\n", event->name);
      }
    }
  }

  debug("%s\n", "End of notify_on_change.");
}
