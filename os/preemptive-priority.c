#include <stdio.h>

int main(){
	
	printf("Preemptive priority scheduling algo\n");
	printf("Enter the number of processes: ");
	int np;
	scanf("%d",&np);
	int burst[np],arrival[np],waiting[np],turnaround[np],remaining[np],id[np],completion[np],priority[np];
	for(int i=0;i<np;i++){
		printf("Enter the burst time for process P%d: ",i+1);
		scanf("%d",&burst[i]);
		printf("Enter the arrival time for process P%d: ",i+1);
		scanf("%d",&arrival[i]);
		printf("Enter the priority for process P%d: ",i+1);
		scanf("%d",&priority[i]);
		remaining[i]=burst[i];
		printf("\n");
		}
		
	int completed=0;
	int time=0;
	while(completed<np){
		int highest=-1;
		int high=999;
		for(int i=0;i<np;i++){
			if(arrival[i]<=time && remaining[i]>0 && priority[i]<high){
				high=priority[i];
				highest=i;}
			}
		if(highest==-1){
			time++;
			continue;}
		time++;
		remaining[highest]--;
		if(remaining[highest]==0){
			completed++;
			completion[highest]=time;
			turnaround[highest]=completion[highest]-arrival[highest];
			waiting[highest]=turnaround[highest]-burst[highest];
			}
		}
	printf("\nProcess\tBurst\tArrival\tPriority\tWaiting\tTurnaround\n");
    for(int i = 0; i < np; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", 
               i + 1, burst[i], arrival[i], priority[i], waiting[i], turnaround[i]);
    }
    
    float total_wt = 0, total_tt = 0;
    for(int i = 0; i < np; i++) {
        total_wt += waiting[i];
        total_tt += turnaround[i];
    }
    
    printf("Average turnaround time: %f\n", total_tt / np);
    printf("Average waiting time: %f\n", total_wt / np);
    
    return 0;
	
	}
