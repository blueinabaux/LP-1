#include<iostream>
using namespace std;

class Process{
    public:
        int id;
        string pname;

        Process(){
            id = 0;
            pname = "";
        }
};

class Election{

    Process proc[10];
    bool isCrashed[10];
    int num;

    public:

        void inputProcesses(){
            cout<<"Enter the number of Processes: ";
            cin>>num;

            for(int i=0;i<num;i++){
                cout<<"Enter Process ID: ";
                cin>>proc[i].id;
                cout<<"Enter Process Name: ";
                cin>>proc[i].pname;
                cout<<endl;
            }

        }

        void crashHighestProcess(){
            int highestIndex = 0;

            for(int i=0;i<num;i++){
                if(proc[i].id > proc[highestIndex].id){
                    highestIndex = i;
                }
            }
            isCrashed[highestIndex] = true;
            cout<<"Process "<<proc[highestIndex].pname<<" with ID: "<<proc[highestIndex].id<<" has crashed !"<<endl;
        }

        void bullyAlgo(int init_id){
            int max_id = init_id;

            for(int i=0;i<num;i++){

                if(proc[i].id > init_id && !isCrashed[i]){
                    cout<<"Message for Election was sent to Process: "<<proc[i].pname<<endl;

                    if(proc[i].id > max_id){
                        max_id = proc[i].id;
                    }
                }
            }

            cout<<"New co-ordinator is: "<<max_id<<endl;
        }


        void ringAlgo(int init_id){

            int start_index = -1;

            for(int i=0;i<num;i++){
                if(proc[i].id == init_id){
                    start_index = i;
                    break;
                }
            }

            int max_id = init_id;
            
            for(int i=0;i<num;i++){

                int index = (start_index + i) % num;

                if(!isCrashed[i]){
                    if (proc[index].id > max_id) {
                        max_id = proc[index].id;
                    }
                }
            }
            
            cout<<"New co-ordinator is: "<<max_id<<endl;
        }
};


int main(){

    Election election;

    election.inputProcesses();
    election.crashHighestProcess();

    int init_id;
    cout<<"Enter the initiator ID which recognized the crash: ";
    cin>>init_id;

    cout<<endl;

    int choice;

    do
    {
        cout<<"1. Bully Algorithm\n2. Ring Algorithm\n3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            election.bullyAlgo(init_id);
            break;
        case 2:
            election.ringAlgo(init_id);
            break;
        case 3:
            cout<<"Exiting...";
            break;
        default:
            break;
        }

    } while (choice != 3);
    




    return 0;
}