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
//     int n,a,b;
//     cin>>n>>a>>b;
//     int p1 = (n/2)*b + (n%2)*a;
//     int p2 = n*a;
//     cout<<min(p1,p2)<<nline;
// }

// Progressive Square
// void solve(){
//     int n,c,d;
//     cin>>n>>c>>d;
//     int arr[n*n];
//     int len = n*n;
//     for(int i=0;i<n*n;i++) cin>>arr[i];
//     int _min = *min_element(arr,arr+len);
//     multiset<int> s;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             int num = _min + i*c + j*d;
//             s.insert(num);
//         }
//     }
//     for(int i=0;i<n*n;i++){
//         if(s.find(arr[i]) == s.end()){
//             cout<<"No"<<endl;
//             return;
//         }
//         s.erase(s.find(arr[i]));
//     }
//     cout<<"Yes"<<endl;
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
//             if(k>=arr[l]) ans++;
//             break;
//         }
//         if(arr[l]==arr[r]){
//             int req = 2*arr[l];
//             if(k>=req){
//                 k-=req;
//                 ans+=2;
//                 l++,r--;
//             }else if(k==req-1){
//                 ans++;
//                 break;
//             }else break;
//         }else if(arr[l] > arr[r]){
//             int req = 2*arr[r];
//             if(k>=req){
//                 k-=req;
//                 arr[l]-=arr[r];
//                 ans++;
//                 r--;
//             }else break;
//         }else{
//             int req = 2*arr[l];
//             if(k>=req){
//                 k-=req;
//                 arr[r]-=arr[l];
//                 ans++;
//                 l++;
//             }else if(k==req-1){
//                 ans++;
//                 break;
//             }else break;
//         }
//         // cout<<l<<" "<<r<<" "<<k<<endl;
//     }
//     cout<<ans<<endl;
// }

// Inaccurate Subsequence Search
// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<int> a(n),b(n);
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<m;i++) cin>>b[i];
//     map<int,int> m1,m2;
//     for(int i=0;i<m;i++) m1[b[i]]++;
//     int l=0,r=0;
//     int eq = 0,ans = 0;
//     while(r<n){
//         m2[a[r]]++;
//         if(m1.find(a[r])!=m1.end()){
//             if(m2[a[r]]<=m1[a[r]]) eq++;
//         }
//         if(r-l+1==m){
//             if(eq>=k) ans++;
//             m2[a[l]]--;
//             if(m2[a[l]]<m1[a[l]]) eq--;
//             l++;
//         }
//         r++;
//     }
//     cout<<ans<<nline;
// }

// Long Inversions
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    // checking for all the possivble sizes
    int ans = 1;
    for(int i=n;i>1;i--){
        vector<int> flick(n+1,0);
        int sum = 0;
        for(int j=0;j<=n-i;j++){
            sum+=flick[j];
            if(s[j] == '0'){
                if(sum==0 || sum%2==0) flick[j]++,flick[j+i]--,sum++;
            }else{
                if(sum&1) flick[j]++,flick[j+i]--,sum++;
            }
        }
        for(int j=1;j<n;j++) flick[j] += flick[j-1];
        // cout<<i<<endl;
        // for(int j=0;j<n;j++) cout<<flick[j]<<" ";
        // cout<<endl;
        bool flag = true;
        for(int j=0;j<n;j++){
            if(s[j] == '0' && flick[j]%2==0){
                flag = false;
                break;
            }else if(s[j] == '1' && flick[j]&1){
                flag = false;
                break;
            }
        }
        if(flag){
            ans = i;
            break;
        }
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