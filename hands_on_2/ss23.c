/*
===========================================================================================
Name : ss20w.c
Author : Dhruva Sharma
Description : write a program to print the maximum number of files can be opened within a 
process and size of a pipe (circular buffer)
Output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out
MAximum number of files that can be opened within a process is: 1024
Size of a pipe (circular buffer) is:16

============================================================================================
*/
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
int main(){
	long mfiles = sysconf(_SC_OPEN_MAX);
	if(mfiles < 0) perror ("sysconf");
	long psize = sysconf(_PC_PIPE_BUF);
	if(psize < 0) perror("sysconf");
	printf("MAximum number of files that can be opened within a process is: %d\nSize of a pipe (circular buffer) is:%d\n", mfiles, psize);
}
