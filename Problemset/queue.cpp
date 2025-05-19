#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Maximum of all subarrays of size k
// vector <int> max_of_subarrays(int *arr, int n, int k)
// {
//     deque<int> dq;
//     vector<int> ans;
//     int l = 0,r=0;
//     while(r<n){
//         while(!dq.empty() && arr[dq.front()]<=arr[r]) dq.pop_front();
//         dq.push_front(r);
//         if(r-l+1==k){
//             while(dq.back()<l) dq.pop_back();
//             l++;
//             ans.push_back(arr[dq.back()]);
//         }
//         r++;
//     }
//     return ans;
// }

// First non-repeating character in a stream
// string FirstNonRepeating(string a){
//     vector<int> hsn(26);
//     int n = a.length();
//     queue<char> q;
//     string ans;
//     for(int i=0;i<n;i++){
//         hsn[a[i] - 'a']++;
//         if(hsn[a[i]-'a'] == 1) q.push(a[i]);
//         while(!q.empty() && hsn[q.front()-'a']>1) q.pop();
//         if(!q.empty()) ans.push_back(q.front());
//         else ans.push_back('#');
//     }
//     return ans;
// }

// void print(queue<int> q){
//     while(!q.empty()){
//         cout<<q.front()<<" ";
//         q.pop();
//     }
//     cout<<endl;
// }

// vector<long long> printFirstNegativeInteger(long long int a[],
//                                              long long int n, long long int k) {
    
//     queue<int> q;
//     vector<long long> ans;
//     int l=0,r=0;
//     while(r<n){
//         if(a[r]<0) q.push(r);
//         while(!q.empty() && q.front()<l) q.pop();
//         if(r-l+1==k){
//             //print(q);
//             if(q.empty()) ans.push_back(0);
//             else ans.push_back(a[q.front()]);
//             l++;
//         }
//         r++;
//     }
//     return ans;
                                                 
//  }

// Steps by Knight
int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int N)
{
    vector<int> dirx = {-2,-1,1,2,2,1,-2,-1};
	vector<int> diry = {1,2,2,1,-1,-2,-2,-1};
	
	vector<vector<bool>> vis(N+1,vector<bool>(N+1,0));
	// applying the bfs on the target postion
	queue<pair<pair<int,int>,int>> q;
	q.push({{kp[0],kp[1]},0});
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int lvl = q.front().second;
		vis[x][y] = 1;
		if(tp[0] == x && tp[1] == y) return lvl;
		for(int i=0;i<8;i++){
			int nx = x + dirx[i];
			int ny = y + diry[i];
			if(nx>0 && nx<=N && ny>0 && ny<=N && vis[nx][ny]) q.push({{nx,ny},lvl+1});
		}
	}
	return -1;
}

void solve(){

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