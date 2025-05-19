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
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> hsn(n+1,0);
//     for(int i=0;i<n;i++) hsn[arr[i]]++;
//     bool taken = 0;
//     for(int i=0;i<=n;i++){
//         if(hsn[i] == 0){
//             cout<<i<<endl;
//             return;
//         }
//         if(hsn[i]==1){
//             if(taken){
//                 cout<<i<<endl;
//                 return;
//             }
//             taken = 1;
//         }
//     }
// }

// Bessie's Birthday Cake (Easy Version)
// int tt = 1;
// placing even points before odd points in increasing orderr
// vector<int> check(vector<int> &diff){
//     vector<int> ans;
//     sort(diff.begin(),diff.end());
//     for(int i=0;i<diff.size();i++){
//         if(diff[i]%2==0) ans.push_back(diff[i]);
//     }
//     for(int i=0;i<diff.size();i++){
//         if(diff[i]&1) ans.push_back(diff[i]);
//     }
//     return ans;
// }

// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     int arr[m];
//     for(int i=0;i<m;i++) cin>>arr[i];
//     sort(arr,arr+m);
//     int ans = max(m+k-2,0);
//     vector<int> v;
//     int two = 0;
//     if(m>1){
//         int dis = n - arr[m-1];
//         dis+= (arr[0]);// for n->1
//         if(dis == 2) two++;
//         else if(dis>2) v.push_back(dis);
//     }
//     for(int i=1;i<m;i++){
//         int dis = arr[i]-arr[i-1];
//         if(dis == 2) two++;
//         else if(dis>2) v.push_back(dis);
//     }
//     v = check(v);
//     for(int i=0;i<v.size();i++){
//         int req = (v[i]/2);
//         int get = v[i]/2;
//         if(v[i]%2==0) req--;
//         if(k>=req) two+=get,k-=req;
//         else{
//             two+=k;
//             k=0;
//             break;
//         }
//     }
//     two-=k;
//     ans += two;
//     cout<<ans<<endl;
// }

// int find(int n,int m,vector<vector<int>> &v,int ind,int d){
// 	// for storing the previous minimum
// 	priority_queue<pair<int,int>> pq;
// 	pq.push({-1,0});
// 	int cost = 0;
// 	for(int i=1;i<m;i++){
// 		int index = pq.top().second;
// 		int val = -pq.top().first;
// 		int reach = i-d-1;
// 		while(index<reach){
// 			pq.pop();
// 			index = pq.top().second;
// 			val = -pq.top().first;
// 		}
// 		cost = val+v[ind][i]+1;
// 		pq.push({-cost,i});
// 	}
// 	return cost;
// }

// void solve(){
//     int n,m,k,d;
//     cin>>n>>m>>k>>d;
// 	vector<vector<int>> arr(n,vector<int>(m));
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++) cin>>arr[i][j];
// 	}
// 	int ans = 1e18,l = 0,r = 0;
// 	int sum = 0;
// 	while(r<n){
// 		sum += find(n,m,arr,r,d);
// 		if(r-l+1==k){
// 			ans = min(ans,sum);
// 			sum -= find(n,m,arr,l,d);
// 			l++;
// 		}
// 		r++;
// 	}
// 	cout<<ans<<endl;
// }

// Binary Path
// void solve(){
// 	int n;cin>>n;
// 	vector<string> v(2);
// 	for(int i=0;i<2;i++) cin>>v[i];
// 	int down = 1,cnt = 1;
// 	string ans;
// 	ans.push_back(v[0][0]);
// 	for(int i=0;i<n-1;i++){
// 		// regular ways
// 		if(v[1][i]==v[0][i+1] && down) cnt++,ans.push_back(v[1][i]);
// 		else{
// 			if(v[1][i] > v[0][i+1] && down) cnt = 1,ans.push_back(v[0][i+1]); // down greater we will stay
// 			else down = 0,ans.push_back(v[1][i]); // up greater we forced down
// 		}
// 	}
// 	ans.push_back(v[1][n-1]);
// 	cout<<ans<<endl;
// 	cout<<cnt<<endl;
// }

