/*
===========================================================================================
Name : ss29.c
Author : Dhruva Sharma
Description :Write a program to remove the message queue 
Output: 
[parallels@fedora-linux-38 handsOn2]$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x612c0a8c 1          parallels  660        0            0           

[parallels@fedora-linux-38 handsOn2]$ ./a.out
Message queue removed
[parallels@fedora-linux-38 handsOn2]$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages  

============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
int main(){
	key_t key = ftok(".", 'a');
	if(key < 0) perror("ftok");
	int msgid = msgget(key, 0666);
	msgctl(msgid, IPC_RMID, NULL);
	printf("Message queue removed\n");
}


