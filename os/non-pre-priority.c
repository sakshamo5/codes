
#include <stdio.h>


void sorting(int Arr[][4], int n) {
    int i, j;
    int temp[4];
    for (j = 1; j < n; j++) {
        temp[0] = Arr[j][0]; 
        temp[1] = Arr[j][1]; 
        temp[2] = Arr[j][2]; 
        temp[3] = Arr[j][3];

        i = j - 1;
        while (i >= 0 && Arr[i][3] > temp[3]) {
            Arr[i + 1][0] = Arr[i][0];
            Arr[i + 1][1] = Arr[i][1];
            Arr[i + 1][2] = Arr[i][2];
            Arr[i + 1][3] = Arr[i][3];
            i--;
        }
        Arr[i + 1][0] = temp[0];
        Arr[i + 1][1] = temp[1];
        Arr[i + 1][2] = temp[2];
        Arr[i + 1][3] = temp[3];
    }
}

int main(){
	printf("Non-Preemptive Priority Scheduling\n");	
	printf("Enter the number of jobs: ");
	int nj;
	scanf("%d",&nj);
	
	
	int jobs[nj][4];
	
	for(int i=0;i<nj;i++){
		printf("\n");
		printf("Enter the burst time for Job no. %d: ",i+1);
		scanf("%d",&jobs[i][1]);
		//printf("Enter the arrival time for Job no. %d: ",i+1);
		//scanf("%d",&arrival_jobs[i]);
		printf("Enter the priority for Job no. %d: ",i+1);
		scanf("%d",&jobs[i][3]);
		jobs[i][2]=0;
		jobs[i][0]=i+1;
	}
	sorting(jobs,nj);
	
	int matrix[nj][3];
	int global_time=0;
	for(int i=0;i<nj;i++){
		for(int j=0;j<3;j++){
		if(j==0){
			matrix[i][j]=jobs[i][1];
		}	
		if(j==1){
			matrix[i][j]=global_time-jobs[i][2];
		}
		if(j==2){
			matrix[i][j]=matrix[i][0]+matrix[i][1];
			global_time+=jobs[i][1];
		}
		}
	}
	
	printf("Name   burst   waiting   turnaround\n");
	for(int i=0;i<nj;i++){
		printf("P%d   \t%d   \t%d    \t%d\n",jobs[i][0],matrix[i][0],matrix[i][1],matrix[i][2]);
	}
	float tt=0;
	float wt=0;
	for(int i=0;i<nj;i++){
		tt=tt+matrix[i][2];
		wt=wt+matrix[i][1];
	}
	float avg_tt=tt/nj;
	float avg_wt=wt/nj;
	printf("Average turnaround time: %f\n",avg_tt);
	printf("Average waiting time: %f\n",avg_wt);
	return 0;
}



