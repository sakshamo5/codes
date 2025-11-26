#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Before execlp call\n");
    printf("Current PID: %d\n", getpid());
    
    // Execute 'ls -l' command using execlp
    execlp("ls", "ls", "-l", NULL);
    
    // This will only execute if execlp fails
    perror("execlp failed");
    return 1;
}
