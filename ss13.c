/*
 * 13/ Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not(check in man 2 select)
 */
#include <sys/select.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

int main(void) {
	fd_set rfds;
	struct timeval time_val;
	int ret_val = 0;
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);
	time_val.tv_sec = 10;
	time_val.tv_usec = 0;
	ret_val = select(1, &rfds, NULL, NULL, &time_val);
	if(ret_val) {
		printf("Data is available within 10 seconds");
	}
	else {
		printf("Data is not available within 10 seconds");
	}
}
