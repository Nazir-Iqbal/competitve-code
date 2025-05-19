#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Everything Nim
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     set<int> s;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         s.insert(arr[i]);
//     }
//     vector<int> un;
//     for(int ele : s) un.push_back(ele);
//     int len = un.size();
//     // the player who takes the control will win the game
//     if(len==1){
//         cout<<"Alice"<<endl;
//         return;
//     }
//     for(int i=0;i<len;i++){
//         if(i==0){
//             if(un[i]!=1){
//                 cout<<"Alice"<<endl;
//                 return;
//             }
//         }else{
//             int diff = un[i]-un[i-1];
//             if(diff!=1){
//                 if(i&1){
//                     cout<<"Bob"<<endl;
//                     return;
//                 }else{
//                     cout<<"Alice"<<endl;
//                     return;
//                 }
//             }
//         }
//     }
//     if((len-1)&1) cout<<"Bob"<<endl;
//     else cout<<"Alice"<<endl;
// }

// How Does the Rook Move?
// int mod = 1e9+7;

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<bool> row(n,0),col(n,0);
//     for(int i=0;i<k;i++){
//         int r,c;
//         cin>>r>>c;
//         r--,c--;
//         row[r] = 1,col[c] = 1;
//         if(row[c] || col[r]) continue;
//         else row[c]=1,col[r] = 1;
//     }
//     int free = 0;
//     for(int i=0;i<n;i++) if(row[i]==0) free++;
//     vector<int> dp(free+1,1);
//     for(int i=2;i<=free;i++) dp[i] = ((2*(i-1)*dp[i-2]) + dp[i-1])%mod;
//     cout<<dp[free]<<endl;
// }

// Nene's Magical Matrix
// void solve(){
//     int n;cin>>n;
//     int sum = 0;
//     for(int i=1;i<=n;i++) sum += (i*(2*(i-1)+1));
//     cout<<sum<<" "<<2*n<<endl;
//     for(int i=1;i<=n;i++){
//         cout<<2<<" "<<i<<" ";
//         for(int j=1;j<=n;j++) cout<<j<<" ";
//         cout<<endl;
//         int col = n-i+1;
//         cout<<1<<" "<<col<<" ";
//         for(int j=n;j>=1;j--) cout<<j<<" ";
//         cout<<endl;
//     }
// }

// Long Inversions
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int k = 1;
//     // we are greedily checking for window size i
//     for(int i=1;i<=n;i++){
//         vector<int> hsn(n+1,0);
//         bool flag = true;
//         for(int j=0;j<n;j++){
//             if(j!=0) hsn[j]+=hsn[j-1];
//             if(s[j]=='0' && (hsn[j]%2==0)){
//                 if(j+i<=n){
//                     hsn[j]++;
//                     hsn[j+i]--;
//                 }else{
//                     flag = false;
//                     break;
//                 }
//             }else if(s[j]=='1' && (hsn[j]&1)){
//                 if(j+i<=n){
//                     hsn[j]++;
//                     hsn[j+i]--;
//                 }else{
//                     flag = false;
//                     break;
//                 }
//             }
//         }
//         // cout<<i<<" : ";
//         // for(int ele : hsn) cout<<ele<<" ";
//         // cout<<endl;
//         if(flag) k = i;
//     }
//     cout<<k<<endl;
// }

// Inaccurate Subsequence Search
// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     int a[n],b[m];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int j=0;j<m;j++) cin>>b[j];
//     int l=0,r=0;
//     map<int,int> m1,m2;
//     for(int i=0;i<m;i++) m2[b[i]]++;
//     int ans = 0,cnt = 0;
//     while(r<n){
//         int temp = min(m1[a[r]],m2[a[r]]);
//         m1[a[r]]++;
//         int val = min(m1[a[r]],m2[a[r]]);
//         cnt += (val-temp);
//         // cout<<a[r]<<" "<<m1[a[r]]<<" "<<m2[a[r]]<<endl;
//         if(r-l+1==m){
//             if(cnt >= k) ans++;
//             temp = min(m1[a[l]],m2[a[l]]);
//             m1[a[l]]--;
//             val = min(m1[a[l]],m2[a[l]]);
//             cnt += (val-temp);
//             l++;
//         }
//         r++;
//     }
//     cout<<ans<<endl;
// }

