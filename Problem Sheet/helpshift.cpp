#include <bits/stdc++.h>
using namespace std;
// string s1,s2;

// bool check(int ind,int n){
//     string t1,t2,t3,t4;
//     for(int i=0;i<=ind;i++) t1.push_back(s1[i]),t2.push_back(s2[i]);
//     for(int i=ind+1;i<n;i++) t3.push_back(s1[i]),t4.push_back(s2[i]);
//     sort(t1.begin(),t1.end());
//     sort(t2.begin(),t2.end());
//     sort(t3.begin(),t3.end());
//     sort(t4.begin(),t4.end());
//     if(t1==t2 && t3==t4) return true;
//     return false;
// }

// void solve(){
//     cin>>s1>>s2;
//     int n = s1.size();
//     if(s1.size()!=s2.size()){
//         cout<<"false"<<endl;
//         return;
//     }
//     if(s1==s2){
//         cout<<"true"<<endl;
//     }

//     for(int i=0;i<=n-2;i++){
//         if(check(i,n)){
//             cout<<"true"<<endl;
//             return;
//         }
//     }
//     cout<<"false"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n);
//     int ans = 0;
//     for(int i=1;i<n;i++) ans = max(ans,arr[i]-arr[i-1]);
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int ans = 0;
//     for(int i=1;i<=n;i++){
//         n-=i;
//         if(n<0) break;
//         ans = i;
//     }
//     cout<<ans<<endl;
// }

const int N = 1e5+7;
vector<int> hsn(N,0);
void solve(){
    int n;cin>>n;
    int x,y;cin>>x>>y;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        hsn[l]++,hsn[r+1]--;
    }
    for(int i=1;i<N;i++) hsn[i] += hsn[i-1];
    int ans = 0;
    for(int i=x;i<=y;i++) ans += hsn[i];
    cout<<ans<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    solve();
    return 0;
}