#include<iostream>
#include<algorithm>
using namespace std;

#define totalProcesses 4

class Process{

    public:
        int at, bt, prior, pno;
};

Process proc[50];

bool comp(Process a, Process b){
    if(a.at == b.bt){
        return a.prior < b.prior;
    }
    return a.at < b.at;
}

void calculateTime(){

    int completed=0,currTime=0;
    int stime[totalProcesses]={0},ctime[totalProcesses]={0};
    int tat[totalProcesses]={0}, wt[totalProcesses]={0};
    bool isCompleted[totalProcesses] = {false};
    double tat_avg=0, wt_avg=0;

    while(completed < totalProcesses){
        int index = -1;
        int higherPriority = 1000;

        for(int i=0;i<totalProcesses;i++){

            if(proc[i].at <= currTime && !isCompleted[i]){

                if(proc[i].prior < higherPriority){
                    higherPriority = proc[i].prior;
                    index = i;
                }

                else if(proc[i].prior < higherPriority){
                    if(proc[i].at < proc[index].at){
                        index = i;
                    }
                }
            }
        }

        if(index != -1){
            stime[index] = currTime;
            ctime[index] = stime[index] + proc[index].bt;
            tat[index] = ctime[index] - proc[index].at;
            wt[index] = tat[index] - proc[index].bt;

            tat_avg+=tat[index];
            wt_avg+=wt[index];

            currTime = ctime[index];
            isCompleted[index] = true;
            completed++;
        }
        else{
            currTime ++;
        }

    }
    cout << "ProcessNo\tStart_Time\tComplete_Time\tTAT\tWait_Time" << endl;

    for(int i=0;i<totalProcesses;i++){
        cout << proc[i].pno << "\t\t" << stime[i] << "\t\t" << ctime[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }

    cout << "Average Turnaround Time: " << tat_avg / totalProcesses << endl;
    cout << "Average Waiting Time: " << wt_avg / totalProcesses << endl;

}

int main(){

    int arrivalTime[] = {0, 1, 2, 3};
    int burstTime[] = {4, 2, 5, 1};
    int priority[] = {3, 4, 1, 2};

    for(int i=0;i<totalProcesses;i++){
        proc[i].at = arrivalTime[i];
        proc[i].bt = burstTime[i];
        proc[i].prior = priority[i];
        proc[i].pno = i+1;
    }

    sort(proc, proc+totalProcesses, comp);

    calculateTime();


    
    return 0;
}
