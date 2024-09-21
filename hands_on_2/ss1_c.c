/*
===========================================================================================
Name : ss34.c
Author : Dhruva Sharma
Description :  Write a separate program (for each time domain) to set a interval timer in
10sec and 10micro second
a. ITIMER_REAR
b. ITIMER_VIRTUAL
c. ITIMER_PROF

============================================================================================
*/
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler(int signal) {
    printf("ITIMER_PROF triggered\n");
}

int main() {
    struct itimerval t;
    signal(SIGPROF, handler);
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    setitimer(ITIMER_PROF, &t, NULL);
    while (1) {}
    return 0;
}

