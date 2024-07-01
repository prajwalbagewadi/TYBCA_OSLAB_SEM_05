/*
3. Creating a child process without terminating the parent process Write a program to
create a child process using fork().The parent should goto sleep state and child
process should begin its execution. In the child process, use execl() to execute the “ls”
command. 
*/
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main(){
    pid_t pid;
    int stat;
    //create child process
    pid=fork();
    if(pid<0){
        printf("fork() System call Error.");
    }
    else if(pid==0){
        printf("Child Process in Execution:\n");
        printf("Child Process in (Pid:%d):\n",pid);
        /*
            In C, the execl() function is used to replace the current process image with a new process image. 
            It is part of the exec family of functions provided by the unistd.h header. 
            The execl() function executes the program pointed to by path, 
            passing arg0, arg1, ..., argn as arguments to the new program. 
            By convention, arg0 should be the name of the file being executed. 

            Syntax:
            #include <unistd.h>
            int execl(const char *path, const char *arg, ...  (char  *) NULL );
            
            path: The path to the executable file.
            arg: The arguments to the executable. 
            The list of arguments must be terminated by a NULL pointer.
        */
        execl("/usr/bin/ls","ls",NULL);
        return 1;
    }
    else{
        printf("Parent Process in Execution:\n");
        printf("Parent Process in (Pid:%d):\n",getpid());
        // parent process sleeps for 10 sec
        printf("Parent Process in Sleep mode\n");
        sleep(10);
        // wait for child process to complete.
        // printf("Parent Process in wait mode\n");
        // wait(stat);
    }
    printf("Current Process(Program) Execution (Pid:%d)\n",getpid());
    return 0;
}
