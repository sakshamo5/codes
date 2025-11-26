#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    
    printf("Before fork - Process ID: %d\n", getpid());
    
    // Create child process
    pid = fork();
    
    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child process created\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else {
        // Parent process
        printf("Parent process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }
    
    return 0;
}
