/*
============================================================================
Name : ss15.c
Author : Dhruva Sharma
Description : Write a program to display the environmental variable of the user (use environ).

============================================================================
*/
#include <stdio.h>
extern char **environ;
int main(){
	int i = 0;
	while(environ[i]!= NULL){
		printf("%s\n", environ[i++]);
	}
}

