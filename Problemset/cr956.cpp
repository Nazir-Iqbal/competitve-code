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

// Array Divisibility
// void solve(){
//     int n;cin>>n;
//     for(int i=1;i<=n;i++) cout<<i<<" ";
//     cout<<endl;
// }

// Corner Twist
// void print(vector<vector<int>> &a){
//     int n = a.size(),m = a[0].size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cout<<a[i][j]<<" ";
//         cout<<endl;
//     }
//     cout<<endl;
// }

// Have Your Cake and Eat It Too
// void solve(){
//     int n;cin>>n;
//     int sum1 = 0,sum2 = 0,sum3 = 0;
//     int arr[n][3];
//     for(int i=0;i<n;i++) cin>>arr[i][0],sum1+=arr[i][0];
//     for(int i=0;i<n;i++) cin>>arr[i][1],sum2+=arr[i][1];
//     for(int i=0;i<n;i++) cin>>arr[i][2],sum3+=arr[i][2];
//     vector<int> tot(3);
//     tot[0] = sum1/3 , tot[1] = sum2/3 , tot[2] = sum3/3;
//     if(sum1%3!=0) tot[0]++;
//     if(sum2%3!=0) tot[1]++;
//     if(sum3%3!=0) tot[2]++;

//     // cout<<tot[0]<<" "<<tot[1]<<" "<<tot[2]<<endl;

//     vector<int> permu = {0,1,2};
//     do{
//         int sum0 = 0,sum1 = 0,sum2 = 0;
//         for(int i=0;i<n;i++){
//             sum0 += arr[i][permu[0]];
//             if(sum0>=tot[permu[0]]){
//                 for(int j=i+1;j<n;j++){
//                     sum1 += arr[j][permu[1]];
//                     if(sum1>=tot[permu[1]]){
//                         for(int k=j+1;k<n;k++){
//                             sum2 += arr[k][permu[2]];

//                             if(sum2>=tot[permu[2]]){
//                                 // cout<<sum0<<" "<<sum1<<" "<<sum2<<endl;
//                                 // cout<<i<<" "<<j<<" "<<k<<endl;
//                                 vector<pair<int,pair<int,int>>> vp;
//                                 vp.push_back({permu[0],{1,i+1}});
//                                 vp.push_back({permu[1],{i+2,j+1}});
//                                 vp.push_back({permu[2],{j+2,k+1}});
//                                 sort(vp.begin(),vp.end());
//                                 for(int i=0;i<3;i++) cout<<vp[i].second.first<<" "<<vp[i].second.second<<" ";
//                                 cout<<endl;
//                                 return;
//                             }

//                         }
//                         break;
//                     }
//                 }
//                 break;
//             }
//         }

//     }while(next_permutation(permu.begin(),permu.end()));
//     cout<<-1<<endl;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> a(n,vector<int>(m)),b(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         string s;cin>>s;
//         for(int j=0;j<m;j++) a[i][j] = s[j] - '0';
//     }
//     for(int i=0;i<n;i++){
//         string s;cin>>s;
//         for(int j=0;j<m;j++) b[i][j] = s[j] - '0';
//     }
//     //  converting a to b
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<m-1;j++){
//             if(a[i][j] == b[i][j]) continue;
//             int con = (3 + (b[i][j]-a[i][j]))%3;
//             int anti = 3-con;
//             a[i][j] = (a[i][j]+con)%3;
//             a[i+1][j+1] = (a[i+1][j+1] +con)%3;
//             a[i+1][j] = (a[i+1][j] + anti)%3;
//             a[i][j+1] = (a[i][j+1] + anti)%3;
//             // print(a);
//         }
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(a[i][j] != b[i][j]){
//                 cout<<"NO"<<endl;
//                 return;
//             }
//         }
//     }
//     cout<<"YES"<<endl;
// }


// Swap Dilemma
vector<int> a,b;
void merge(int l,int r,int mid,int &inv,vector<int> &a){
    vector<int> temp;
    int left = l;
    int right = mid+1;

    while(left<=mid && right<=r){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }else{
            temp.push_back(a[right]);
            inv += (mid-left+1);
            right++;
        }
    }
    while(left<=mid) temp.push_back(a[left]),left++;
    while(right<=r) temp.push_back(a[right]),right++;

    for(int i=l;i<=r;i++) a[i] = temp[i-l];
}

void mergesort(int l,int r,int &inv,vector<int> &a){
    // base case
    if(l>=r) return ;

    int mid = (l+r)/2;

    mergesort(l,mid,inv,a);
    mergesort(mid+1,r,inv,a);

    merge(l,r,mid,inv,a);

}

void solve(){
    int n;cin>>n;
    a.resize(n),b.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int inva = 0,invb = 0;
    mergesort(0,n-1,inva,a);
    mergesort(0,n-1,invb,b);

    for(int i=0;i<n;i++){
        if(a[i] != b[i]){
            cout<<"No"<<endl;
            return;
        }
    }

    // cout<<invb<<endl;
    // for(int i=0;i<n;i++) cout<<b[i]<<" ";
    // cout<<endl;

    if((inva&1) == (invb&1)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

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