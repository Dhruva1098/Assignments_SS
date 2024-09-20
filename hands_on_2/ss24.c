/*
===========================================================================================
Name : ss24.c
Author : Dhruva Sharma
Description : write a program to create a message queue and print the key and message queue
id
Output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out
message queue key:1630276236
Message queue id:0

============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
	long msg_type;
	char msg_data[100];
};

int main(){
	key_t key = ftok(".", 'a');
	if(key<0) perror("ftok");
	int msgid = msgget(key, 0666 | IPC_CREAT);
	if (msgid<0) perror("msgget");

	printf("message queue key:%d\nMessage queue id:%d\n", key, msgid);
}
