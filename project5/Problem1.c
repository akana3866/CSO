#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

#define NUM 100000
#define ITERATIONS 50000

double elapsedTime(struct timeval begin, struct timeval end) {
  return (end.tv_sec - begin.tv_sec) * 1000.0 + 
         (end.tv_usec - begin.tv_usec) / 1000.0;
}

void writeOddNumbers(int start, int end, char *filename) {
  FILE *f = fopen(filename, "w"); 
  for(int i=start; i<=end; i+=2) {
    fprintf(f, "%d\n", i); 
  }
  fclose(f);
}

int main() {

  struct timeval begin, end;

  // Single process
  gettimeofday(&begin, NULL);
  for(int i=0; i<ITERATIONS; i++) {
    writeOddNumbers(1, NUM, "output.txt"); 
  }
  gettimeofday(&end, NULL);

  printf("Single process took %.3f ms\n", elapsedTime(begin, end));

  // Multiple processes
  gettimeofday(&begin, NULL); 
  
  int range = NUM/10;
  for(int i=0; i<10; i++) {
    if(fork() == 0) {
      char filename[20];
      sprintf(filename, "out%d.txt", i);  
      writeOddNumbers(i*range+1, (i+1)*range, filename);
      return 0;
    }
  }
  
  while(wait(NULL) > 0);
  
  // Merge files
  // Code to merge files

  gettimeofday(&end, NULL);

  printf("Multiple processes took %.3f ms\n", elapsedTime(begin, end));

  return 0;
}