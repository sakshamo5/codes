#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    time_t start, end;
    
    printf("Program start\n");
    time(&start);
    
    printf("Sleeping for 5 seconds...\n");
    unsigned int remaining = sleep(5);
    
    time(&end);
    
    if (remaining > 0) {
        printf("Sleep interrupted! %u seconds remaining\n", remaining);
    } else {
        printf("Sleep completed successfully\n");
    }
    
    printf("Time elapsed: %.0f seconds\n", difftime(end, start));
    printf("Program end\n");
    
    return 0;
}

