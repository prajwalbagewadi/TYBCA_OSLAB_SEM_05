/*
1. Write the program to simulate Preemptive Shortest Job First (SJF) -scheduling.
Thearrival time and first CPU-burst for different n number of processes should be
input to thealgorithm. Assume the fixed IO waiting time (2 units). The next CPU-
burst should be generated randomly. The output should give Gantt chart, turnaround
time and waitingtime for each process. Also find the average waiting time and
turnaround time.
*/

package PSJF;
import java.lang.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Iterator;

class Process{
    public int pid;  // Process Id
    public int AT;   //Arrival Time
    public int BT;   //Burst Time
    public int RBT;  //Remaining Burst Time
    public int CT;   //Completion Time
    public int TAT;  //Turn Around Time
    public int WT;   //Waiting Time
    //int RT;   //Response Time
    public static Scanner sc=new Scanner(System.in);
    
    public Process(){
        
    }
    
    public void getPdata(int pid){
        System.out.println("\nEnter Process Data:");
        this.pid=pid+1;
        System.out.println("Enter Pid:"+this.pid+": AT:");
        this.AT=sc.nextInt();
        System.out.println("Enter Pid:"+this.pid+": BT:");
        this.BT=sc.nextInt();
        this.RBT=this.BT;
        this.CT=0;
        System.out.println("Pid:"+this.pid+": AT:"+this.AT+":");
        System.out.println("Pid:"+this.pid+": BT:"+this.BT+":");
        System.out.println("Pid:"+this.pid+": RBT:"+this.RBT+":");
        System.out.println("Pid:"+this.pid+": CT:"+this.CT+":");
    }
    
    public void dispP(){
        System.out.println("Process Data:");
        System.out.println("Pid:"+this.pid+":");
        System.out.println("Pid:"+this.pid+": AT:"+this.AT+":");
        System.out.println("Pid:"+this.pid+": BT:"+this.BT+":");
        System.out.println("Pid:"+this.pid+": RBT:"+this.RBT+":");
        System.out.println("Pid:"+this.pid+": CT:"+this.CT+":");
    }
}

public class Q1{
    public Process[] p=new Process[10];
     
