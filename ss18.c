/*
./a.out
Max priority : 47
Min priority : 15
*/
#include <stdio.h>
#include <sched.h>

int main(){
  int max,min;
  max = sched_get_priority_max(SCHED_FIFO);
  min = sched_get_priority_min(SCHED_FIFO);
  printf("Max priority : %d \nMin priority : %d", max,min);
}
