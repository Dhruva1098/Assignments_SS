/*
===========================================================================================
Name : ss19.c
Author : Dhruva Sharma
Description :  Create FIFO file by
a. mknod
b. mkfifo
c. use strace command to find out which command (mknod or mkfifo) is better
d. mknod system call
e. mkfifo library function

Output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out 
FIFO created with mknod
FIFO created with mkfifo


============================================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(){
	int out = mknod("myfifo", S_IFIFO | 0666, 0);
	if(out < 0) perror("mknod");
	printf("FIFO created with mknod\n");

	int out2 = mkfifo("myfifo2", 0666);
	if(out2 < 0)  perror("mkfifo");
	printf("FIFO created with mkfifo\n");

}

