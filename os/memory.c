#include <stdio.h>

void allocate(int blocks[], int m, int process[], int n, char* method) {
    int alloc[10], temp[10], totalWaste = 0;
        for(int i = 0; i < m; i++) 
        temp[i] = blocks[i];
    
        for(int i = 0; i < n; i++)
        alloc[i] = -1;
    
        for(int i = 0; i < n; i++) {
        int idx = -1;
        
        if(method[0] == 'F') {  // First Fit
            for(int j = 0; j < m; j++) {
                if(temp[j] >= process[i]) {
                    idx = j;
                    break;
                }
            }
        } 
        else if(method[0] == 'B') {
            for(int j = 0; j < m; j++) {
                if(temp[j] >= process[i]) {
                    if(idx == -1 || temp[j] < temp[idx])
                        idx = j;
                }
            }
        } 
        else {
            for(int j = 0; j < m; j++) {
                if(temp[j] >= process[i]) {
                    if(idx == -1 || temp[j] > temp[idx])
                        idx = j;
                }
            }
        }
        
        if(idx != -1) {
            alloc[i] = idx;
            totalWaste += (temp[idx] - process[i]);
            temp[idx] -= process[i];
        }
    }
    
    printf("\n%s:\n", method);
    for(int i = 0; i < n; i++) {
        printf("P%d(%d): %s\n", i+1, process[i], 
               alloc[i] != -1 ? "Allocated" : "NOT ALLOCATED");
    }
    printf("Total Waste: %d\n", totalWaste);
}

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    printf("Blocks: 100, 500, 200, 300, 600\n");
    printf("Processes: 212, 417, 112, 426\n");

    
    allocate(blocks, 5, process, 4, "First Fit");
    allocate(blocks, 5, process, 4, "Best Fit");
    allocate(blocks, 5, process, 4, "Worst Fit");
    
    return 0;
}
