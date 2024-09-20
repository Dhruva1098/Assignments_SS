/*
===========================================================================================
Name : ss27.c
Author : Dhruva Sharma
Description :Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag 
Output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out
Recieving msg with 0 as flag
recieved:message 1
recieving msg with IPC_NOWAIT as a flag:
recieved:message 1

============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <string.h>

struct m {
	long msg_type;
	char msg_data[100];
};
int main(){
	struct m msg;
	key_t key = ftok(".", 'a');
	if(key < 0) perror("ftok");
	int msgid = msgget(key, 0666);
	printf("Recieving msg with 0 as flag\n");
	msgrcv(msgid, &msg, sizeof(msg.msg_data), 0, 0);
	printf("recieved:%s\n", msg.msg_data);

	printf("recieving msg with IPC_NOWAIT as a flag:\n");
	msgrcv(msgid, &msg, sizeof(msg.msg_data), 0, IPC_NOWAIT);
	printf("recieved:%s\n", msg.msg_data);
}
