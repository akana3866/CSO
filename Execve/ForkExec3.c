#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h> 


int main(int argc, char **argv)
{
  // populate arraay with random numbers
  int child_status;
  pid_t pid;
  int i;
   char *array[3];
   array[0]="Process";
   array[1] ="Timer";
   array[2]="Start";
   pid = fork();
   if (pid == 0) {
    pid= execve("Process3", array, NULL);
     }
   int num;   
    
   return(0);
   }

  
