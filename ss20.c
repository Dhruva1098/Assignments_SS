/*
============================================================================
Name : ss20.c
Author : Dhruva Sharma
Descripton : Find out the priority of your running program. Modify the priority with nice command.

============================================================================
*/
/* 
ps -o pid,pri,nice,comm -p 4999
PID PRI NI COMM
4999  31  5 ./a.out

sudo renice -n -20 -p 4999
ps -o pid,pri,nice,comm -p 4999
PID PRI NI COMM
4999  31 -15 ./a.out
*/
int main(){
  for(;;);
}
