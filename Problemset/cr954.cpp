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

// X Axis
// void solve(){
//     vector<int> v(3);
//     cin>>v[0]>>v[1]>>v[2];
//     sort(v.begin(),v.end());
//     int ans = abs(v[0]-v[1]) + abs(v[1]-v[2]);
//     cout<<ans<<endl;
// }

// Matrix Stabilization
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> v(n,vector<int> (m,0));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cin>>v[i][j];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             vector<int> dx = {0,1,0,-1};
//             vector<int> dy = {1,0,-1,0};
//             int _max = 0;
//             for(int k=0;k<4;k++){
//                 int nx = i+dx[k];
//                 int ny = j+dy[k];
//                 if(nx>=0 && nx<n && ny>=0 && ny<m) _max = max(_max,v[nx][ny]);
//             }
//             if(_max==0) continue;
//             if(v[i][j]>_max) v[i][j] = _max;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cout<<v[i][j]<<" ";
//         cout<<endl;
//     }
// }

// Update Queries
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     string s,c;cin>>s;
//     int arr[m];
//     for(int i=0;i<m;i++) cin>>arr[i];
//     cin>>c;
//     set<int> st;
//     for(int i=0;i<m;i++) st.insert(arr[i]);
//     sort(c.begin(),c.end());
//     int len = 0;
//     for(int ele : st){
//         s[--ele] = c[len];
//         len++;
//     }
//     cout<<s<<endl;
// }

// Mathematical Problem
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     for(int i=0;i<n;i++){
//         if(s[i] == '0' && n>3){
//             cout<<0<<endl;
//             // cout<<"*"<<endl;
//             return;
//         }
//     }
//     if(n==3){
//         if(s[0] == '0' || s[2] == '0'){
//             cout<<0<<endl;
//             return;
//         }
//     }
//     if(n==2){
//         cout<<(s[0]-'0')*10 + (s[1]-'0')<<endl;
//         return;
//     }

//     // using the brute force
//     vector<int> number;
//     for(int i=0;i<n;i++) number.push_back(s[i] - '0');
    
//     int ans = INT_MAX;
//     for(int i=0;i<n-1;i++){
//         int num = (s[i] - '0')*10 + (s[i+1]-'0');
//         int temp = 0;
//         for(int j=0;j<n;j++){
//             if(j==i){
//                 if(num != 1) temp += num;
//                 j++;
//             }else{
//                 int req = s[j] - '0';
//                 if(req != 1) temp += req;
//             }
//         }
//         ans = min(ans,temp);
//     }
//     if(ans == 0){
//         for(int i=0;i<n;i++){
//             if(s[i] != '0'){
//                 ans = 1;
//                 break;
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

// Beautiful Array
void solve(){
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    map<int,vector<int>> m;
    for(int i=0;i<n;i++) m[arr[i]%k].push_back(i);

    // debug
    // for(auto ele : m){
    //     cout<<ele.first<<" : ";
    //     for(int ind : ele.second) cout<<arr[ind]<<" ";
    //     cout<<endl;
    // }

    int diff = 0,ans = 0;
    for(auto & ele : m){
        int sz = ele.second.size();
        diff += sz%2;
        if(sz==1) continue;
        vector<int> temp;
        for(int i=0;i<sz;i++) temp.push_back(arr[ele.second[i]]);
        sort(temp.begin(),temp.end());
        // for(int ele : temp) cout<<ele<<" ";
        // cout<<endl;
        int local1 = 0,local2 = INT_MAX;
        for(int i=1;i<sz;i+=2) local1 += abs(temp[i]  - temp[i-1])/k;
        
        // calculating th prefix diff
        vector<int> prefix(sz+1),suffix(sz+2);
        prefix[0] = 0,suffix[sz+1] = 0;
        for(int i=1;i<sz;i+=2){
            prefix[i] = prefix[i-1] + (temp[i]-temp[i-1])/k;
            prefix[i+1] = prefix[i];
        }
        for(int i=sz;i>1;i-=2){
            suffix[i] = suffix[i+1] + (temp[i-1]-temp[i-2])/k;
            suffix[i-1] = suffix[i];
        }
        for(int i=1;i<=sz;i+=2){
            local2 = min(prefix[i-1]+suffix[i+1],local2);
        }
        // for(int i=1;i<=sz;i++) cout<<prefix[i]<<" ";
        // cout<<endl;
        // cout<<local1<<" "<<local2<<endl;
        ans += min(local1,local2); 
    }
    if(diff>(n%2)){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
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