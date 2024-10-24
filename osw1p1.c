#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>

int main() 
{
  pid_t pid = fork();
  
  if (pid < 0) 
  {
    printf("Fork Failed\n"); 
    return 1;
  }
  else if (pid == 0) 
  {
    printf("This is the child process. PID: %d\n", getpid());
  }
  else 
  {
    printf("This is the parent process. Child PID: %d\n", pid); 
    printf("Parent PID: %d\n", getpid());
  }

return 0;
}