// Bitwise Operation Wizard
// void solve(){
// 	int n;cin>>n;
// 	if(n==2){
// 		cout<<"! "<<0<<" "<<1<<endl;
// 		cout.flush();
// 	}
// 	int pw = 0;
// 	for(int i=0;i<31;i++){
// 		if((1<<pw)<n-1) pw=i;
// 		else break;
// 	}
// 	int first = (1<<pw), second = (1<<pw)-1;
// 	int ind1 = 0,ind2 = 0;
// 	for(int i=0;i<n;i++){
// 	}
// }

// Bitwise Operation Wizard
// void solve(){
//     int n;cin>>n;
//     int maxind = 0;
//     for(int i=1;i<n;i++){
//         cout<<"? "<<maxind<<" "<<maxind<<" "<<i<<" "<<i<<endl;
//         cout.flush();
//         char c;cin>>c;
//         if(c=='<') maxind = i;
//     }
//     vector<int> possible;
//     int prev = 0;
//     for(int i=0;i<n;i++){
//         cout<<"? "<<maxind<<" "<<prev<<" "<<maxind<<" "<<i<<endl;
//         cout.flush();
//         char c;cin>>c;
//         if(c == '=') possible.push_back(i);
//         else if(c=='<'){
//             possible.clear();
//             possible.push_back(i);
//             prev = i;
//         }
//     }
//     int minind = possible[0];
//     // for(int ele : possible) cout<<ele<<" ";
//     // cout<<endl;
//     for(int i=1;i<possible.size();i++){
//         cout<<"? "<<minind<<" "<<minind<<" "<<possible[i]<<" "<<possible[i]<<endl;
//         cout.flush();
//         char c;cin>>c;
//         if(c == '>') minind = possible[i];
//     }
//     cout<<"! "<<minind<<" "<<maxind<<endl;
// }

// Find a Mine
// void solve(){
//     int n,m;cin>>n>>m;
//     cout<<"? "<<1<<" "<<1<<endl;
//     int x;cin>>x;
//     int xcor,ycor;
//     if(x<m) xcor = 1,ycor=x+1;
//     else xcor = x-m+2,ycor = m;
//     cout<<"? "<<xcor<<" "<<ycor<<endl;
//     int x1;cin>>x1;
//     x1/=2;
//     int x2=-1;
//     if(xcor+x1<=n && ycor-x1>0){
//         cout<<"? "<<xcor+x1<<" "<<ycor-x1<<endl;
//         cin>>x2;
//     }
//     if(x2==0) cout<<"! "<<xcor+x1<<" "<<ycor-x1<<endl;
//     else{
//         int dis = min(n-xcor,ycor-1);
//         xcor += dis,ycor-=dis;
//         cout<<"? "<<xcor<<" "<<ycor<<endl;
//         int x3;cin>>x3;
//         x3/=2;
//         cout<<"! "<<xcor-x3<<" "<<ycor+x3<<endl;
//     }
// }

// Turtle vs. Rabbit Race: Optimal Trainings
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> prefix(n+1,0);
//     for(int i=1;i<=n;i++) prefix[i] += (prefix[i-1]+arr[i-1]);
//     int q;cin>>q;
//     vector<int> ans;
//     while(q--){
//         int l,u;
//         cin>>l>>u;
//         int ind = upper_bound(prefix.begin(),prefix.end(),prefix[l-1]+u)-prefix.begin();
//         if(ind == n+1) ans.push_back(n);
//         else if(ind == l) ans.push_back(l);
//         else{
//             int req2 = prefix[ind]-prefix[l-1],req1 = prefix[max(ind-1,l)]-prefix[l-1];
//             if(req1>=u) ans.push_back(ind-1);
//             else{
//                 int sum = (u*(u+1))/2;
//                 req2= max(req2-u-1,0ll),req1 = u-req1;
//                 if(req1<=req2) ans.push_back(ind-1);
//                 else ans.push_back(ind);
//             }
//         }
//     }
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Final Countdown
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     string temp;
//     int ind = 0;
//     for(int i=0;i<n;i++){
//         if(s[i] == '0') ind++;
//         else break;
//     }
//     for(int i=ind;i<n;i++) temp.push_back(s[i]);
//     s = temp;
//     n = s.length();
//     vector<int> prefix(n,0);
//     prefix[0] = s[0]-'0';
//     for(int i=1;i<n;i++) prefix[i] = (prefix[i-1]+(s[i]-'0'));
//     vector<int> v;
//     int prev = 0;
//     for(int i=n-1;i>=0;i--){
//         prefix[i]+=prev;
//         prev = 0;
//         v.push_back(prefix[i]%10);
//         prefix[i]/=10;
//         prev = prefix[i];
//     }
//     if(prev>0){
//         while(prev)v.push_back(prev%10),prev/=10;
//     }
//     reverse(v.begin(),v.end());
//     string ans;
//     for(int i=0;i<v.size();i++) ans.push_back(char(v[i]+'0'));
//     cout<<ans<<endl;
// }

