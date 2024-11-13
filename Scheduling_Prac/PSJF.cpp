#include<iostream>
#include<algorithm>
using namespace std;

class Process{

    public:
        int pid;
        int arrivalTime;
        int burstTime;
        int compTime;
        int tatTime;
        int waitTime;
};

void findPSJF(Process proc[], int n){

    int remainTime[n];

    for(int i=0;i<n;i++){
        remainTime[i] = proc[i].burstTime;
    }

    int currTime=0, completedTask = 0;
    int shortestTask = -1, minBurst = INT_MAX;

    while(completedTask < n){

        int shortestTask = -1, minBurst = INT_MAX;

        for(int i=0;i<n;i++){

            if(proc[i].arrivalTime <= currTime && remainTime[i] < minBurst && remainTime[i] > 0){
                minBurst = remainTime[i];
                shortestTask = i;
            }

        }

        if(shortestTask == -1){
            currTime++;
            continue;
        }

        remainTime[shortestTask] --;

        if(remainTime[shortestTask] == 0){
            completedTask++;
            proc[shortestTask].compTime = currTime +1;
            proc[shortestTask].tatTime = proc[shortestTask].compTime - proc[shortestTask].arrivalTime;
            proc[shortestTask].waitTime = proc[shortestTask].tatTime - proc[shortestTask].burstTime;

        }
        currTime++;
    }

}

void display(Process proc[], int n) {
    cout << "PID\tAT\tBT\tCOMP\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].arrivalTime << "\t" << proc[i].burstTime << "\t" 
             << proc[i].compTime << "\t" << proc[i].tatTime << "\t" << proc[i].waitTime << "\n";
    }
}

int main(){

    Process proc[] = {
        
    // pid, AT, BT
        {1, 0, 2},
        {2, 3, 5},
        {3, 2, 3}
    };

    int n = sizeof(proc) / sizeof(proc[0]);

    findPSJF(proc, n);
    display(proc, n);



    return 0;
}
