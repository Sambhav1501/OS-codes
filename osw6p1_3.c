//communication through shared memory
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/msg.h>
#include <unistd.h>  // For fork()
#include <sys/wait.h>  // For wait()

int main() {
    // Generate a unique key
    key_t key = ftok("shmfile", 65);

    // Get the shared memory ID
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach to shared memory
    char *str = (char *) shmat(shmid, (void *)0, 0);  // Corrected: char *str instead of char str

    pid_t pid;
    pid = fork();

    if (pid > 0) {  // Parent Process
        wait(NULL);  // Wait for the child process to finish
        printf("Parent reads: %s\n", str);  // Read the string from shared memory
        shmdt(str);  // Detach from shared memory
        shmctl(shmid, IPC_RMID, NULL);  // Destroy the shared memory
    } else {  // Child Process
        strcpy(str, "Hello from Child!");  // Write a string to shared memory
        shmdt(str);  // Detach from shared memory
    }

    return 0;
}
