#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h> 


int main(int argc, char **argv)
{
  int child_status;
  pid_t pid;
   
    pid = fork();
    if (pid==0) {
     execve("Process1",NULL, NULL);
     exit(0);
     }
    wait(&child_status);
    printf("Done\n");
   return(0);
   }

  
