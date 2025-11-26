#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;
    
    pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
        printf("Child is working for 3 seconds...\n");
        sleep(3);
        printf("Child process completed\n");
        exit(42);  // Exit with status 42
    }
    else {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());
        printf("Parent waiting for child (PID: %d)\n", pid);
        
        pid_t terminated_pid = wait(&status);
        
        printf("Child process %d terminated\n", terminated_pid);
        
        if (WIFEXITED(status)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
        if (WIFSIGNALED(status)) {
            printf("Child killed by signal: %d\n", WTERMSIG(status));
        }
    }
    
    return 0;
}
