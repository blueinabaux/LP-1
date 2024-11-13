#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void findCompTime(vector<int>&COMP, vector<int>&BT){

    COMP[0] = BT[0];
    for(int i=1;i<BT.size();i++){
        COMP[i] = COMP[i-1] + BT[i];
    }
}

void findTAT(vector<int>&TAT, vector<int>&COMP, vector<int>&AT){

    for(int i=0;i<AT.size();i++){
        TAT[i] = COMP[i] - AT[i];
    }
}

void findWT(vector<int>&WT, vector<int>&TAT, vector<int>&BT){

    for(int i=0;i<BT.size();i++){
        WT[i] = TAT[i] - BT[i];
    }
}



void avgTime(int n, vector<int>&PID , vector<int>AT, vector<int>&BT){
    vector<int>COMP(n);
    vector<int>TAT(n);
    vector<int>WT(n);

    findCompTime(COMP, BT);
    findTAT(TAT, COMP, AT);
    findWT(WT, TAT, BT);

    double total_TAT = 0;
    double total_WT = 0;

    cout<<"\nPID\tAT\tBT\tCOMP\tTAT\tWT\n";

    for(int i=0;i<n;i++){
        cout<<PID[i]<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"<<COMP[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<endl;

        total_TAT+=TAT[i];
        total_WT+=WT[i];
    }

    cout<<"Average TAT: "<<(total_TAT / n)<<endl;
    cout<<"Average WT: "<<(total_WT / n)<<endl;


}

int main(){

    vector<int>PID = {1,2,3};
    vector<int>AT = {0,1,2};
    vector<int>BT = {2,4,5};

    int n = PID.size();

    avgTime(n, PID, AT, BT);

    return 0;
}
