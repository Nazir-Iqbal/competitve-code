#include<bits/stdc++.h>
using namespace std;

int SIZE = 10;

class ticket{
    string regno;
    string color;
    int slot;

    public:
        // default constructor
        ticket(){
            regno = "";
            color = "";
            slot = 0;
        }

        // parametrised constructor
        ticket(string regno,string color,int slot){
            this->regno = regno;
            this->color = color;
            this->slot = slot;
        }

        void set_regno(string regno){
            this->regno = regno;
        }

        void set_color(string color){
            this->color = color;
        }

        void set_slot(int slot){
            this->slot = slot;
        }

        vector<string> get(){
            vector<string> details = {regno,color,to_string(slot)};
            return details;
        }
    
};

class parking{
    int n;
    vector<bool> allocated;
    map<string,int> mp;
    vector<ticket> area;

    public:
        parking(int n){
            this->n = n;
            area.resize(n+1);
            allocated.resize(n+1);
        }

        void set_size(int n){
            area.resize(n+1);
            allocated.resize(n+1);
            for(int i=0;i<=n;i++) allocated[i] = 0;
        }

        int park(string regno,string color){
            int num = -1;
            for(int i=1;i<=n;i++){
                if(allocated[i] == 0){
                    num = i;
                    break;
                }
            }
            if(num == -1) return 0;
            
            ticket t1(regno,color,num);
            area[num] = t1;
            allocated[num] = 1;
            mp[regno] = num;
            return num;
        }

        void leave(int ind){
            allocated[ind] = 0;
        }

        string find_regno(int ind){
            if(ind<1 && ind>n) return "Invalid Input";

            if(!allocated[ind]) return "Empty";

            vector<string> req = area[ind].get();
            return req[0];
        }

        int find_parking_no(string regno){
            if(mp.find(regno) == mp.end()) return -1;

            int num = mp[regno];

            return num;
        }

        vector<bool> get_status(){
            return allocated;
        }

        vector<ticket> find_all(){
            return area;
        }
};

void print(vector<ticket> &t1,parking &nazir_parking){
    vector<bool> status = nazir_parking.get_status();
    for(int i=1;i<t1.size();i++){
        if(status[i]){
            vector<string> v1 = t1[i].get();
            cout<<v1[0]<<" "<<v1[1]<<" "<<v1[2]<<endl; 
        }
    }
}

void execution(){

    bool flag = false;
    parking nazir_parking(SIZE);
    
    int tt = 100000;
    while(tt--){
        string command;
        cin>>command;
        // cout<<command<<endl;
        if(command == "create_parking_lot"){
            int n;cin>>n;
            if(n<=0 || n>1e5){
                cout<<"The size of the parking is Invalid"<<endl;
                continue;
            }
            flag=true;
            // initialize the parking area
            nazir_parking.set_size(n);
        }else{
            if(!flag){
                string temp;
                getline(cin,temp);
                cout<<"Please create the parking area"<<endl;
                if(command == "Exit"){
                    break;
                }
            }else{
                if(command == "park"){

                    string regno,color;
                    cin>>regno>>color;
                    int parking_no = nazir_parking.park(regno,color);
                    if(parking_no) cout<<"Allocated slot number: "<<parking_no<<endl;
                    else cout<<"Sorry, parking lot is full"<<endl;

                }else if(command == "leave"){
                    int num;
                    cin>>num;
                    nazir_parking.leave(num);
                    cout<<"Slot number "<<num<<" is free"<<endl;

                }else if(command == "status"){

                    vector<ticket> t1 = nazir_parking.find_all();

                    print(t1,nazir_parking);

                }else if(command == "slot_number_for_registration_number"){
                    string regno;
                    cin>>regno;
                    int num = nazir_parking.find_parking_no(regno);

                    if(num == -1) cout<<"Not found"<<endl;
                    else cout<<num<<endl;

                }else if(command == "Exit"){
                    break;
                }else{
                    // cout<<command<<endl;
                    cout<<"Enter the valid command"<<endl;

                }
            }
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    execution();

    return 0;
}