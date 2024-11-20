#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int pid = fork();
  
  if (pid > 0) {
    printf("parent: child=%d\n", pid);
    pid = wait((int *)0);
    printf("child %d is done\n", pid);
  } else if (pid == 0) {
    sleep(1);
    printf("child: exiting\n");
  } else {
    printf("fork error\n");
    exit(1);
  }
  
  exit(0);
}

