/*
sudo ./a.out
Password:
Current Priority = 0
New Priority: -10
*/
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>

int main() {
  int priority;
  priority = getpriority(PRIO_PROCESS, 0);
  printf("Current Priority = %d\n", priority);
  if(setpriority(PRIO_PROCESS, 0, -10) == -1){
    perror("setpriority");
  }
  priority = getpriority(PRIO_PROCESS, 0);
  printf("New Priority: %d\n", priority);
}
