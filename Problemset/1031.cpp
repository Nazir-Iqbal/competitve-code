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

// void solve(){
//     int k,a,b,x,y;
//     cin>>k>>a>>b>>x>>y;
//     int ans = 0;
//     if(x<=y){
//         int left = (k-a+1);
//         int cnt = 0;
//         if(left >  0){
//             ans += (left+x-1)/x;
//         }
//         k -= x*ans;
//         left = (k-b+1);
//         if(left > 0){
//             ans += (left+y-1)/y;
//         }
//     }else{
//         int left = (k-b+1);
//         int cnt = 0;
//         if(left >  0){
//             ans += (left+y-1)/y;
//         }
//         k -= y*ans;
//         left = (k-a+1);
//         if(left > 0){
//             ans += (left+x-1)/x;
//         }
//     }
//     cout<<ans<<endl;

// }

// int n,m,w,h;
// int x1c,y1c,x2c,y2c;
// int x1d,y1d,x2d,y2d;

// bool xov(){
//     if(x1c == x2c) return true;

//     if(x1c > x2c){
//         return x2d > x1c;
//     }
//     if(x2c > x1c){
//         return x1d > x2c;
//     }
//     return false;
// }

// bool yov(){

//     if(y1c == y2c) return true;

//     if(y1c > y2c){
//         return y2d > y1c;
//     }
//     if(y2c > y1c){
//         return y1d > y2c;
//     }
//     return false;
// }

// void solve(){
//     cin>>n>>m>>w>>h;
//     cin>>x1c>>y1c>>x2c>>y2c;
//     x1d = x1c + w;
//     x2d = x2c + w;
//     y1d = y1c + h;
//     y2d = y2c + h;

//     // cout<<x1c<<" "<<y1c<<" "<<x1d<<" "<<y1d<<endl;
//     // cout<<x2c<<" "<<y2c<<" "<<x2d<<" "<<y2d<<endl;

//     int diffx = -1,diffy = -1;
//     if(xov()){
//         if(y1c > y2c) diffy = y1c - y2d;
//         else diffy = y2c - y1d;
//         if(diffy % h == 0) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }else if(yov()){
//         if(x1c > x2c) diffx = x1c - x2d;
//         else diffx = x2c - x1d;
//         if(diffx % w == 0) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }else{
//         // cout<<"*"<<endl;
//         if(y1c > y2c) diffy = y1c - y2d;
//         else diffy = y2c - y1d;
//         if(x1c > x2c) diffx = x1c - x2d;
//         else diffx = x2c - x1d;

//         // cout<<diffx<<" "<<diffy<<endl;

//         if(diffx % w == 0 || diffy % h == 0) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }

// void solve(){
//     int w,h,a,b;
//     int x1,y1,x2,y2;
//     cin>>w>>h>>a>>b;
//     cin>>x1>>y1>>x2>>y2;
//     if(x1==x2){
//         if( (y2-y1)%b == 0) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//         return;
//     }
//     if(y1==y2){
//         if((x2-x1)%a == 0) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//         return;
//     }

//     if( (x2-x1)%a==0 || (y2-y1)%b==0) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

//  Smilo and Minecraft
// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<vector<char>>  vc(n,vector<char>(m));
//     for(int i=0;i<n;i++){
//         string s;cin>>s;
//         for(int j=0;j<m;j++){
//             vc[i][j] = s[j];
//         }
//     }

//     vector<vector<int>> arr(n+2*k,vector<int>(m+2*k,0));
//     vector<vector<int>> prefix(n+2*k,vector<int>(m+2*k,0));
//     int total = 0;
//     for(int i=k;i<k+n;i++){
//         for(int j=k;j<k+m;j++) arr[i][j] = (vc[i-k][j-k] == 'g')?1:0;
//     }
    
//     // cout<<"*"<<endl;
//     for(int i=1;i<n+2*k;i++){
//         for(int j=1;j<m+2*k;j++){
//             total += arr[i][j];
//             prefix[i][j] = arr[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
//         }
//     }
//     int lost = INT_MAX;
//     bool blast = false;
//     for(int i=k;i<k+n;i++){
//         for(int j=k;j<k+m;j++){
//             if(vc[i-k][j-k] == '.'){
//                 blast = true;
//                 int temp = prefix[i+k-1][j+k-1] - prefix[i-k][j+k-1] - prefix[i+k-1][j-k] + prefix[i-k][j-k];
//                 lost = min(lost,temp);
//             }
//         }
//     }

//     cout<<total-lost<<endl;
// }

// Cheater
bool check(int n,int k,vector<int> a,vector<int> &b){
    int ind1 = k-1,ind2 = n-k;
    int _min = INT_MAX;
    for(int i=0;i<k;i++) _min = min(_min,a[i]);
    int _max = INT_MIN;
    for(int i=k;i<n;i++) _max = max(_max,a[i]);
    if(_min < _max){
        for(int i=0;i<k;i++){
            if(a[i] == _min){
                a[i] = _max;
                break;
            }
        }
    }
    int l = 0,r = 0;
    while(l<=ind1){
        if(r > ind2) return false;
        if(a[l] > b[r]) l++;
        else r++;
    }
    return true;
}

void solve(){
    int n;cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int l=1,r=n;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(n,mid,a,b)) l = mid+1;
        else r = mid-1;
    }
    cout<<r<<endl;
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