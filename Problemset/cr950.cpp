#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     string s;cin>>s;
//     int hsn[7] = {0};
//     for(int i=0;i<n;i++) hsn[s[i]-'A']++;
//     int ans = 0;
//     for(int i=0;i<7;i++){
//         if(hsn[i]<m) ans+= m-hsn[i];
//     }
//     cout<<ans<<endl;
// }

// Choosing Cubes
// void solve(){
//     int n,f,k;
//     cin>>n>>f>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int fav = arr[f-1];
//     sort(arr,arr+n,greater<int>());
//     int first = -1,last = -1;
//     for(int i=1;i<=n;i++){
//         if(arr[i-1] == fav){
//             if(first==-1) first = i;
//             last = i;
//         }
//     }

//     if(k>=last) cout<<"Yes"<<endl;
//     else if(k<first) cout<<"No"<<endl;
//     else cout<<"Maybe"<<endl;
// }

// Sofia and the Lost Operations
// void solve(){
//     int n;cin>>n;
//     int a[n+1],b[n+1];
//     for(int i=1;i<=n;i++) cin>>a[i];
//     for(int j=1;j<=n;j++) cin>>b[j];
//     int m;cin>>m;
//     int d[m+1];
//     for(int i=1;i<=m;i++) cin>>d[i];
//     map<int,int> count,ele,req;

//     for(int i=1;i<=m;i++) count[d[i]]++;
//     for(int i=1;i<=n;i++) ele[b[i]]++;

//     if(ele.find(d[m])==ele.end()){
//         cout<<"No"<<endl;
//         return;
//     }

//     for(int i=1;i<=n;i++){
//         if(a[i] != b[i]) req[b[i]]++;
//     }

//     for(auto item : req){
//         if(count.find(item.first) == count.end()){
//             cout<<"No"<<endl;
//             return;
//         }
//         if(item.second > count[item.first]){
//             cout<<"No"<<endl;
//             return;
//         }
//         count[item.first]-=item.second;
//     }
//     cout<<"Yes"<<endl;
// }

// GCD-sequence
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n==3){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     bool flag = true;
//     int mov = 0;
//     for(int i=0;i<n-2;i++){
//         int num1 = __gcd(arr[i],arr[i+1]);
//         int num2 = __gcd(arr[i+1],arr[i+2]);
//         if(num1>num2){
//             if(mov==0){
//                 if(i==n-3){
//                     break;
//                 }
//                 num2 = __gcd(arr[i+1],arr[i+3]);
//                 if(num1>num2){
//                     flag = false;
//                     break;
//                 }
//                 mov++;
//             }else{
//                 flag = false;
//                 break;
//             }
//         }
//     }
//     if(flag){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     flag = true;
//     mov = 0;
//     for(int i=n-1;i>1;i--){
//         int num1 = __gcd(arr[i],arr[i-1]);
//         int num2 = __gcd(arr[i-1],arr[i-2]);
//         if(num1<num2){
//             if(mov==0){
//                 if(i==2){
//                     break;
//                 }
//                 // cout<<"*"<<endl;
//                 num2 = __gcd(arr[i-1],arr[i-3]);
//                 if(num1<num2){
//                     flag = false;
//                     break;
//                 }
//                 mov++;
//             }else{
//                 flag = false;
//                 break;
//             }
//         }
//     }
//     if(flag){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     cout<<"No"<<endl;
// }

// bool check(vector<int> &v){
//     int n = v.size();
//     for(int i=0;i<n-1;i++){
//         if(v[i]>v[i+1]) return false; 
//     }
//     return true;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n==3){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     vector<int> gcd;
//     for(int i=0;i<n-1;i++){
//         gcd.push_back(__gcd(arr[i],arr[i+1]));
//     }
//     int cnt = 0;
//     bool istrue = true;
//     for(int i=0;i<n-2;i++){
//         if(gcd[i]>gcd[i+1]){
//             bool flag = false;
//             for(int j=i;j<=i+2;j++){
//                 vector<int> temp,temparr;
//                 for(int l=0;l<n;l++){
//                     if(l==j) continue;
//                     temparr.push_back(arr[l]);
//                 }
//                 for(int l=0;l<n-2;l++) temp.push_back(__gcd(temparr[l],temparr[l+1]));
//                 if(check(temp)){
//                     flag=true;
//                 }
//             }
//             if(flag) istrue = true;
//             else istrue = false;
//             break;
//         }
//     }
//     if(istrue) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// Permutation of Rows and Columns
void solve(){
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    int col = 0,row = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
            if(a[0][0] == b[i][j]){
                row = i;
                col = j;
            }
        }
    }
    int r[n],c[m];
    for(int i=0;i<n;i++) r[i] = i;
    for(int j=0;j<m;j++) c[j] = j;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][0] == b[j][col]){
                r[i] = j;
                break;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(a[0][i] == b[row][j]){
                c[i] = j;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[r[i]][c[j]]){;
                cout<<"No"<<nline;
                return;
            }
        }
    }
    // cout<<"*"<<endl;
    cout<<"Yes"<<nline;
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