/*
============================================================================
Name : ss28.c
Author : Dhruva Sharma
Descripton :Write a program to get maximum and minimum real time priority.

============================================================================
*/
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
