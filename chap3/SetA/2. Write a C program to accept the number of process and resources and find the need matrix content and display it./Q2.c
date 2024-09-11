/**
 * 2. Write a C program to accept the number of process and resources and find the need 
 * matrix content and display it.
 */
#include<stdio.h>
#include<stdlib.h>
int **remainingNeed(int no_resources,int no_processes,int allocated[][no_resources],int max[][no_resources]){
    // int X no_rows
    int **need=(int **)malloc(sizeof(int*)*no_processes);
    // int X no_cols
    for(int i=0;i<no_processes;i++){
        need[i]=(int *)malloc(sizeof(int)*no_resources);
    }
    for(int i=0;i<no_processes;i++){
        for(int j=0;j<no_resources;j++){
            need[i][j]=max[i][j] - allocated[i][j];
           
        }
    }
    return need;
}
int main(){
    int no_processes,no_resources,temp;

    printf("Enter number of Processes:");
    scanf("%d",&no_processes);
    printf("number of Processes:%d\n",no_processes);
    printf("Enter number of Resources:");
    scanf("%d",&no_resources);
    int allocated[no_processes][no_resources],max[no_processes][no_resources];
    int resource[no_resources];
    printf("number of Resources:%d\n",no_resources);
    for(int i=0;i<no_resources;i++){
        printf("Enter no of Resources of Type[%d] available:",i);
        scanf("%d",&resource[i]);
        printf("Available Resources:%d\n",resource[i]);
    }

    printf("enter pre allocated Resources:\n");
    for(int i=0;i<no_processes;i++){

        for(int j=0;j<no_resources;j++){
           printf("[%d][%d]:",i,j);
           scanf("%d",&temp);
           if(temp<=resource[j]){
                allocated[i][j]=temp;
           }
           
        }
    }
    printf("Pre Allocation matrix:\n");
    for(int i=0;i<no_processes;i++){

        for(int j=0;j<no_resources;j++){
           printf("%d \t",allocated[i][j]);
        }
        printf("\n");
    }

    printf("enter Max need Resources:\n");
    for(int i=0;i<no_processes;i++){

        for(int j=0;j<no_resources;j++){
           printf("[%d][%d]:",i,j);
           scanf("%d",&temp);
           if(temp<=resource[j]){
                max[i][j]=temp;
           }
           
        }
    }
    printf("Max need matrix:\n");
    for(int i=0;i<no_processes;i++){

        for(int j=0;j<no_resources;j++){
           printf("%d \t",max[i][j]);
        }
        printf("\n");
    }
    printf("Remaining need matrix");
    int **need=remainingNeed(no_resources,no_processes,allocated,max);
    for(int i=0;i<no_processes;i++){
        for(int j=0;j<no_resources;j++){
            printf("%d \t",need[i][j]);
        }
        printf("\n");
    }
    return 0;
}
