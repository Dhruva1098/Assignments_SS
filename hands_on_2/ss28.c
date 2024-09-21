/*
===========================================================================================
Name : ss28.c
Author : Dhruva Sharma
Description :Write a program to change the exiting message queue permission (use msqid_ds) 
Output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out
current permissions: 666
Updated permissions: 660

============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
int main(){
	struct msqid_ds msg_info;
	key_t key = ftok(".", 'a');
	if(key < 0) perror("ftok");

	int msgid = msgget(key, 0666|IPC_CREAT);
	int out = msgctl(msgid, IPC_STAT, &msg_info);
	if(out < 0) perror("msgctl");
	printf("current permissions: %o\n",msg_info.msg_perm.mode);
	msg_info.msg_perm.mode = 0660;
	msgctl(msgid, IPC_SET, &msg_info);
	msgctl(msgid, IPC_STAT, &msg_info);
	printf("Updated permissions: %o\n",msg_info.msg_perm.mode);
}
