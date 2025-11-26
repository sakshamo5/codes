//Round Robin Scheduling


#include <stdio.h>
#include <stdlib.h>

struct Node{
	int process;
	int burst_time;
	int remaining_time;
	int arrival;
	int waiting;
	int turnaround;	
	struct Node* next;
	};

struct Node* head=NULL;
struct Node* ptr=NULL;
struct Node* pptr=NULL;
struct Node* temp=NULL;


void insert(int p, int b, int a){
	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->arrival=a;
	temp->burst_time=b;
	temp->process=p;
	temp->remaining_time=b;
	temp->turnaround=0;
	temp->waiting=0;
	temp->next=NULL;
	
	if (head==NULL){
		head=temp;
		ptr=temp;
		}
	else{
	ptr->next=temp;
	ptr=ptr->next;}	
}
int main(){
	int np,time;
	printf("Round Robin Scheduling \n");
	printf("Enter the number of processes: ");
	scanf("%d",&np);
	printf("Enter the time slice: ");
	scanf("%d",&time);
	for(int i=0;i<np;i++){
		int p,a,b;
		printf("Enter the burst time of process P%d: ",i+1);
		scanf("%d",&b);
		p=i+1;
		a=0;
		insert(p,b,a);
	}
	int current_time=0;
	int done=0;
	do{
		done=1;
		for(struct Node* temp = head; temp != NULL; temp = temp->next){
            if(temp->remaining_time > 0){
                done = 0;  
                if(temp->remaining_time > time){
                    current_time += time;
                    temp->remaining_time -= time;
                } else {
                    current_time += temp->remaining_time;
                    temp->waiting = current_time - temp->arrival - temp->burst_time;
                    temp->turnaround = current_time - temp->arrival;
                    temp->remaining_time = 0;
                }
            }
        }
		}
	while(!done);
	
	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(struct Node* temp = head; temp != NULL; temp = temp->next){
        printf("P%d\t\t%d\t\t%d\t\t%d\n", temp->process, temp->burst_time, temp->waiting, temp->turnaround);
    }
    
    float tt=0;
	float wt=0;
	for(struct Node* temp = head; temp != NULL; temp = temp->next){
       tt+=temp->turnaround;
       wt+=temp->waiting;
    }
	float avg_tt=tt/np;
	float avg_wt=wt/np;
	printf("Average turnaround time: %f\n",avg_tt);
	printf("Average waiting time: %f\n",avg_wt);
	return 0;
	
	
}

