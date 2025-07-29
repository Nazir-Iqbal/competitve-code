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
//     int n,m;
//     cin>>n>>m;
//     if(n>2 && m>2){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     if(n==1 || m==1){
//         cout<<"No"<<endl;
//         return;
//     }
    
//     if(n==2 && m==2){
//         cout<<"No"<<endl;
//         return;
//     }
//     cout<<"Yes"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<vector<int>> v;
//     int op = 0,transfer = 0;
//     for(int i=0;i<n;i++){
//         int a,b,c,d;
//         cin>>a>>b>>c>>d;
//         // for zero
//         transfer += abs(a-c);
//         if(b!=d){
//             if(b>d) op += min(a,c);
//             transfer += abs(b-d);
//         }
//     }
//     // cout<<op<<" "<<transfer<<endl;
//     op += transfer/2;
//     cout<<op<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<pair<int,int>> x,y;
//     for(int i=0;i<n;i++){
//         int xi,yi;
//         cin>>xi>>yi;
//         x.push_back({xi,i});
//         y.push_back({yi,i});
//     }
//     sort(x.begin(),x.end());
//     sort(y.begin(),y.end());
//     set<int> firstx,secx,firsty,secy;
//     for(int i=0;i<n;i++){
//         if(i<n/2){
//             firstx.insert({x[i].second});
//             firsty.insert({y[i].second});
//         }else{
//             secx.insert({x[i].second});
//             secy.insert({y[i].second});
//         }
//     }
//     vector<int> samef,sames,crossf,crosss;
//     for(int i=0;i<n/2;i++){
//         int ind = x[i].second;
//         if(firsty.find(ind)!=firsty.end()) samef.push_back(ind);
//         else crossf.push_back(ind);
//     }
//     for(int i=n/2;i<n;i++){
//         int ind= x[i].second;
//         if(secy.find(ind)!=secy.end()) sames.push_back(ind);
//         else crosss.push_back(ind);
//     }
//     vector<pair<int,int>> vp;
//     for(int i=0;i<samef.size();i++){
//         vp.push_back({samef[i],sames[i]});
//     }
//     for(int i=0;i<crossf.size();i++){
//         vp.push_back({crossf[i],crosss[i]});
//     }
//     for(auto &ele : vp) cout<<ele.first+1<<" "<<ele.second+1<<endl;
// }

void solve(){
    int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	vector<int> vis(n+1,0);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// i --> vertices j --> time
	
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