    int getTotalBT(Process p[],int size){
        int totalBT=0;
        for(int i=0;i<size;i++){
            totalBT+=p[i].BT;
        }
        return totalBT;
    }
    public void ganttChart(Process p[],int size){
        System.out.println("\nGantt Chart:");
        ArrayList<Process> rq=new ArrayList<Process>();
        Process minBT;
        int currTime=0,i=0,totalBT=getTotalBT(p,size);
        System.out.println("Total BT:"+totalBT);
        while(i<size){
            System.out.println("I="+i);
            if(p[i].AT==currTime){
                if(rq.isEmpty()){
                    System.out.println("current Time="+currTime);
                    System.out.println("Ready Queue is empty.");
                    System.out.println("Pid:"+p[i].pid+": :"+currTime+":==:"+(currTime+1)+":\n");
                    p[i].RBT--;
                    p[i].CT=currTime+1;
                    currTime++;
                    rq.add(p[i]);  
                }
                else{
                    rq.add(p[i]);
                    System.out.println("current Time="+currTime);
                    System.out.println("Ready Queue is not empty.");
                    System.out.println("Ready Queue:");
                    rq.forEach(Process->Process.dispP());
                    
                    Iterator<Process> iter=rq.iterator();
                    while(iter.hasNext()){
                        if(iter.next().RBT==0){
                            iter.remove();
                        }
                    }
                    minBT=rq.get(0);
                    for(Process q:rq){
                        if(q.RBT<minBT.RBT){
                            minBT=q;
                        }   
                    }
                    
                    System.out.println("Pid:"+minBT.pid+": :"+currTime+":==:"+(currTime+1)+":");
                    minBT.RBT--;
                    minBT.CT=currTime+1;
                    currTime++;
                }
                i++;
            }
            else{
                System.out.println("current Time="+currTime);
                System.out.println("No Processes to Enter.");
                System.out.println("Ready Queue:");
                rq.forEach(Process->Process.dispP());
                
                Iterator<Process> iter=rq.iterator();
                while(iter.hasNext()){
                    if(iter.next().RBT==0){
                        iter.remove();
                    }
                }
                minBT=rq.get(0);
                for(Process q:rq){
                    if(q.RBT<minBT.RBT){
                        minBT=q;
                    }   
                }
                System.out.println("Pid:"+minBT.pid+": :"+currTime+":==:"+(currTime+1)+":");
                minBT.RBT--;
                minBT.CT=currTime+1;
                currTime++;
            }
        }
        //while(currTime<=totalBT){
        while(!rq.isEmpty()){
            System.out.println("current Time="+currTime);
            System.out.println("Processes are entered in queue.");
            System.out.println("Ready Queue:");
            rq.forEach(Process->Process.dispP());
            
            Iterator<Process> iter=rq.iterator();
            while(iter.hasNext()){
                if(iter.next().RBT==0){
                    iter.remove();
                    //break;
                }
            }
            if(rq.size()==1){
                while(currTime<totalBT){
                    System.out.println("current Time="+currTime);
                    System.out.println("Ready Queue has sigle Element.");
                    System.out.println("Pid:"+rq.getLast().pid+": :"+currTime+":==:"+(currTime+1)+":\n");
                    rq.getLast().RBT--;
                    rq.getLast().CT=currTime+1;
                    currTime++;
                }
                break;
            }
            
            minBT=rq.get(0);
            for(Process q:rq){
                if(q.RBT<minBT.RBT){
                    minBT=q;
                }   
            }
            System.out.println("Pid:"+minBT.pid+": :"+currTime+":==:"+(currTime+1)+":");
            minBT.RBT--;
            minBT.CT=currTime+1;
            currTime++;
            System.out.println("Time="+currTime);
            
            
        }
        //}
    }
    
    public void putTAT(Process p[],int size){
        for(int i=0;i<size;i++){
            p[i].TAT=p[i].CT-p[i].AT;
        }
    }
    
    public void putWT(Process p[],int size){
        for(int i=0;i<size;i++){
            p[i].WT=p[i].TAT-p[i].BT;
        }
    }
    
    public void averageTAT(Process p[],double size){
        double TotalTAT=0;
        for(int i=0;i<size;i++){
            TotalTAT+=p[i].TAT;
        }
        System.out.println("--Average TAT="+((double)TotalTAT/size));
    }
    
    public void averageWT(Process p[],double size){
        double TotalWT=0;
        for(int i=0;i<size;i++){
            TotalWT+=p[i].WT;
        }
        System.out.println("--Average WT="+((double)TotalWT/size));
    }
    
    public static void main(String[] args){
        System.out.println("Preemptive Shortest Job First (SJF) -scheduling.");
        System.out.println("Enter Number of Processes:");
        int n=Process.sc.nextInt();
        Q1 Q1obj=new Q1();
  
        //input 
        for(int i=0;i<n;i++){
            Q1obj.p[i]=new Process();
            Q1obj.p[i].getPdata(i);
        }
        
        //disp
        for(int i=0;i<n;i++){
            Q1obj.p[i].dispP();
        }
        
        //create ganttChart
        Q1obj.ganttChart(Q1obj.p,n);
        
        //put TAT for each process
        Q1obj.putTAT(Q1obj.p,n);
        
        //put WT for each process
        Q1obj.putWT(Q1obj.p,n);
        
        //disp
        System.out.println("Final Data:");
        for(int i=0;i<n;i++){
            Q1obj.p[i].dispP();
        }
        
        //Average TAT
        Q1obj.averageTAT(Q1obj.p,n);
        
        //Average WT
        Q1obj.averageWT(Q1obj.p,n);
    }
}
