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

// void solve(){
//     int a,b;
//     cin>>a>>b;
//     cout<<(b-a)<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> ans;
//     for(int i=0;i<n;i++){
//         string s;cin>>s;
//         for(int j=0;j<4;j++){
//             if(s[j] == '#') ans.push_back(j+1);
//         }
//     }
//     reverse(ans.begin(),ans.end());
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// The Legend of Freya the Frog
// void solve(){
//     int x,y,k;
//     cin>>x>>y>>k;
//     int tx = x/k,ty = y/k;
//     if(x%k!=0) tx++;
//     if(y%k!=0) ty++;
//     int ans = max(2*(tx-1)+1,2*ty);
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> v1(n+2,0),v2(n+2,0);//,pr1(n+2,0),pr2(n+2,0);
//     for(int i=0;i<n;i++){
//         int x,y;
//         cin>>x>>y;
//         if(y==0) v1[x]=1;
//         else v2[x]=1;
//     }
//     int cnt1 = 0,cnt2 = 0;
//     for(int i=0;i<=n;i++){
//         if(v1[i] == 1) cnt1++;
//         if(v2[i] == 1) cnt2++;
//     }
//     int ans = 0;
//     for(int i=0;i<=n-2;i++){
//         if(v1[i]==1 && v1[i+2]==1){
//             if(v2[i+1]==1) ans++;
//         }
//         if(v2[i]==1 && v2[i+2]==1){
//             if(v1[i+1] == 1) ans++;
//         }
//     }
//     for(int i=0;i<=n;i++){
//         if(v1[i]==1 && v2[i]==1) ans += cnt1+cnt2-2;//cout<<i<<endl;
//     }
//     cout<<ans<<endl;
// }

// Klee's SUPER DUPER LARGE Array!!!
// int get(int n,int k,int x){
//     int num1 = (x*(2*k+x-1))/2;
//     int num2 = (n*(2*k+n-1))/2 - num1;
//     int ans = abs(num1-num2);
//     // cout<<num1<<"*"<<num2<<endl;
//     // cout<<n<<" "<<k<<" "<<x<<" "<<ans<<endl;
//     return ans;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int lo = 0,hi = n;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         int num1 = get(n,k,mid);
//         int num2 = get(n,k,mid+1);
//         if(num1>=num2) lo = mid+1;
//         else if(num1<num2) hi = mid-1;
//     }
//     // cout<<lo<<" "<<hi<<endl;
//     int ans = min(get(n,k,lo),get(n,k,hi));
//     cout<<ans<<endl;
// }

// Firefly's Queries
// int getx(vector<int>& first,vector<int>& last,int n,int k){
//     int rot = k/n;
//     int sum = rot*(first[n]);
//     k%=n;
//     if(k==0) return sum;
//     if(n-rot>=k){
//         sum += (first[k+rot]-first[rot]);
//     }else{
//         sum += last[n-rot];
//         sum += first[k-n+rot];
//     }
//     return sum;
// }

// void solve(){
//     int n,q;
//     cin>>n>>q;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> first(n+1,0),last(n+1,0);
//     first[1] = arr[0];
//     last[1] = arr[n-1];
//     for(int i=2;i<=n;i++){
//         first[i] += arr[i-1] + first[i-1];
//         last[i] += arr[n-i] + last[i-1];
//     }
//     while(q--){
//         int l,r;
//         cin>>l>>r;
//         l-=1;
//         int num1 = getx(first,last,n,l);
//         int num2 = getx(first,last,n,r);
//         cout<<abs(num1-num2)<<endl;
//     }
// }

int minVal(int x, int y) { return (x < y)? x: y; }  
  
// A utility function to get the  
// middle index from corner indexes.  
int getMid(int s, int e) { return s + (e -s)/2; }  
  
/* A recursive function to get the 
minimum value in a given range  
of array indexes. The following  
are parameters for this function.  
  
    st --> Pointer to segment tree  
    index --> Index of current node in the  
           segment tree. Initially 0 is  
           passed as root is always at index 0  
    ss & se --> Starting and ending indexes  
                of the segment represented  
                by current node, i.e., st[index]  
    qs & qe --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)  
{  
    // If segment of this node is a part  
    // of given range, then return  
    // the min of the segment  
    if (qs <= ss && qe >= se)  
        return st[index];  
  
    // If segment of this node 
    // is outside the given range  
    if (se < qs || ss > qe)  
        return INT_MAX;  
  
    // If a part of this segment 
    // overlaps with the given range  
    int mid = getMid(ss, se);  
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),  
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2));  
}  
  
// Return minimum of elements in range 
// from index qs (query start) to  
// qe (query end). It mainly uses RMQUtil()  
int RMQ(int *st, int n, int qs, int qe)  
{  
    // Check for erroneous input values  
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input";  
        return -1;  
    }  
  
    return RMQUtil(st, 0, n-1, qs, qe, 0);  
}  
   
int constructSTUtil(int arr[], int ss, int se, 
                                int *st, int si)  
{  
    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
   
    int mid = getMid(ss, se);  
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),  
                    constructSTUtil(arr, mid+1, se, st, si*2+2));  
    return st[si];  
}  
int *constructST(int arr[], int n)  
{  
    // Allocate memory for segment tree  
  
    //Height of segment tree  
    int x = (int)(ceil(log2(n)));  
  
    // Maximum size of segment tree  
    int max_size = 2*(int)pow(2, x) - 1;  
  
    int *st = new int[max_size];  
  
    // Fill the allocated memory st  
    constructSTUtil(arr, 0, n-1, st, 0);  
  
    // Return the constructed segment tree  
    return st;  
}  

void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int range[n+1] = {0};
    int l = 0,r = 0,con = 0;
    while(r<n){
        if(arr[r]-arr[l]==r-l) con++;//cout<<l<<"*"<<r<<endl;
        // cout<<l<<" "<<r<<" "<<arr[r]-arr[l]<<" "<<con<<endl;
        if(r-l+1==k){
            int mov = (k)-con;
            range[l] = mov;
            if(arr[l+1]-arr[l]==1) con--;
            l++;
        }
        r++;
    }
    int *st = constructST(range, n+1); 
    // for(int i=0;i<n;i++) cout<<i<<" "<<range[i]<<endl;
    vector<int> ans;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int temp = RMQ(st, n, l, r);
        ans.push_back(temp);
    }
    for(int ele : ans) cout<<ele<<" ";
    cout<<endl;
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