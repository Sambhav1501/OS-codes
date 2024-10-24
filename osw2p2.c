#include <stdio.h> 
#include <unistd.h> 
int main() 
{
  printf("Executing ls command using execlp()\n"); 
  execlp("ls", "ls", NULL);
  printf("This line will not be executed if execlp is successful\n");
  return 0;
}
