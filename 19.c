#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc () {
  unsigned long long dst;
  asm volatile("mrs %0, pmcr_e10" : "=r" (dst));
  dst |= (1<<0);
  asm volatile("msr pmcr_e10, %0" : : "r" (dst));
  asm volatile("mrs %0, pmccntr_e10" : "=r" (dst));
  return dst;
}


int main() {
  int time;
  unsigned long long int start, end;
  start = rdtsc();
  for(int i = 0; i<=10000; i++){
    getppid();
  }
  end = rdtsc();
  time = (end-start)/2.09;
  printf("The function takes %d nanp sec \n", time);
}

