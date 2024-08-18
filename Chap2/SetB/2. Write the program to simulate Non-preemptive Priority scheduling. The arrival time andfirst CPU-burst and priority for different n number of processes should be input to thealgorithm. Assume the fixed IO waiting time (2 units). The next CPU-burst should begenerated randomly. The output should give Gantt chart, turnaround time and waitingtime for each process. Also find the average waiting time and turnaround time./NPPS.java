/*
2. Write the program to simulate Non-preemptive Priority scheduling. The arrival time
andfirst CPU-burst and priority for different n number of processes should be input to
thealgorithm. Assume the fixed IO waiting time (2 units). The next CPU-burst should
begenerated randomly. The output should give Gantt chart, turnaround time and
waitingtime for each process. Also find the average waiting time and turnaround time.
*/

package non_preemptive_priority_scheduling;
import java.lang.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Iterator;

class Process{
    public int pid;  //Process Id
    public int AT;   //Arrival Time
    public int BT;   //Burst Time
    public int prio; //Process Prority.
    public int CT;   //Completion Time
    public int TAT;  //Turn Around Time
    public int WT;   //Waiting Time
    public static Scanner sc=new Scanner(System.in);
    
    public Process(){
        
    }
    
    public Process(int pid,int AT,int BT,int Prio){
        this.pid=pid;
        this.AT=AT;
        this.BT=BT;
        this.prio=Prio;
        this.CT=0;
    }
    
    public void getPdata(int pid){
        System.out.println("\nEnter Process Data:");
        this.pid=pid+1;
        System.out.println("Enter Pid:"+this.pid+": AT:");
        this.AT=sc.nextInt();
        System.out.println("Enter Pid:"+this.pid+": BT:");
        this.BT=sc.nextInt();
        System.out.println("Enter Pid:"+this.pid+": Prio:");
        this.prio=sc.nextInt();
        this.CT=0;
        System.out.println("Pid:"+this.pid+": AT:"+this.AT+":");
        System.out.println("Pid:"+this.pid+": BT:"+this.BT+":");
        System.out.println("Pid:"+this.pid+": Prio:"+this.prio+":");
        System.out.println("Pid:"+this.pid+": CT:"+this.CT+":");
    }
    
    public void dispP(){
        System.out.println("Process Data:");
        System.out.println("Pid:"+this.pid+":");
        System.out.println("Pid:"+this.pid+": AT:"+this.AT+":");
        System.out.println("Pid:"+this.pid+": BT:"+this.BT+":");
        System.out.println("Pid:"+this.pid+": Prio:"+this.prio+":");
        System.out.println("Pid:"+this.pid+": CT:"+this.CT+":");
    }
}


public class NPPS{
    public Process[] p=new Process[10];
    public ArrayList<Process> rq=new ArrayList<Process>();
    Process max;
    int getTotalBT(Process p[],int size){
        int totalBT=0;
        for(int i=0;i<size;i++){
            totalBT+=p[i].BT;
        }
        return totalBT;
    }
    public void ganttChart(Process[] p,int size){
        int curr_time=0,totalBT=getTotalBT(p,size);
        while(curr_time<totalBT){
            
            for(int i=0;i<size;i++){
                if(p[i].AT<=curr_time && p[i].CT==0){
                    System.out.println("i="+i);
                    rq.add(p[i]);
                    System.out.println("Time="+curr_time);
                }
            }
            
            while(!rq.isEmpty()){
                System.out.println("Ready queue:");
                rq.forEach(Process->Process.dispP());
                max=rq.get(0);
                for(Process q:rq){
                    if(q.prio >= max.prio){
                        if(q.prio==max.prio){
                            if(q.AT<max.AT){
                                max=q;
                            }
                        }
                        else{
                            max=q;
                        }
                    }
                }
                System.out.println("pid["+max.pid+"]"+" ["+curr_time+"]==["+(curr_time+max.BT)+"]");
                max.CT=curr_time+max.BT;
                curr_time=curr_time+max.BT;
                rq.remove(max);
            }
        }
    }
    
    public void calTAT(Process[] p,int size){
        for(int i=0;i<size;i++){
            p[i].TAT=p[i].CT-p[i].AT;
        }
    }
    
    public void calWT(Process[] p,int size){
        for(int i=0;i<size;i++){
            p[i].WT=p[i].TAT-p[i].BT;
        }
    }
    
    public void AvgTAT(Process[] p,int size){
        double totalTAT=0;
        for(int i=0;i<size;i++){
            totalTAT+=p[i].TAT;
        }
        System.out.println("Avg TAT="+((double)totalTAT/size));
    }
    
    public void AvgWT(Process[] p,int size){
        double totalWT=0;
        for(int i=0;i<size;i++){
            totalWT+=p[i].WT;
        }
        System.out.println("Avg WT="+((double)totalWT/size));
    }
    
    public static void main(String[] args){
        NPPS obj=new NPPS();
        System.out.println("Enter number of Processes:");
        //int n=Process.sc.nextInt();
        int n=5;
        
        //input
//        for(int i=0;i<n;i++){
//            obj.p[i]=new Process();
//            obj.p[i].getPdata(i);
//        }
        
        //Process Data  pid,AT,BT,Prio
        obj.p[0]=new Process(1,0,4,2);
        obj.p[1]=new Process(2,1,3,3);
        obj.p[2]=new Process(3,2,1,4);
        obj.p[3]=new Process(4,3,5,5);
        obj.p[4]=new Process(5,4,2,5);
        
        //disp
        for(int i=0;i<n;i++){
            obj.p[i].dispP();
        }
        
        obj.ganttChart(obj.p,n);
        
        //disp
        for(int i=0;i<n;i++){
            obj.p[i].dispP();
        }
        
        obj.calTAT(obj.p,n);
        obj.calWT(obj.p,n);
        obj.AvgTAT(obj.p,n);
        obj.AvgWT(obj.p,n);
    }
}
