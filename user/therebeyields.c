#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

void yielder()
{
  // these procs will always yield,
  // which should hog the CPU and starve everything else
  printf("\tI am the yielder: %d\n", getpid());
  while(1)
  {
    printf("\t\tYielding again!\n");
    sleep(1);
  }
}

void full_burst()
{
  // these procs will always time out
  // making their bursts larger and larger
  printf("\tI am the burster: %d\n", getpid());
  while(1);
}

int main()
{
  int pid, i;
  int N = 64;
  for (i=0; i<N; i++)
  {
    pid = fork();
    if (pid == 0)
      full_burst();
    yielder();
  }
  return 0;
}
