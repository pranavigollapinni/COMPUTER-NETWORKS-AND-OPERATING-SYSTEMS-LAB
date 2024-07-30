#include<stdio.h>
int main()
{
int p[20],et[20],pri[20], wt[20],tat[20],i, k, n, temp;
float wtavg,tatavg;
 int clrscr();
printf("Enter the number of processes --- ");
scanf("%d",&n);
for(i=0;i<n;i++){
p[i] = i;
printf("Enter the Execution Time & Priority of Process %d --- ",i);
scanf("%d%d",&et[i], &pri[i]);
}
for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
if(pri[i] > pri[k]){
temp=p[i];
p[i]=p[k];
p[k]=temp;
temp=et[i];
et[i]=et[k];
et[k]=temp;
temp=pri[i];
pri[i]=pri[k];
pri[k]=temp;
}
wtavg = wt[0] = 0;
tatavg = tat[0] = et[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + et[i-1];
tat[i] = tat[i-1] + et[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\nPROCESS\t\tPRIORITY\tEXECUTION TIME\tWAITING TIME\tTURNAROUNDTIME");
for(i=0;i<n;i++)
printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],pri[i],et[i],wt[i],tat[i]);
printf("\nAverage Waiting Time is --- %f",wtavg/n);
printf("\nAverage Turnaround Time is --- %f",tatavg/n);
getch();
}
