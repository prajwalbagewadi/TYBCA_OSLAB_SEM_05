/*
1. Write the program to calculate minimum number of resources needed to avoid
deadlock. 
*/
#include<stdio.h>
int cal_min_res(int processes[],int allocted[],int max[],int num_processes){
    int min_res_needed=0,total_allocated=0,total_max=0;
    for(int i=0;i<num_processes;i++){
        total_allocated+=allocted[i];
        total_max+=max[i];
    }
    printf("total max=%d\n",total_max);
    printf("total allocated=%d\n",total_allocated);
    // formula min_res_needed=total_max-total_allocated+1;
    min_res_needed=total_max-total_allocated+1;
    return min_res_needed;
}
int main(){
    int num_processes,need;//,num_resources;
    printf("Enter number of Processes:");
    scanf("%d",&num_processes);
    // printf("Enter number of Resources:");
    // scanf("%d",&num_resources);
    int processes[num_processes],allocated[num_processes],max[num_processes];
    //input allocated resources
    printf("Enter allocated resources for each process:\n");
    for(int i=0;i<num_processes;i++){
        printf("Process %d:",i+1);
        scanf("%d",&allocated[i]);
    }
    //disp
    printf("disp.\n");
    for(int i=0;i<num_processes;i++){
        printf("Process %d:",i+1);
        printf("%d\n",allocated[i]);
    }
    //input max resources need
    printf("Enter max resources for each process:\n");
    for(int i=0;i<num_processes;i++){
        printf("Process %d:",i+1);
        scanf("%d",&max[i]);
    }
    //disp
    printf("disp.\n");
    for(int i=0;i<num_processes;i++){
        printf("Process %d:",i+1);
        printf("%d\n",max[i]);
    }
    need=cal_min_res(processes,allocated,max,num_processes);
    printf("minimum Resouces needed to avoid deadlock:%d",need);
    return 0;
}
