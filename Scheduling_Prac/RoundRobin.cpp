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

void calcTime(Process proc[], int n, int q){

    int remainTime[n];
    for(int i=0;i<n;i++){
        remainTime[i] = proc[i].burstTime;
    }

    int currTime = 0;
    bool allDone = false;

    while(!allDone){
        allDone = true;

        for(int i=0;i<n;i++){

            if(remainTime[i] > 0){
                allDone = false;

                if(remainTime[i] > q){
                    currTime += q;
                    remainTime[i] -= q;
                }
                else{
                    currTime += remainTime[i];
                    proc[i].compTime = currTime;
                    remainTime[i] = 0;
                }
            }
        }
    }
}

void findTAT(Process proc[], int n){
    for(int i=0;i<n;i++){
        proc[i].tatTime = proc[i].compTime - proc[i].arrivalTime;
    }
}

void findWT(Process proc[], int n){
    for(int i=0;i<n;i++){
        proc[i].waitTime = proc[i].tatTime - proc[i].burstTime;
    }
}

void display(Process proc[], int n){
    cout<<"PID\tAT\tBT\tCOMP\tTAT\tWT"<<endl;
    for(int i=0;i<n;i++){
        cout<<proc[i].pid<<"\t"<<proc[i].arrivalTime<<"\t"<<proc[i].burstTime<<"\t"<<proc[i].compTime<<"\t"<<proc[i].tatTime<<"\t"<<proc[i].waitTime<<endl;
    }
}

int main(){

    int n,q;
    cout<<"Enter the number of Processes: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the Time Quantum: ";
    cin>>q;

    Process proc[n];

    for(int i=0;i<n;i++){
        cout<<"Process "<<i+1<<endl;
        proc[i].pid = i+1;
        cout<<"Arrival Time: ";
        cin>>proc[i].arrivalTime;
        cout<<endl;
        cout<<"Burst Time: ";
        cin>>proc[i].burstTime;
        cout<<endl;
    }

    calcTime(proc,n,q);
    findTAT(proc,n);
    findWT(proc,n);

    cout<<"ROUND ROBIN TABLE: "<<endl;
    display(proc,n);
    
    return 0;
}