// Card Game
// void solve(){
//     int n;cin>>n;
//     char c;cin>>c;
//     vector<bool> vis(2*n,0);
//     map<char,vector<int>> mp;
//     set<int> trump;
//     for(int i=0;i<2*n;i++){
//         int x;cin>>x;
//         char type;cin>>type;
//         if(type == c) trump.insert(x);
//         else mp[type].push_back(x);
//     }
//     vector<pair<pair<int,char>,pair<int,char>>> ans;
//     for(auto ele : mp){
//         vector<int> v = ele.second;
//         sort(v.begin(),v.end());
//         for(int i=0;i<v.size();i++){
//             if(i+1<v.size()){
//                 ans.push_back({{v[i],ele.first},{v[i+1],ele.first}});
//                 i++;
//             }else{
//                 if(trump.size()>0){
//                     int num = (*trump.begin());
//                     trump.erase(trump.begin());
//                     ans.push_back({{v[i],ele.first},{num,c}});
//                 }else{
//                     cout<<"IMPOSSIBLE"<<endl;
//                     return;
//                 }
//             }
//         }
//     }

//     if(trump.size()&1){
//         cout<<"IMPOSSIBLE"<<endl;
//         return;
//     }else{
//         vector<int> v;
//         for(int ele : trump) v.push_back(ele);
//         for(int i=0;i<v.size();i+=2){
//             ans.push_back({{v[i],c},{v[i+1],c}});
//         }
//     }

//     for(auto ele : ans){
//         cout<<ele.first.first<<ele.first.second<<" "<<ele.second.first<<ele.second.second<<endl;
//     }
// }

// LR-remainders
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> arr(n,0);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     string s;cin>>s;
//     vector<pair<int,int>> range;
//     range.push_back({0,n-1});
//     int l = 0,r = n-1;
//     for(int i=0;i<n-1;i++){
//         if(s[i] == 'L')l++,range.push_back({l,r});
//         else r--,range.push_back({l,r});
//     }
//     reverse(range.begin(),range.end());
//     vector<int> ans;
//     l=-1,r=-1;
//     int temp = 1;
//     for(int i=0;i<n;i++){
//         if(l==-1){
//             l = range[i].first,r = range[i].second;
//             temp = arr[l];
//             temp%=m;
//             ans.push_back(temp);
//             continue;
//         }else{
//             if(l!=range[i].first) l--,temp*=arr[l];
//             else r++,temp*=arr[r];
//         }
//         // cout<<l<<" "<<r<<" "<<temp<<endl;
//         temp%=m;
//         ans.push_back(temp);
//     }
//     reverse(ans.begin(),ans.end());
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Chat Screenshots
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> adj[n+1];
//     for(int i=0;i<k;i++){
//         int prev = -1;
//         for(int i=0;i<n;i++){
//             int x;cin>>x;
//             if(i==0) continue;
//             if(prev!=-1) adj[prev].push_back(x);
//             prev = x;
//         }
//     }
//     // Kahn's algorithm
//     vector<int> indegree(n+1,0);
//     for(int i=1;i<=n;i++){
//         for(int ele : adj[i]) indegree[ele]++;
//     }
//     queue<int> q;
//     vector<int> topo;
//     for(int i=1;i<=n;i++) if(indegree[i] == 0) q.push(i);
//     while(!q.empty()){
//         int f = q.front();
//         topo.push_back(f);
//         q.pop();
//         for(int ele : adj[f]){
//             indegree[ele]--;
//             if(indegree[ele]==0) q.push(ele);
//         }
//     }
//     // for(int ele : topo) cout<<ele<<" ";
//     // cout<<endl;
//     if(topo.size()!=n) cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;
// }