// Inhabitant of the Deep Sea
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int l=0,r=n-1;
//     int ans = 0;
//     while(l<=r){
//         if(l==r){
//             k-=arr[l];
//             if(k>=0) ans+=1;
//             break;
//         }
//         if(arr[l]==arr[r]){
//             k-=2*arr[l];
//             if(k>=0) ans+=2;
//             else if(k==-1){
//                 ans+=1;
//                 break;
//             }
//             l++,r--;
//         }else if(arr[l]>arr[r]){
//             k-=2*arr[r];
//             arr[l]-=arr[r];
//             if(k>=0) ans+=1;
//             else break;
//             r--;
//         }else{
//             k-=2*arr[l];
//             arr[r]-=arr[l];
//             if(k>=0) ans+=1;
//             else{
//                 if(k==-1) ans++;
//                 break;
//             }
//             l++;
//         }
//     }
//     cout<<ans<<endl;
// }

// Ticket Hoarding
// void solve(){
//     int n,k,m;
//     cin>>n>>m>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<pair<int,int>> days;
//     for(int i=0;i<n;i++) days.push_back({arr[i],i});
//     sort(days.begin(),days.end());
//     int time = k/m;
//     if(k%m!=0) time++;
//     vector<pair<int,int>> sorter;
//     for(int i=0;i<time;i++) sorter.push_back({days[i].second,days[i].first});
//     sort(sorter.begin(),sorter.end());
//     vector<int>way;
//     for(int i=0;i<time;i++) way.push_back(sorter[i].second);
//     int ans = 0,cnt = 0;
//     int left = k%m,_max = *max_element(way.begin(),way.end());
//     for(int i=0;i<time;i++){
//         if(way[i]==_max){
//             if(left==0) ans +=(cnt+way[i])*m,cnt+=m;
//             else ans +=(cnt+way[i])*left,cnt+=left,left = 0;
//         }else ans += (cnt+way[i])*m,cnt+=m;
//     }
//     cout<<ans<<endl;
// }

// 0, 1, 2, Tree!
// void solve(){
//     int a,b,c;
//     cin>>a>>b>>c;
//     // if tree is possible 
//     if(c!=a+1){
//         cout<<-1<<endl;
//         return;
//     }
//     int h = log2(2*c-1);
//     int d = (1<<h);
//     d-=c;
//     b = max(b-d,0ll);
//     // taking ciel b/c
//     h += (b+c-1)/c;
//     cout<<h<<endl;
// }

// Nearly Shortest Repeating Substring
const int N = 2e5+7;
vector<int> factor[N];

void pre(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i) factor[j].push_back(i);
    }
}

bool check(int n,string s,int k){
    int cnt = 0;
    bool flg1 = true,flg2 =true;
    for(int i=0;i<k;i++){
        for(int j=i;j<n;j+=k){
            if(s[i]!=s[j]) cnt++;
        }
    }
    if(cnt>1) flg1 = false;
    cnt = 0;
    for(int i=n-1;i>n-1-k;i--){
        for(int j=i;j>=0;j-=k){
            if(s[i]!=s[j]) cnt++;
        }
    }
    if(cnt>1) flg2 = false;
    // cout<<k<<"*"<<flg1<<" "<<flg2<<endl;
    return flg1|flg2;
}

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int ans = n;
    check(n,s,10);
    for(int i=0;i<factor[n].size();i++){
        int k = factor[n][i];
        if(check(n,s,k)){
            ans = k;
            break;
        }
    }
    cout<<ans<<endl;
}

int32_t main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    FIO;
    pre();
    int t;cin>>t;
    while(t--){
      solve();
    }
    return 0;
}