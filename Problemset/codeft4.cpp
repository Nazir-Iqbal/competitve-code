#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     int cap = 0,sum = 0;
//     for(int i=0;i<n;i++) cin>>arr[i];
//     for(int i=0;i<n;i++){
//         cap = __gcd(cap,arr[i]);
//         sum += arr[i];
//     }
//     int ans = sum/cap;
//     cout<<ans<<nline;
// }

// Ticket Counter
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     queue<int> q;
//     multiset <int> s;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         q.push(arr[i]);
//         s.insert(arr[i]);
//     }
//     int time = 1;
//     vector<int> ans;
//     while(s.size()!=0){
//         ans.push_back(s.size());
//         while(!q.empty()){
//             // cout<<q.front()<<nline;
//             if(q.front()<time) q.pop();
//             else break;
//         }
//         if(!q.empty()){
//             s.erase(s.find(q.front()));
//             q.pop();
//         }
//         s.erase(time);
//         time++;
//     }
//     ans.push_back(0);
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// wEIRD sORT
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     vector<int> pos(n+1,0);
//     for(int i=0;i<n;i++) cin>>arr[i],pos[arr[i]]=i;
//     int seg = 1;
//     for(int i=0;i<n-1;i++){
//         if(arr[i+1]-arr[i] != 1) seg++;
//     }
//     // cout<<seg<<endl;
//     int com = 0;
//     for(int i=1;i<n;i++){
//         if(pos[i+1]>pos[i]+1){
//             int l = pos[i],r = pos[i+1];
//             // cout<<l<<" "<<r<<nline;
//             bool flag = true;;
//             for(int j=l;j<=r;j++){
//                 if(arr[j]>i+1){
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag) com++;
//         }
//     }
//     cout<<seg-com<<nline;
// }

// wEIRDER sORT
const int N = 1e6+7;

void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    vector<int> cage(N,0),hsn(N,0);
    for(int i=0;i<n;i++) cin>>arr[i],hsn[arr[i]]++;
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            cage[i] += hsn[j];
        }
    }
    map<int,set<int>> m;
    for(int i=1;i<N;i++){
        m[cage[i]].insert(i);
    }

    while(q--){
        int k,l,r;
        cin>>k>>l>>r;
        if(m.find(k)==m.end()){
            cout<<-1<<" ";
            continue;
        }
        auto num = m[k].lower_bound(l);
        if(num == m[k].end()){
            cout<<-1<<" ";
            continue;
        }
        if((*num)>r){
            cout<<-1<<" ";
            continue;
        }
        cout<<(*num)<<" ";
    }
    cout<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}