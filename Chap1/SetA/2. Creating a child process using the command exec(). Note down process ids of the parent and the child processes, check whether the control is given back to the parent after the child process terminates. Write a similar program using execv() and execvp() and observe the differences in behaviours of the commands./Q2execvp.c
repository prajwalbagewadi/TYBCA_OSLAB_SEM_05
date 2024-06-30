/*2. Creating a child process using the command exec(). Note down process ids of the
parent and the child processes, check whether the control is given back to the parent
after the child process terminates. Write a similar program using execv() and execvp()
and observe the differences in behaviours of the commands.*/

#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main(){
    /*
        The exec() system call in Unix-like operating systems is used to execute a new program, 
        replacing the current process with a new one. 
        In simpler terms, when a process calls exec(), 
        it stops executing its current code and starts running a new program.
    */
    pid_t pid;
    int stat;
    pid=fork();
    printf("Process using execvp().\n");
    //create child process
    if(pid<0){
        printf("Error: fork() system call.\n");
    }
    else if(pid==0){
        // child process
        printf("Child Process in Execution.\n");
        printf("Child Process(Pid:%d)\n",getpid());
        char* args[]={"./simple",NULL};
        execvp("/home/prajwal/Desktop/os/chap1/SetA/simple",args);
        return 1;
    }
    else{
        // parent process
        printf("Parent Process in Execution.\n");
        printf("Parent Process(Pid:%d)\n",getpid());
        wait(&stat);
        printf("the child process(status:%d)\n",WIFEXITED(stat));
    }
    //common code:
    printf("Parent Process in Execution.\n");
    printf("Common code line run by Parent process ctrl back to Parent(Pid=%d)\n",getpid());
    return 0;
}
