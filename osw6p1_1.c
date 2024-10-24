//communication through pipe
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main() {
    int fd[2];
    pid_t pid;
    char writeMsg[] = "Hello from Child!";
    char readMsg[50];

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {  // Parent Process
        close(fd[1]);  // Close writing end
        read(fd[0], readMsg, sizeof(readMsg));
        printf("Parent reads: %s\n", readMsg);
        close(fd[0]);
    } else {  // Child Process
        close(fd[0]);  // Close reading end
        write(fd[1], writeMsg, strlen(writeMsg) + 1);
        close(fd[1]);
    }

    return 0;
}

