#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

vector<int> convert(string &str){
    vector<int>arr;
    int temp = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]==','){
            arr.push_back(temp);
            temp = 0;
        }else{
            temp*=10;
            temp+=(str[i]-'0');
        }
    }
    arr.push_back(temp);
    return arr;
}

void solve(){
    string str;cin>>str;
    getline(cin,str);
    vector<int> arr = convert(str);
    int n=  arr.size();
    vector<bool> hsn(n,0);
    int cur = 0,prev = 0;
    while(cur<n){
        if(arr[cur]<prev){
            prev = arr[cur];
            cur -=arr[cur];
            if(cur<0 || hsn[cur]){
                cout<<"No"<<endl;
                return;
            }
            hsn[cur] = 1;
        }else{
            prev = arr[cur];
            cur += arr[cur];
            hsn[cur] = 1;
        }
    }
    cout<<"Yes"<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}