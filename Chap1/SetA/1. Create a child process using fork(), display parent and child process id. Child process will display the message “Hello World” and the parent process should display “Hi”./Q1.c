/*
1. Create a child process using fork(), display parent and child process id. Child
process will display the message “Hello World” and the parent process should display
“Hi”.
*/
#include<stdio.h>
#include<unistd.h>
/*
The unistd.h header file is part of the POSIX (Portable Operating System Interface) standard 
and is used in Unix-like operating systems, such as Linux and macOS. 
It provides access to various operating system API functions 
for system calls and other fundamental functions.
#include <unistd.h>: For POSIX API functions like fork() and getpid().
*/
#include<sys/types.h>
/*
The sys/types.h header file is part of the POSIX standard 
and is commonly included in Unix-like operating systems. 
This header file defines a set of data types used in system calls. 
These types are generally used to ensure portability 
across different platforms by providing consistent type definitions.
#include <sys/types.h>: For defining data types used in system calls (pid_t).
*/
int main(){
    pid_t pid; 
    int Ipid;
    /*
        In Unix-like operating systems, 
        pid_t is a data type defined in the sys/types.h header file. 
        It is used to represent process IDs (PIDs). 
        This type is typically defined as an integer, 
        but its exact representation can vary depending on the system.
    */
    pid=fork();
    /*
        The fork() system call is used in Unix-like operating systems 
        to create a new process. 
        The new process created by fork() is called the child process, 
        and the process that called fork() is referred to as the parent process. 
        The child process is a duplicate of the parent process, 
        except for certain differences like unique process IDs and other attributes 
        specific to each process. 
    */
    if(pid<0){ // fork() call failure returns -1.
        printf("Error in fork() call.");
    }
    else if(pid==0){
        // Child process
        printf("Child Process:\n");
        printf("Child Process msg:hello world.\n");
        printf("Child Process PID:%d\n",pid);
        //wait();
        /*
            When pid == 0 after a fork() call, 
            it indicates that the code is executing in the child process. 
            The fork() system call creates a new process 
            by duplicating the calling (parent) process, 
            and the return value of fork() allows 
            the program to distinguish between the parent and child processes.
        */
    }
    else{
        printf("Parent Process:\n");
        printf("Parent Process msg:hi.\n");
        printf("Parent Process PID:%d\n",getpid());
    }
    //common code:
    printf("Common code line run by both processes running in program PID=%d\n",getpid());
    return 0;
}
