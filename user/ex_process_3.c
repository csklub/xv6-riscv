#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  // int pid = fork();
  int pid, status;

  if ((pid = fork()) == 0) {
    // child executing here
    printf("child: exiting\n");
    exit(1);
  } else if (pid > 0) {
    // parent executing here
    // parent waits for the child to be
    // done before printing
    pid = wait(&status); 
    printf("parent: child=%d\n", pid);
    printf("parent: child %d exited with %d\n", pid, status);
  } else {
    // parent executing here too
    // if there's an error.
    printf("parent: fork error\n");
    exit(1);
  }
  
  exit(0);
}

