#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>

int main()
{
  DIR *dir;
  struct dirent *entry;
  dir=opendir(".");
  if(dir==NULL)
  {
    perror("unable to open directory");
    exit(1);
  }
  printf("Content of directory:\n");
  while((entry = readdir(dir)) != NULL)
  {
    printf("%s\n",entry->d_name);
  }
  closedir(dir);
  return 0;
}
