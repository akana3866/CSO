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
    execve("Process1",NULL, NULL);
      
    
    printf("Done\n");
   return(0);
   }

  
