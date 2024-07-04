/*
3. Write a program to find the execution time taken for execution of a given set of
instructions (Hint: use clock() function. This function clock() is called at the
beginning of program and again at the end of the program and the difference between
the values returned gives the time spent by processor on the program.)
*/
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>
#include<stdio.h>
int main(){
    printf("Exec time:\n");
    clock_t starttime=clock();
    /*
    The clock() function in C returns the approximate processor time that is consumed by the program 
    which is the number of clock ticks used by the program since the program started. 

    The difference between the clock() value at the beginning of the program and the clock() value at the point 
    where we want to measure the clock ticks is the number of clock ticks used by a program. 
    The result can be converted to seconds using the CLOCKS_PER_SEC constant, which represents the number of clock ticks per second.
    */

    printf("Start clock:(%ld)\n",starttime);
    int i,n=10;
    // printf("enter num for loop Exec:");
    // scanf("%d",&n);
    for(i=0;i<=n;i++){
        printf("the Loop under Exec:%d\n",i);
    }
    clock_t endtime=clock();
    printf("end clock:(%ld)\n",endtime);
    clock_t tot_time=endtime-starttime;
    printf("total Execution Time in clock ticks:%ld\n",tot_time);
    printf("total Execution Time:%f\n",(float)tot_time/CLOCKS_PER_SEC);
    /*
    Typecasting in C is the process of converting one data type to another data type 
    by the programmer using the casting operator during program design. 
    Syntax:

    int x;
    float y;
    y = (float) x;
    */
    return 0;
}