// Anna and the Valentine's Day Gift
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int sz = 0;
//     vector<int> cnt;
//     for(int i=0;i<n;i++){
//         bool flag = false;
//         int count = 0;
//         while(arr[i]){
//             if(arr[i]%10) flag = true;
//             if(flag) sz++;
//             else count++;
//             arr[i]/=10;
//         }
//         cnt.push_back(count);
//     }
//     sort(cnt.begin(),cnt.end(),greater<int>());
//     for(int i=1;i<n;i+=2) sz += cnt[i];
//     if(sz>m) cout<<"Sasha"<<endl;
//     else cout<<"Anna"<<endl;
// }

// Divisible Pairs
// void solve(){
//     int n,x,y;
//     cin>>n>>x>>y;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<pair<int,int>,int> mp;
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int num1 = (x-(arr[i]%x))%x;
//         int num2 = (arr[i]%y);
//         ans += mp[{num1,num2}];
//         mp[{arr[i]%x,arr[i]%y}]++;
//     }
//     cout<<ans<<endl;
// }

// Lexicographically Largest
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> v;
//     for(int i=0;i<n;i++) v.push_back(arr[i]+i+1);
//     sort(v.begin(),v.end(),greater<int>());
//     vector<int> ans;
//     ans.push_back(v[0]);
//     int _max = v[0];
//     for(int i=1;i<n;i++){
//         if(_max>v[i]) _max=v[i];
//         else _max--;
//         ans.push_back(_max);
//     }
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Sasha and the Casino
// void solve(){
//     int k,x,a;
//     cin>>k>>x>>a;
//     int loss = 0;
//     for(int i=1;i<=x+1;i++){
//         int bet = (loss/(k-1))+1;
//         if(i==1) bet = 1;
//         loss+=bet;
//         a-=bet;
//         // cout<<bet<<" "<<loss<<endl;
//         if(a<0){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Physical Education Lesson
// void solve(){
//     int n,x;
//     cin>>n>>x;
//     int postive = n-x,negative = n+x-2;
//     // cout<<postive<<" "<<negative<<endl;
//     int ans = 0;
//     unordered_set<int> s;
//     for(int i=1;i*i<=postive;i++){
//         if(postive%i==0){
//             int num1 = i,num2 = postive/i;
//             if(num1%2==0){
//                 int num = (num1+2)/2;
//                 if(num>=x) s.insert(num);
//             }
//             if(num2%2==0){
//                 int num = (num2+2)/2;
//                 if(num>=x) s.insert(num);
//             }
//         }
//     }
//     for(int i=1;i*i<=negative;i++){
//         if(negative%i==0){
//             int num1 = i,num2 = negative/i;
//             if(num1%2==0){
//                 int num = (num1+2)/2;
//                 if(num>x) s.insert(num);
//             }
//             if(num2%2==0){
//                 int num = (num2+2)/2;
//                 if(num>x) s.insert(num);
//             }
//         }
//     }
//     // for(int ele : s) cout<<ele<<" ";
//     // cout<<endl;
//     cout<<s.size()<<endl;
// }

// Iris and Game on the Tree
int cnt0,cnt1,cnt2,cnt3;
void dfs(int node,int par,vector<int> adj[],string &s){
    int child = 0;
    for(int it : adj[node]){
        if(it == par) continue;
        dfs(it,node,adj,s);
        child++;
    }
    if(child == 0){
        if(s[node-1]=='0') cnt0++;
        else if(s[node-1]=='1') cnt1++;
        else cnt2++;
    }else{
        if(s[node-1]=='?') cnt3++;
    }
}

void solve(){
    int n;cin>>n;
    vector<int> adj[n+1];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string s;cin>>s;
    cnt0 = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0;
    dfs(1,0,adj,s);
    if(s[0] == '?') cnt3--;
    // cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
    int ans = 0;
    if(s[0] == '?'){
        if(cnt1==cnt0){
            if(cnt3&1){
                ans = cnt1 + (cnt2+1)/2; // ceil
            }else ans = cnt1 + (cnt2/2);
        }else{
            ans = max(cnt1,cnt0)+(cnt2/2);
        }
    }else{
        if(s[0]=='0') ans = cnt1 + (cnt2+1)/2;
        else ans = cnt0 + (cnt2+1)/2;
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
	// solve();
    return 0;
}