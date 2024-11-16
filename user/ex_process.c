#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int pid;
  pid = fork();

  if (pid > 0) {
    const char *filename = "child_out.out";
    int fd = open(filename, O_CREATE | O_WRONLY);
    if (fd < 0) {
      printf("parent: failed to open file - %s\n", filename);
      exit(1);
    }

    // redirect stdout to the file
    const char *msg = "parent: child = %d\n";

    pid = wait((int *)0);
    printf("child %d is done\n", pid);
    // write to stdout
    printf(msg, pid);
    // write to file
    fprintf(fd, msg, pid);

    // close the file
    close(fd);
  } else if (pid == 0) {
    printf("child: exiting\n");
    exit(0);
  } else {
    printf("fork error\n");
  }
  
  exit(0);
}

