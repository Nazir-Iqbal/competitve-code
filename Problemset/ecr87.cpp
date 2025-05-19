#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// const double pi = 3.14159265358979323846; 

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// using namespace __gnu_pbds;

// #define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Alarm Clock
// void solve(){
//     int a,b,c,d;
//     cin>>a>>b>>c>>d;
//     if(b<a && c<=d ) cout<<-1<<endl;
//     else if(b>=a) cout<<b<<endl;
//     else{
//         a-=b;
//         int div,diff = c-d;
//         if(a%diff==0) div = a/diff;
//         else div = a/diff+1;
//         cout<<b+div*c<<endl;
//     }
// }

// Ternary String
// void solve(){
//     string s;cin>>s;
//     int l=0,r=0,n=s.length();
//     unordered_set<char> st;
//     int ans = INT_MAX;
//     vector<int> hsn(3,-1);
//     for(int i=0;i<n;i++){
//         hsn[s[i]-'1']=i;
//         int _min = *min_element(hsn.begin(),hsn.end());
//         int _max = *max_element(hsn.begin(),hsn.end());
//         if(_min==-1) continue;
//         ans = min(_max-_min+1,ans);
//     }
//     if(ans == INT_MAX) ans = 0;
//     cout<<ans<<endl;
// }

// Simple Polygon Embedding
// double calculateApothem(double sideLength, double numberOfSides) {
//     double angleInRadians = pi / (2.0*numberOfSides);
//     double apothem = sideLength / tan(angleInRadians);
//     return apothem;
// }

// void solve(){
//     double n;cin>>n;
//     double ans = calculateApothem(1,n);
//     cout<<setprecision(20)<<ans<<endl;
// }

// Not So Simple Polygon Embedding
// void solve(){
//     double n;cin>>n;
//     double theta = pi/4.0;
//     double delta = pi/n;
//     double cur = 0,xmin=0,xmax=0;
//     for(int i=0;i<2*n;i++){
//         cur += cos(theta);
//         xmin = min(xmin,cur);
//         xmax = max(xmax,cur);
//         // change in theta
//         theta-=delta;
//     }
//     cout<<setprecision(20)<<xmax-xmin<<endl;
// }

// void solve(){
//     int n,q;
//     cin>>n>>q;
//     oset<int> os;
//     for(int i=0;i<n;i++){
//         int temp;
//         cin>>temp;
//         os.insert(temp);
//     }

//     // for(auto ele : os) cout<<ele<<" ";
//     // cout<<endl;

//     os.erase(2);

//     while(q--){
//         int k;cin>>k;
//         if(k>0){
//             os.insert(k);
//         }else{
//             k = abs(k);
//             k--;
//             auto ele = os.find_by_order(k);
//             os.erase(ele);
//         }
//     }

//     // for(auto ele : os) cout<<ele<<" ";
//     // cout<<endl;

//     if(os.size()==0) cout<<0<<endl;
//     else cout<<(*os.find_by_order(0))<<endl;

// }

// int32_t main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

//     // int t;cin>>t;
//     // while(t--){
//     //   solve();
//     // }

//     // solve();

//     int n,q;
//     cin>>n>>q;
//     oset<int> os;
//     for(int i=0;i<n;i++){
//         int temp;
//         cin>>temp;
//         os.insert(temp);
//     }
    
//     os.erase(2);

//     while(q--){
//         int k;cin>>k;
//         if(k>0){
//             os.insert(k);
//         }else{
//             k = abs(k);
//             k--;
//             auto ele = os.find_by_order(k);
//             os.erase(ele);
//         }
//     }

//     // for(auto ele : os) cout<<ele<<" ";
//     // cout<<endl;

//     if(os.size()==0) cout<<0<<endl;
//     else cout<<(*os.find_by_order(0))<<endl;

//     return 0;
// }

// Multiset
// int n,k;
// vector<int>  a,q;
// int find_le(int x){
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         if(a[i]<=x) cnt++;
//     }
//     // cout<<cnt<<"*"<<endl;
//     for(int i=0;i<k;i++){
//         if(q[i]>0 && q[i]<=x) cnt++;
//         else if(q[i]<0 && abs(q[i])<=cnt) cnt--;
//     }
//     return cnt;
// }


// int main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

//     scanf("%d %d", &n, &k);
//     a.resize(n),q.resize(k);
//     for(int i=0;i<n;i++) scanf("%d", &a[i]);
//     for(int i=0;i<k;i++) scanf("%d", &q[i]);
//     if(find_le(100000000)==0){
//         // cout<<"*"<<endl;
//         cout<<0<<endl;
//         return 0;
//     }
//     int lo = 0,hi = 1e6;
//     // solving using the binary search
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(find_le(mid)>0) hi = mid-1;
//         else lo = mid+1;
//         // cout<<lo<<" "<<mid<<" "<<hi<<endl;
//     }
//     printf("%d\n", lo);

//     return 0;
// }

// template for fenwick tree

    const int n = 1e6+1;
    int fen_tree[n];

    //upadate query
    void update(int ind , int add){
        while(ind<=n){
            fen_tree[ind]+=add;
            ind += (ind & (-ind ));
        }
    }

    //sum query
    int sum(int ind){
        int s = 0;
        while(ind>0){
            s+=fen_tree[ind];
            ind-= (ind & (-ind));
        }
        return s;
    }

    // applying the binary lifting for find opoeration
    int find(int x){
        int cur = 0,prevsum=0;
        for(int i=log2(n);i>=0;i--){
            if((cur + (1 << i) <=n) && ((fen_tree[cur+(1<<i)] + prevsum) < x)){
                cur += 1<<i;
                prevsum+=fen_tree[cur];
            }
        }
        return (cur+1);
    }



int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    FIO;
    int n,q;cin>>n>>q;

    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        update(temp,1);
    }

    while(q--){
        int k;cin>>k;
        if(k>0){
            update(k,1);
        }else{
            k=abs(k);
            int ind = find(k);
            update(ind,-1);
        }
    }

    int ind = find(1);
    if(ind>n) cout<<0<<'\n';
    else cout<<ind<<'\n';
}