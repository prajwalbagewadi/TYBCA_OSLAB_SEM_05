/*
2. Write a program that demonstrates the use of nice() system call. After a child
process is started using fork(), assign higher priority to the child using nice() system
call.
*/
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main(){
    pid_t pid1,pid2,retnice;
    int stat;
    pid1=fork();
    pid2=fork();
    if(pid1<0 || pid2<0){
        printf("Child Process.Creation Error.\n");
        printf("Fork() system call Error.\n");
    }
    else if(pid1==0){
        retnice=nice(-5);
        printf("Child process (pid1) Executing:\n");
        printf("Child process (pid1)(Pid:%d)\n",pid1);
        printf("Parent process (pid1)(Pid:%d)\n",getpid());
        
        /*
            The nice() function in C is used to change the priority of a process. 
            By default, processes are started with a priority of 0. 
            The nice() function can be used to increase or decrease this priority, 
            affecting the scheduling of the process.

            A higher nice value means a lower priority.nice value is +19 (low priority) 
            A lower nice value means a higher priority.to -20 (high priority).
        */
        printf("Child process (pid1)(Pid:%d)\n",retnice);
        printf("child process (pid1)in sleep mode.\n");
        sleep(5);
        printf("Child process (pid1) Terminated.\n\n");
        return 1;
    }
    else if(pid2==0){
        retnice=nice(3);
        printf("Child process (pid2) Executing:\n");
        printf("Child process (pid2)(Pid:%d)\n",pid2);
        printf("Parent process (pid2)(Pid:%d)\n",getpid());
        
        /*
            The nice() function in C is used to change the priority of a process. 
            By default, processes are started with a priority of 0. 
            The nice() function can be used to increase or decrease this priority, 
            affecting the scheduling of the process.

            A higher nice value means a lower priority.nice value is +19 (low priority) 
            A lower nice value means a higher priority.to -20 (high priority).
        */
        printf("Child process (pid2)(Pid:%d)\n",retnice);
        printf("child process (pid2)in sleep mode.\n");
        sleep(5);
        printf("Child process (pid2) Terminated.\n\n");
        return 1;
    }
    else{
        retnice=nice(4);
        printf("Parent process Executing:\n");
        printf("Parent process (Pid:%d)\n",getpid());
        
        printf("Parent process (Pid:%d)\n",retnice);
        printf("Parent process in sleep mode.\n");
        printf("Parent process waiting for Child to complete.\n");
        wait(&stat);
        printf("Child Process status:(%d).\n",stat);
        printf("Parent process Terminated.\n\n");
    }
    printf("Parent process current program (Pid:%d).\n",getpid());
    return 0;
}
