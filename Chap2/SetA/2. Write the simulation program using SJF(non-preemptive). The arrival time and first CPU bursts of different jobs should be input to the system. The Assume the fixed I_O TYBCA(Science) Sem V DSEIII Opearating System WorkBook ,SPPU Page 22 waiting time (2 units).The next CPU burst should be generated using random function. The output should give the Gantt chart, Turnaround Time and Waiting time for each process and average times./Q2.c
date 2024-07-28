/*
2. Write the simulation program using SJF(non-preemptive). The arrival time and first
CPU bursts of different jobs should be input to the system. The Assume the fixed I_O
TYBCA(Science) Sem V DSEIII Opearating System WorkBook ,SPPU Page 22
waiting time (2 units).The next CPU burst should be generated using random
function. The output should give the Gantt chart, Turnaround Time and Waiting time
for each process and average times.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define IOWAIT 2

struct process{
	int pid;// Process Id
    int AT; //Arrival Time
    int BT; //Burst Time
    int CT; //Completion Time
    int TAT;//Turn Around Time
    int WT; //Waiting Time
    int RT; //Response Time
};

typedef struct process Process;
Process p[MAX];
int numOfProcess;

void inputProcessData(Process *p,int pid){
    printf("\n Enter Process Data:\n");
    p->pid=pid;
    printf("Enter AT for pid:%d:",p->pid);
    scanf("%d",&p->AT);
    printf("Enter BT for pid:%d:",p->pid);
    scanf("%d",&p->BT);
    printf("pid:%d: AT:%d:\n",p->pid,p->AT);
    printf("pid:%d: BT:%d:\n",p->pid,p->BT);
}

//insertion Sort.
void swap(Process *a,Process *b){
	Process temp=*a;
	*a=*b;
	*b=temp;
}
void sortByBT(Process p[],int size){
	int s,u; // s=sorted u=unsorted;
	for(u=1;u<size;u++){
		s=u-1;
		while(s>=0)
		{
			if(p[s].BT > p[s+1].BT){
				swap(&p[s],&p[s+1]);
			}
			s--;
		}	
	}
}

void dispProcessData(Process *p){
    printf("\n Process Data:\n");
    printf("pid:%d:\n",p->pid);
    printf("pid:%d: AT:%d:\n",p->pid,p->AT);
    printf("pid:%d: BT:%d:\n",p->pid,p->BT);
    printf("pid:%d: CT:%d:\n",p->pid,p->CT);
    printf("pid:%d: TAT:%d:\n",p->pid,p->TAT);
    printf("pid:%d: WT:%d:\n",p->pid,p->WT);
    printf("pid:%d: RT:%d:\n",p->pid,p->RT);
    printf("\n");
}

void display(Process p[],int size){
    for(int i=0;i<size;i++){
        dispProcessData(&p[i]);
    }
}

void createGanttChart(Process p[],int size){
    printf("Gantt_Chart:\n");
    int current_time=0;
    for(int i=0;i<size;i++){
        if(current_time<p[i].AT){
            current_time+=p[i].AT;
        }
        printf("pid:%d: :%d:--:%d:\n",p[i].pid,current_time,current_time+p[i].BT+IOWAIT);
        p[i].CT=current_time+=p[i].BT+IOWAIT; // add Io_wait time in current time clock
        p[i+1].BT=rand()%10+1;// generate cpu burst with rand()function rand()%n+1 for generating random number between 0 to n
        printf("pid:%d: CT:%d:\n",p[i].pid,p[i].CT);
        p[i].TAT=p[i].CT-p[i].AT;
        printf("pid:%d: TAT:%d:\n",p[i].pid,p[i].TAT);
        p[i].WT=p[i].TAT-p[i].BT;
        printf("pid:%d: WT:%d:\n",p[i].pid,p[i].WT);
        p[i].RT=p[i].WT;
        printf("pid:%d: RT:%d:\n",p[i].pid,p[i].RT);
        printf("\n");
    }  
}

void averageTAT(Process p[],int size){
    int TTAT=0;
    for(int i=0;i<size;i++){
        TTAT+=p[i].TAT;
    }
    float Avg=(float)TTAT/size;
    printf("Average Turn Around Time:%f:\n",Avg);
}

void averageWT(Process p[],int size){
    int TWT=0;
    for(int i=0;i<size;i++){
        TWT+=p[i].WT;
    }
    float Avg=(float)TWT/size;
    printf("Average Waiting Time:%f:\n",Avg);
}

int main(){
	printf("SJF Non Preemptive Scheduling:\n");
	printf("Enter No of Processes:");
	scanf("%d",&numOfProcess);
	int i;
	for(i=0;i<numOfProcess;i++){
    	inputProcessData(&p[i],i+1);
    }
    display(p,numOfProcess);
    sortByBT(p,numOfProcess);
    display(p,numOfProcess);
    createGanttChart(p,numOfProcess);
    display(p,numOfProcess);
    averageTAT(p,numOfProcess);
    averageWT(p,numOfProcess);
	return 0;
}
