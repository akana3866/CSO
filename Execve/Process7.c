#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include<signal.h> 
int secs=0;
  
int main(int argc, char **argv)
{
 

  while(secs<10) {
  //   printf("Time:%i\n",secs);
     fflush(0);
     sleep(1);
     secs++;
      
  }

  return 0;
}
 
