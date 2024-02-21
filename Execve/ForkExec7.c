#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h> 

int  loop=1;
int cnt=0;
void handle_sigchild(int sig) 
{ 
     printf("Caught signal %d\n\n\n", sig); 
    loop = 0;
} 

int main(int argc, char **argv)
{
signal(SIGCHLD, handle_sigchild);

  int child_status;
  pid_t pid; 
  pid = fork();
   
   if (pid == 0) {
    pid= execve("Process7", NULL, NULL);
     }
   int num;
   while (loop==1) {
   printf("Parent waiting - loopcount:%i",cnt );
   fflush( stdout );
   usleep(100*1000);
   printf("\r\b ");
      cnt++;
   }
   return(0);
   }

  
