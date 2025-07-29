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
//     int a,b,x,y;
//     cin>>a>>b>>x>>y;
//     if(a==b){
//         cout<<0<<endl;
//         return;
//     }
//     if(b<a){
//         if(b+1==a){
//             if(a&1) cout<<y<<endl;
//             else cout<<-1<<endl;
//         }else cout<<-1<<endl;
//     }else{
//         int cost = 0;
//         if(x>y){
//             for(int i=a+1;i<=b;i++){
//                 if(i&1) cost += y;
//                 else cost += x;
//             }
//         }else cost += (b-a)*x;
//         cout<<cost<<endl;
//     }
// }

// void solve(){
//     int n;cin>>n;
//     float px,py,qx,qy;
//     cin>>px>>py>>qx>>qy;
//     vector<float> v(n);
//     for(int i=0;i<n;i++) cin>>v[i];
//     sort(v.begin(),v.end());
//     float dis = sqrt(pow(abs(qx-px),2)+pow(abs(qy-py),2));

//         if(n==1){
//             if(v[0] == dis) cout<<"Yes"<<endl;
//             else cout<<"No"<<endl;
//             return;
//         }

//     float sum = 0;
//     for(int i=0;i<n-1;i++) sum+=v[i];

//     if(v[n-1]<=dis){
//         if(sum+v[n-1] >= dis) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }else{
//         float diff = v[n-1]-sum;
//         if(diff<=dis) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }

// void solve(){
//     int n,l,r,k;
//     cin>>n>>l>>r>>k;
//     if(n&1) cout<<l<<endl;
//     else{
//         if(n==2) cout<<-1<<endl;
//         else{
//             int extra = l;
//             int last = 0;
//             while(extra){
//                 extra>>=1ll;
//                 // cout<<last<<" "<<extra<<endl;
//                 last++;
//             }
//             int num = (1ll<<last);
//             // cout<<last<<" "<<num<<endl;
//             if(l<=num && r>=num){
//                 if(k<n-1) cout<<l<<endl;
//                 else cout<<num<<endl;
//             }else cout<<-1<<endl;
//         }
//     }
// }

int power(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (1LL * result * base) % mod;
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Fermat's Little Theorem for modular inverse
int modInverse(int a, int p) {
    // p must be prime
    return power(a, p - 2, p);
}

// Modular Division: (a / b) % m
int modDivide(int a, int b, int m) {
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1) {
        cout << "Division not defined (modular inverse doesn't exist)\n";
        return -1;
    }
    else {
        return (1LL * a * inv) % m;
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    int ans = 2;

    int mul = 1;
    for(int i=1;i<=n;i++) mul = (mul*(i+1))%m;

    // cout<<mul<<endl;

    for(int i=1;i<=n;i++){
        int factor = modDivide(mul,i+1,m);
        for(int j=i+1;j<=n;j++){
            int num = modDivide(factor,j+1,m);
            int zero = (((1 + 2*i + (j-i))%m)*num)%m;
            int non_zero = (i*num)%m;
            cout<<i<<" "<<j<<" "<<factor<<" "<<num<<" "<<zero<<" "<<non_zero<<endl;
            ans = (ans + zero + non_zero)%m;
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