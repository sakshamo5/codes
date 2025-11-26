#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *file = "/usr/bin/echo";
    char *const args[] = {"/usr/bin/echo", "Hello from execv!", NULL};
    
    printf("Before execv call\n");
    printf("Current PID: %d\n", getpid());
    
    // Execute the command
    execv(file, args);
    
    // This will only execute if execv fails
    perror("execv failed");
    return 1;
}
