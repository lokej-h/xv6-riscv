#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int main() 
{
  fork();
  while(1);
  return 0;
}
