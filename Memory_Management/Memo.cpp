#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void firstFit(int nb, int boxCap[], int ni, int iSize[], int allocation[]){

    for(int i=0;i<ni;i++){
        for(int j=0;j<nb;j++){
            if(boxCap[j] >= iSize[i]){
                boxCap[j] -= iSize[i];
                allocation[i] = j+1;
                break;
            }
        }
    }
}

void bestFit(int nb, int boxCap[], int ni, int iSize[], int allocation[]){

    for(int i=0;i<ni;i++){

        int bestIndex = -1;

        for(int j=0;j<nb;j++){
            if(boxCap[j] >= iSize[i] && (bestIndex == -1 || boxCap[bestIndex] > boxCap[j])){
                bestIndex = j;

            }
        }

        if(bestIndex != -1){
            boxCap[bestIndex] -= iSize[i];
            allocation[i] = bestIndex+1;
            break;

        }
        else{
            allocation[i] = -1;
        }
    }
}

void worstFit(int nb, int boxCap[], int ni, int iSize[], int allocation[]){

    for(int i=0;i<ni;i++){

        int worstIndex = -1;

        for(int j=0;j<nb;j++){
            if(boxCap[j] >= iSize[i] && (worstIndex == -1 || boxCap[worstIndex] < boxCap[j])){
                worstIndex = j;
            }
        }

        if(worstIndex != -1){
            boxCap[worstIndex] -= iSize[i];
            allocation[i] = worstIndex+1;
            break;
        }
        else{
            allocation[i] = -1;
        }
    }
}


void nextFit(int nb, int boxCap[], int ni, int iSize[], int allocation[]){

    int j=0;
    for(int i=0;i<ni;i++){

        int start = j;

        while (true){
            if(boxCap[j] >= iSize[i]){
                boxCap[j] -= iSize[i];
                allocation[i] = j+1; 
                break;
            }
            
            j = (j+1) % nb;
            if (j == start) break;
        }
    }
}

void displayAllocation(int ni, int iSize[], int allocation[]){
    cout<<"ITEM\tSIZE\tALLOCATION\n";
    for(int i=0;i<ni;i++){
        cout<<i+1<<"\t"<<iSize[i]<<"\t";
        if(allocation[i] != -1){
            cout<<"Box "<<allocation[i];
        }
        else{
            cout<<"Not allocated";
        }
        cout<<endl;
    }
}


void resetBox(int nb, int boxCap[], int ogBoxCap[]){
    for(int i=0;i<nb;i++){
        boxCap[i] = ogBoxCap[i];
    }
}



int main(){

    int nb, ni;
    cout<<"Enter the number of Boxes: ";
    cin>>nb;

    int boxCap[nb], ogBoxCap[nb];

    for(int i=0;i<nb;i++){
        cout<<"Enter the Capacity of Box "<<i+1<<": ";
        cin>>boxCap[i];
        ogBoxCap[i] = boxCap[i];
    }

    cout<<"Enter the number of Items: ";
    cin>>ni;

    int iSize[ni], allocation[ni];
    for(int i=0;i<ni;i++){
        cout<<"Enter the Size of Item "<<i+1<<": ";
        cin>>iSize[i];
        allocation[i] = -1;
    }

    int choice;

    do
    {
        resetBox(nb,boxCap, ogBoxCap);

        cout<<"\n1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Next Fit\n5.Exit Program\n";
        cout<<"Enter the Choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            firstFit(nb, boxCap, ni, iSize, allocation);
            break;
        case 2:
            bestFit(nb, boxCap, ni, iSize, allocation);
            break;
        case 3:
            worstFit(nb, boxCap, ni, iSize, allocation);
            break;
        case 4:
            nextFit(nb, boxCap, ni, iSize, allocation);
            break;
        case 5:
            cout<<"Exiting..."<<endl;
            break;
        default:
            break;
        }
        displayAllocation(ni,iSize, allocation);
    } while (choice != 5);
    

    

    return 0;
}