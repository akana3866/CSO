#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include<signal.h> 
int secs=0;
 void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n", sig); 
    secs = 0;
} 
int main(int argc, char **argv)
{
sleep(1);
signal(SIGINT, handle_sigint);
     int i;
    if( argc >   0 )
    {
        printf("The arguments supplied are:\n");
        for(i = 0; i < argc; i++)
        {
            printf("%s\t", argv[i]);
        }
    }
    else
    {
        printf("argument list is empty.\n");
    }
    
  int  j ;
 printf("\n");
  while(secs<20) {
     printf("Time:%i\n",secs);
     fflush(0);
     sleep(1);
     secs++;
      printf("\r\b\r");
  }

  return 0;
}
 
