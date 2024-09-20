/*
===========================================================================================
Name : ss26.c
Author : Dhruva Sharma
Description : Write a program to send messages to the message queue. check $ipcs -q
Output: 
[parallels@fedora-linux-38 handsOn2]$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x612c0a8c 1          parallels  666        100          1 

============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <string.h>

struct msg{
	long msg_type;
	char msg_data[100];
};

int main(){
	struct msg message;
	key_t key = ftok(".", 'a');
	if(key < 0) perror("ftok");

	int msgid = msgget(key, 0666 | IPC_CREAT);
	message.msg_type = 1;
	snprintf(message.msg_data, sizeof(message.msg_data), "message 1");
	msgsnd(msgid, &message, sizeof(message.msg_data), 0);
}

