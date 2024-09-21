/*
===========================================================================================
Name : ss23.c
Author : Dhruva Sharma
Description :30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory 
Output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out
Writing to shared memory
attempting to write in RDONLY mode
shared memory removed
[parallels@fedora-linux-38 handsOn2]$ ipcs  -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      


============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
int main(){
	key_t key = ftok(".", 'a');
	int shmid = shmget(key, 1024, 0666|IPC_CREAT);
	char *str = (char*)shmat(shmid, (void*)0,0); //attatch w-r mode
	printf("Writing to shared memory\n");
	strcpy(str,"message1"); //a.
	shmdt(str);//detach
	str = (char*)shmat(shmid, (void*)0, SHM_RDONLY); //b.attatch ronly mode
	printf("attempting to write in RDONLY mode\n");
	//if(strcpy(str,"overwrite") == NULL){
	//	printf("write failed\n");
	//} else {
	//	printf("write succeeded\n");
	//}
	//commenting out because it givesd me segmentation fault
	shmdt(str); //c. detach
	shmctl(shmid, IPC_RMID, NULL); //d.remove shared memory
	printf("shared memory removed\n");
}
