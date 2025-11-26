// Round Robin Scheduling with Arrival Time
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int process;
    int burst_time;
    int remaining_time;
    int arrival;
    int waiting;
    int turnaround;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* ptr = NULL;
struct Node* temp = NULL;

void insert(int p, int b, int a) {
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->arrival = a;
    temp->burst_time = b;
    temp->process = p;
    temp->remaining_time = b;
    temp->turnaround = 0;
    temp->waiting = 0;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        ptr = temp;
    } else {
        ptr->next = temp;
        ptr = ptr->next;
    }
}

int main() {
    int np, time_slice;
    printf("Round Robin Scheduling\n");
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the time slice: ");
    scanf("%d", &time_slice);

    for (int i = 0; i < np; i++) {
        int p, a, b;
        printf("\nEnter the burst time of process P%d: ", i + 1);
        scanf("%d", &b);
        printf("Enter the arrival time of process P%d: ", i + 1);
        scanf("%d", &a);
        p = i + 1;
        insert(p, b, a);
    }

    int current_time = 0;
    int done = 0;

    do {
        done = 1;
        for (struct Node* temp = head; temp != NULL; temp = temp->next) {
            if (temp->remaining_time > 0 && temp->arrival <= current_time) {
                done = 0;

                if (temp->remaining_time > time_slice) {
                    current_time += time_slice;
                    temp->remaining_time -= time_slice;
                } else {
                    current_time += temp->remaining_time;
                    temp->waiting = current_time - temp->arrival - temp->burst_time;
                    temp->turnaround = current_time - temp->arrival;
                    temp->remaining_time = 0;
                }
            }
        }

        // if no process has arrived yet, advance time
        int all_idle = 1;
        for (struct Node* temp = head; temp != NULL; temp = temp->next) {
            if (temp->remaining_time > 0) {
                all_idle = 0;
                if (temp->arrival > current_time) {
                    current_time = temp->arrival;
                }
                break;
            }
        }

        if (all_idle) done = 1;

    } while (!done);

    // Print results
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (struct Node* temp = head; temp != NULL; temp = temp->next) {
        printf("P%d\t%d\t%d\t%d\t%d\n", temp->process, temp->arrival,
               temp->burst_time, temp->waiting, temp->turnaround);
    }

    float tt = 0, wt = 0;
    for (struct Node* temp = head; temp != NULL; temp = temp->next) {
        tt += temp->turnaround;
        wt += temp->waiting;
    }
    printf("\nAverage Turnaround Time: %.2f\n", tt / np);
    printf("Average Waiting Time: %.2f\n", wt / np);

    return 0;
}
