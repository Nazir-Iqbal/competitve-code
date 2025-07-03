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
//     int l1,b1,l2,b2,l3,b3;
//     cin>>l1>>b1>>l2>>b2>>l3>>b3;
//     if(l1 == l2 && l2 == l3){
//         if(b1+b2+b3 == l1){
//             cout<<"Yes"<<endl;
//             return;
//         }
//     }
//     if(b1 == b2 && b2==b3){
//         if(l1+l2+l3 == b1){
//             cout<<"Yes"<<endl;
//             return;
//         }
//     }
//     if(l2==l3){
//         int s1 = l1+l2;

//         if(b2+b3==b1 && s1==b1){
//             cout<<"Yes"<<endl;
//             return;
//         }
//     }
//     if(b2==b3){
//         int s1 = b1 + b2;

//         if(l2+l3==l1 && s1==l1){
//             cout<<"Yes"<<endl;
//             return;
//         }
//     }
//     cout<<"No"<<endl;
// }

// void solve(){
//     int n,s;
//     cin>>n>>s;
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int dx,dy,x,y;
//         cin>>dx>>dy>>x>>y;
//         if(x==y){
//             if((dx==1 && dy==1) || (dx==-1 && dy==-1)){
//                 ans++;
//                 continue;
//             }
//         }
//         if(x==s-y){
//             if((dx==1 && dy==-1) || (dx==-1 && dy==1)){
//                 // cout<<x<<" "<<y<<endl;
//                 ans++;
//             }
//         }
//     }
//     cout<<ans<<endl;  
// }


// void solve(){
//     int n,m;
//     cin>>n>>m;
//     if(m<n || m>(n*(n+1))/2){
//         cout<<-1<<endl;
//         return;
//     }
//     vector<int> node(n+2,0);
//     int rem = m,cur = n;
//     while(rem){
//         int req = min(rem,cur);
//         int l = n-req+1;
//         // cout<<cur<<" "<<req<<endl;
//         node[l]++;
//         node[n+1]--;
//         rem-=req;
//         cur--;
//     }
//     unordered_set<int> used;
//     for(int i=1;i<=n+1;i++){
//         node[i] += node[i-1];
//         used.insert(node[i]);
//     }
//     // for(int i=0;i<=n+1;i++) cout<<node[i]<<' ';
//     // cout<<endl;
//     vector<int> prefix(n+2);
//     for(int i=1;i<=n;i++){
//         if(node[i]==node[i-1]) prefix[i] = prefix[i-1]+1;
//         else prefix[i] = 1;
//     }
//     // for(int i=0;i<=n;i++) cout<<prefix[i]<<" ";
//     // cout<<endl;
//     cout<<node[n]<<endl;
//     cur = 2;
//     int val = -1;
//     for(int i=1;i<=n;i++){
//         int prev = node[i];
//         if(prefix[i] > 1){
//             while(used.find(cur)!=used.end()) cur++;
//             if(prefix[i] == 2) cout<<node[i]<<" "<<cur<<endl;
//             else cout<<prev<<" "<<cur<<endl;
//             prev = cur;
//             cur++;
//         }
//         if(node[i]!=node[i-1]) val = node[i-1];
//         if(node[i+1]!=node[i] && node[i] != 1) cout<<prev<<" "<<val<<endl;
//     }
    
// }

// const int MOD = 1e9+7;

// struct Mint
// {
//     int value;
//     static const int MOD_value = MOD;
 
//     Mint(long long v = 0)
//     {
//         value = v % MOD;
//         if (value < 0)
//             value += MOD;
//     }
//     Mint(long long a, long long b) : value(0)
//     {
//         *this += a;
//         *this /= b;
//     }
 
//     Mint &operator+=(Mint const &b)
//     {
//         value += b.value;
//         if (value >= MOD)
//             value -= MOD;
//         return *this;
//     }
//     Mint &operator-=(Mint const &b)
//     {
//         value -= b.value;
//         if (value < 0)
//             value += MOD;
//         return *this;
//     }
//     Mint &operator*=(Mint const &b)
//     {
//         value = (long long)value * b.value % MOD;
//         return *this;
//     }
 
//     friend Mint mexp(Mint a, long long e)
//     {
//         Mint res = 1;
//         while (e)
//         {
//             if (e & 1)
//                 res *= a;
//             a *= a;
//             e >>= 1;
//         }
//         return res;
//     }
//     friend Mint inverse(Mint a) { return mexp(a, MOD - 2); }
 
//     Mint &operator/=(Mint const &b) { return *this *= inverse(b); }
//     friend Mint operator+(Mint a, Mint const b) { return a += b; }
//     friend Mint operator-(Mint a, Mint const b) { return a -= b; }
//     friend Mint operator-(Mint const a) { return 0 - a; }
//     friend Mint operator*(Mint a, Mint const b) { return a *= b; }
//     friend Mint operator/(Mint a, Mint const b) { return a /= b; }
//     friend std::ostream &operator<<(std::ostream &os, Mint const &a) { return os << a.value; }
//     friend std::istream &operator>>(std::istream &is, Mint &a) {return is >> a.value;}
//     friend bool operator==(Mint const &a, Mint const &b) { return a.value == b.value; }
//     friend bool operator!=(Mint const &a, Mint const &b) { return a.value != b.value; }
// };

// void solve(){
//     Mint a,b,k;
//     cin>>a>>b>>k;
//     Mint n = k*(a-1)+1;
//     Mint m = 1;
//     for(Mint i=0;i.value<a.value;i=i+1){
//         // cout<<i<<endl;
//         m = m*(n-i);
//     }
//     for(int i=0;i<a.value;i++) m = m/(a-i);
//     m=m*k;
//     m=m*(b-1);
//     m=m+1;
//     cout<<n<<" "<<m<<endl;
// }

int find(int cur,int cost,int total,int k){
    int l = 1,r = total;
    while(l<=r){
        int mid = (l+r)/2;
        int sum =cur+mid + k;
        if(sum<=cost) l = mid+1;
        else r = mid-1;
    }
    return r;
}

bool check(int n,vector<int> &v,int k,int x,int total){
    int sum = 0;
    for(int i=0;i<n;i++){
        if(v[i]<x){
            sum += v[i];
            // additional
            int add = find(v[i],x,total,k);
            sum += add;
        }else{
            sum += x;
        }
        // cout<<sum<<endl;
    }
    return sum>=total;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    int total = 0;
    for(int i=0;i<n;i++) cin>>v[i],total += v[i];
    sort(v.begin(),v.end());
    int l = 1,r = 1e12;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(n,v,k,mid,total)) r = mid-1;
        else l = mid+1;
    }
    int ans = 0;
    // cout<<check(n,v,k,11,total)<<endl;
    // cout<<l<<endl;
    int req = total;
    l--;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int temp = 0;
        if(v[i]<l){
            temp += v[i];
            // additional
            int add = find(v[i],l,total,k);
            temp += add;
            ans += (temp*(temp+1))/2 + add*k;
        }else{
            temp += l;
            ans += (temp*(temp+1))/2;
        }
        cnt+=temp;
    }
    ans += (total-cnt)*(l+1);
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