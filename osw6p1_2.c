//communication through message passing
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>  // Include this for fork()
#include <sys/wait.h>  // For wait()

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    pid_t pid;

    struct msg_buffer message;

    // Generate a unique key
    key = ftok("progfile", 65);

    // Create a message queue and return its ID
    msgid = msgget(key, 0666 | IPC_CREAT);

    pid = fork();  // Fork the process

    if (pid > 0) {  // Parent Process
        // Wait for the child process to finish writing
        wait(NULL);

        // Parent reads the message from the queue
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Parent reads: %s\n", message.msg_text);

        // Destroy the message queue
        msgctl(msgid, IPC_RMID, NULL);
    } else {  // Child Process
        // Prepare the message
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from Child!");

        // Send the message
        msgsnd(msgid, &message, sizeof(message), 0);
    }

    return 0;
}


