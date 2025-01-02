#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  int ticks = 10;
  if (argc > 1) {
    ticks = atoi(argv[1]);
  }

  sleep(ticks);

  exit(0);
}

