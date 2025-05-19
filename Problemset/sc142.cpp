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
//     int n;cin>>n;
//     int num1 = log2(n);
//     num1 = (1<<(num1-1));
//     int num2 = n>>1;
//     int ans = (num2-num1)*4;
//     cout<<ans<<endl;
// }

// Array Removal
// int find(int num){
//     int set =  __builtin_popcount(num);
//     for(int i=0;i<=30;i++){
//         if(!((1<<i)&num)){
//             if(set!=0) return i;
//         }else set--;
//     }
//     return -1;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     int num = 0;
//     for(int i=0;i<n;i++) cin>>arr[i],num |= arr[i];
//     int pos = -1;
//     pos = find(num);
//     unordered_set<int> s;
//     // cout<<pos<<endl;
//     while(pos != -1 && s.size()!=n){
//         int temp = (1<<pos);
//         num = 0;
//         for(int i=0;i<n;i++){
//             if(arr[i]>temp) s.insert(i);
//             else num|=arr[i];
//         }
//         pos = find(num);
//         // cout<<temp<<" "<<pos<<endl;
//     }
//     cout<<s.size()<<endl;
// }


// Number Hunt
// bool isPrime(int n) 
// { 
//     if (n <= 1)  return false; 
//     if (n <= 3)  return true; 
//     if (n%2 == 0 || n%3 == 0) return false; 
   
//     for (int i=5; i*i<=n; i=i+6) 
//         if (n%i == 0 || n%(i+2) == 0) 
//            return false; 
   
//     return true; 
// } 
 
// int nextPrime(int N)
// {
 
//     if (N <= 1)
//         return 2;
 
//     int prime = N;
//     bool found = false;
//     while (!found) {
//         prime++;
 
//         if (isPrime(prime))
//             found = true;
//     }
 
//     return prime;
// }

// void solve(){
//     int n;cin>>n;
//     if(n==1){
//         cout<<6<<endl;
//         return;
//     }
//     if(isPrime(n)){    
//         int next = nextPrime(n);
//         cout<<n*next<<endl;
//     }else{
//         int next = nextPrime(n);
//         int nnext = nextPrime(next);
//         cout<<next*nnext<<endl;
//     }
// }

// Sum of Xors
void solve(){
    int n,m;
    cin>>n>>m;
    if(n==2 || m==2){
        cout<<(3*n*m)/2<<endl;
    }else{
        cout<<(n*m+4)<<endl;
    }
}

// Pairs Sum with Length x
pair<int,int> find(int x,int num){
    int _min = pow(10,x-1);
    int _max = pow(10,x);
    return {_min-num,_max-num};
}

auto myComp = [&](pair<int,string> e1, pair<int,string> e2) {
if(e1.second!=e2.second)
    return e1.second<e2.second;
else
    return e1.first<e2.first;
};

int search(int low,int high,int st,vector<pair<int,int>> &prefix){
    int n = prefix.size()-1;
    int ind1 = -1,ind2 = -1,lo = st,hi = n;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(prefix[mid].first >= low){
            ind1 = mid;
            hi = mid-1;
        }else lo = mid+1;
    }
    cout<<low<<" "<<high<<" "<<ind1<<" "<<ind2<<endl;
    if(ind1 == -1) return 0;
    lo = st,hi = n;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(prefix[mid].first <= high){
            ind2 = mid;
            lo = mid+1;
        }else hi = mid-1;
    }
    int ans = prefix[ind2].second + prefix[ind1-1].second;
    // cout<<ans<<endl;
    return ans;
}

void solve(){
    int n,x;
    cin>>n>>x;
    map<int,int> m;
    int arr[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++){
        m[arr[i]] += (n-i+1);
    }
    vector<pair<int,int>> prefix;
    prefix.push_back({0,0});
    for(auto ele : m) prefix.push_back({ele.first,ele.second});
    sort(prefix.begin(),prefix.end());
    // for(int i=1;i<prefix.size();i++) prefix[i].second += prefix[i-1].second;

    for(int i=0;i<prefix.size();i++) cout<<prefix[i].first<<" "<<prefix[i].second<<endl;
    
    int ans = 0;
    for(int i=1;i<=n;i++){
        pair<int,int> range = find(x,arr[i]);
        int temp = search(range.first,range.second,i,prefix);
        cout<<arr[i]<<" "<<range.first<<"*"<<range.second<<" "<<temp<<endl;
        ans += temp;
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