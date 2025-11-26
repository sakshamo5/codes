#include<stdio.h>

int main(){
int n,m,i,j,k;
int alloc[10][10], max[10][10], avail[10];
int need[10][10], finish[10], safeSeq[10];
int count=0;

printf("Enter Number of Processes: ");
scanf("%d", &n);
printf("Enter Number of resorce types: ");
scanf("%d", &m);
printf("Enter allocation matrix:\n");
for(i=0;i<n;i++){
for(j=0;j<m;j++){
scanf("%d", &alloc[i][j]);
}
}

printf("Enter max matrix:\n");
for(i=0;i<n;i++){
for(j=0;j<m;j++){
scanf("%d", &max[i][j]);
}
}

printf("Enter available matrix:\n");
for(i=0;i<m;i++){
scanf("%d", &avail[i]);
}

printf("Finding Need matrix:\n");
for( i=0;i<n;i++){
for(j=0;j<m;j++){
need[i][j]=max[i][j]-alloc[i][j];
}
}

printf("Initialising Finish matrix\n");
for(i=0;i<n;i++){
finish[i]=0;
}

int flag=1;
while(count<n&&flag){
flag=0;
for(i=0;i<n;i++){
if(finish[i]==0){
int canAlloc=1;
for(j=0;j<m;j++){
if(need[i][j]>avail[j]){
canAlloc=0;
break;
}
}
if(canAlloc){
for(k=0;k<m;k++){
avail[k]+=alloc[i][k];
}
safeSeq[count++]=i;
finish[i]=1;
flag=1;
}
}
}
}

if(count==n){
printf("\nSystem is in Safe Sequence.\nSafe Sequence is:\n");
for(i=0;i<n;i++){
printf("P%d ", safeSeq[i]);
}
} else {
printf("\nSystem is not in a sfe sequence.");
}
printf("\n");
}
