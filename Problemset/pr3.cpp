#include <bits/stdc++.h>
using namespace std;
#define int long long

// Distinct Buttons
// void solve(){
//   int n;cin>>n;
//   bool up=0,down=0,left=0,right=0;
//   for(int i=0;i<n;i++){
//     int x,y;
//     cin>>x>>y;
//     if(x>0) right = 1;
//     else if(x<0) left = 1;
//     if(y>0) up = 1;
//     else if(y<0) down = 1;

//   }
//   // cout<<up<<down<<left<<right<<endl;
//   if(up+down+left+right==4){
//     cout<<"No"<<endl;
//     return;
//   }
//   cout<<"yes"<<endl;
// }

// Make Almost Equal With Mod
bool check(vector<int>arr,int n,int k){
  if(k!=0)for(int i=0;i<n;i++) arr[i] = arr[i]%k;
  // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
  // cout<<endl;
  set<int> s;
  for(int i=0;i<n;i++) s.insert(arr[i]);
  if(s.size()!=2) return false;
  return true;
}

void solve(){
  int n;cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  int ans = -1;
  for(int i=0;i<=60;i++){
    int num = pow(2,i);
    if(check(arr,n,num)){
    //   cout<<i<<" ";
      ans = num;
      break;
    }
  }
//   cout<<endl;
    cout<<ans<<endl;
  
}

// Heavy Intervals
// bool cmp(int x,int y){
//   return x>y;
// }

// void solve(){
//   int n;cin>>n;
//   int l[n],c[n];
//   set<int> r;
//   for(int i=0;i<n;i++) cin>>l[i];
//   for(int i=0;i<n;i++){
//     int temp;cin>>temp;
//     r.insert(temp);
//   }
//   for(int i=0;i<n;i++) cin>>c[i];
//   sort(l,l+n,cmp);
//   sort(c,c+n,cmp);
//   int ans = 0;
//   vector<int> store;
//   for(int i=0;i<n;i++){
//     int temp = *r.upper_bound(l[i]);
//     // cout<<temp<<endl;
//     r.erase(temp);
//     store.push_back(temp-l[i]);
//   }
//   sort(store.begin(),store.end());
//   for(int i=0;i<n;i++) ans+= store[i]*c[i];
//   cout<<ans<<endl;
// }

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}