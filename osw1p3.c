#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h>

int main() 
{
  pid_t pid1, pid2; 
  pid1 = fork();
  if (pid1 < 0) 
  {
    fprintf(stderr, "Fork Failed\n"); 
    return 1;
  } 
  else if (pid1 == 0) 
  { 
    execlp("/bin/ls", "ls", NULL); 
    exit(0);
  } 
  else 
  {
    wait(NULL); 
    pid2 = fork();
    if (pid2 < 0) 
    {
      fprintf(stderr, "Fork Failed\n"); 
      return 1;
    } 
    else if (pid2 == 0) 
    { 
      sleep(5);
      printf("Second child, PID: %d, Parent PID: %d\n", getpid(), getppid()); 
      exit(0);
    } 
    else 
    {
        printf("Parent process is terminating\n"); 
        exit(0);
    }
  }
  return 0;
}

