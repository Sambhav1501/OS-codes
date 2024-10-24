#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>

int main() 
{
  
  pid_t pid = fork();
  if(pid < 0) 
  {
    printf("Fork Failed\n"); 
    return 1;
  }
  else if (pid == 0) 
  {
    printf("Child Process:\n"); 
    printf("PID: %d\n", getpid()); 
    printf("Parent PID: %d\n", getppid());
  }
  else 
  {
    printf("Parent Process:\n");   
    printf("PID: %d\n", getpid()); 
    printf("Child PID: %d\n", pid);
  }
  return 0;
}
