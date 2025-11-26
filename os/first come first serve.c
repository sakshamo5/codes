#include <stdio.h>

int main(){
	printf("Enter the number of processes: ");
	int np;
	scanf("%d",&np);
	
	printf("Assumning arrival time to be 0 for all processes \n");
	
	int arrival[np];
	
	int burst_processes[np];
	
	for(int i=0;i<np;i++){
		printf("\n");
		printf("Enter the burst time for process no: %d ", i+1);
		scanf("%d",&burst_processes[i]);
		printf("Enter the arrival time for process no: %d ", i+1);
		scanf("%d",&arrival[i]);
		printf("\n");
		
		//arrival[i]=0;
	}
	
	
	int matrix[np][3];
	int global_time=0;
	for(int i=0;i<np;i++){
		for(int j=0;j<3;j++){
		if(j==0){
			matrix[i][j]=burst_processes[i];
		}	
		if(j==1){
			matrix[i][j]=global_time-arrival[i];
		}
		if(j==2){
			matrix[i][j]=matrix[i][0]+matrix[i][1];
			global_time+=burst_processes[i];
		}
		}
	}
	
	printf("Name   burst   waiting   turnaround\n");
	for(int i=0;i<np;i++){
		printf("P%d   \t%d   \t%d      \t%d\n",i,matrix[i][0],matrix[i][1],matrix[i][2]);
	}
	float tt=0;
	float wt=0;
	for(int i=0;i<np;i++){
		tt=tt+matrix[i][2];
		wt=wt+matrix[i][1];
	}
	float avg_tt=tt/np;
	float avg_wt=wt/np;
	printf("Average turnaround time: %f\n",avg_tt);
	printf("Average waiting time: %f",avg_wt);
	
	
	return 0;
}

