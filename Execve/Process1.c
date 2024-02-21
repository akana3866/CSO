#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include<signal.h>
 int main(int argc, char **argv)
{
 int secs = 0;
 printf("\n");
  while(secs<5) {
     printf("Time:%i\n",secs);
     fflush(0);
     sleep(1);
     secs++;
      printf("\r\b\r");
  }
 
  return 0;
}
 
