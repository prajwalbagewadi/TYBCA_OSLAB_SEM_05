/*
1. Write the simulation program using FCFS. The arrival time and first CPU bursts of
different jobs should be input to the system. Assume the fixed I/O waiting time (2
units). The next CPU burstshould be generated using random function. The output
should give the Gantt chart, Turnaround Time and Waiting time for each process and
average times. 
*/

#include<stdio.h>
#include<stdlib.h>
struct process{
    int pid;
    int arrival_time;
    int cpu_burst;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int response_time;
};

//const int max_process=100;
//typedef struct process process;
struct process p[100];
int No_process;
const int Io_wait=2;

void input_process_data(struct process *P,int pid){ //struct process *P (pointer variable)
    printf("Process Data input:\n");
    printf("\n");
    P->pid=pid;
    printf("Process id:%d\n",P->pid);
    printf("Enter Arrival_time:");
    scanf("%d",&P->arrival_time);
    printf("Enter Cpu_burst:");
    scanf("%d",&P->cpu_burst);
    printf("\n");
}

void get_gantt_chart(struct process p[],int size){
    printf("gantt_chart:\n");
    int i,current_time=0;
    for(i=0;i<size;i++){
        if(current_time<p[i].arrival_time){ // for process arrival time can be before or after current time clock.
            current_time=p[i].arrival_time;
        }
        //printf("process %d: %d---%d\n",p[i].pid,current_time,current_time+p[i].cpu_burst);
        printf("process %d: %d---%d\n",p[i].pid,current_time,current_time+p[i].cpu_burst+Io_wait);
        p[i+1].cpu_burst=rand()%10+1; // generate cpu burst with rand()function rand()%n+1 for generating random number between 0 to n
        current_time+=p[i].cpu_burst+Io_wait; // add Io_wait time in current time clock
    }
}

void avg_turn_around_time(struct process p[],int size){
    int i,total_turn_around_time=0;
    for(i=0;i<size;i++){
        total_turn_around_time+=p[i].turn_around_time;
    }
    printf("Average Turn_around_time=%d\n",total_turn_around_time/size);
}

void avg_waiting_time(struct process p[],int size){
    int i,total_waiting_time=0;
    for(i=0;i<size;i++){
        total_waiting_time+=p[i].waiting_time;
    }
    printf("Average waiting_time=%d\n",total_waiting_time/size);
}

void get_data(struct process p[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("\n");
        printf("process Stats:\n");
        printf("process id:%d\n",p[i].pid);
        printf("process id:%d Arrival_time:%d\n",p[i].pid,p[i].arrival_time);
        printf("process id:%d Cpu_burst:%d\n",p[i].pid,p[i].cpu_burst);
        p[i].completion_time=p[i].arrival_time+p[i].cpu_burst;
        printf("process id:%d completion_time:%d\n",p[i].pid,p[i].completion_time);
        p[i].turn_around_time=p[i].completion_time-p[i].arrival_time;
        printf("process id:%d turn_around_time:%d\n",p[i].pid,p[i].turn_around_time);
        p[i].waiting_time=p[i].turn_around_time-p[i].cpu_burst;
        printf("process id:%d waiting_time:%d\n",p[i].pid,p[i].waiting_time);
        p[i].response_time=p[i].waiting_time;
        printf("process id:%d response_time:%d\n",p[i].pid,p[i].response_time);
        printf("\n");
    }
}

int main(){
    printf("Enter No of Processes:");
    scanf("%d",&No_process);
    int i;
    for(i=0;i<No_process;i++){
        input_process_data(&p[i],i);
    }
    get_data(p,No_process);
    get_gantt_chart(p,No_process);
    avg_turn_around_time(p,No_process);
    avg_waiting_time(p,No_process);
    return 0;
}
