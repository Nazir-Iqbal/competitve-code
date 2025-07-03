#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
// #define nline "\n"

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     cout<<max(n,m)+1<<endl;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> v(n);
//     for(int i=0;i<n;i++) cin>>v[i];
//     map<int,int>mp;
//     for(int i=0;i<n;i++) mp[v[i]]++;
//     vector<int> temp;
//     for(auto &ele : mp){
//         temp.push_back(ele.second);
//     }
//     sort(temp.begin(),temp.end());
//     n = temp.size();
//     if(n == 1) cout<<1<<endl;
//     else{
//         int sum = 0;
//         int cnt=0;
//         for(int i=0;i<n-1;i++){
//             sum += temp[i];
//             if(sum <= k) cnt++;
//         }
//         cout<<n-cnt<<endl;
//     }
// }

// void solve(){
//     int a,b,c;
//     cin>>a>>b>>c;
//     int ans = (a^b) + (b^c) + (c^a);
//     cout<<ans<<endl;
// }

// void solve(){
//     int l,r;
//     cin>>l>>r;
//     int mid = 0;
//     vector<int> v1(31,0),v2(31,0);
//     for(int i=30;i>=0;i--){
//         v1[i] = (l>>i)&1;
//         v2[i] = (r>>i)&1;
//     }
//     int ind = -1;
//     for(int i=30;i>=0;i--){
//         if(v1[i] != v2[i]){
//             ind = i;
//             break;
//         }
//     }
//     for(int i=30;i>ind;i--) if(v1[i]) mid += (1<<i);
//     int ind2 = -1;
//     for(int i=ind-1;i>=0;i--){
//         if(v1[i]==v2[i]){
//             ind2 = i;
//             break;
//         }
//     }
//     // cout<<ind<<" "<<ind2<<endl;
//     if(ind2 == -1){
//         mid += (1<<ind);
//         cout<<l<<" "<<mid<<" "<<r<<endl;
//         return;
//     }
//     if(v1[ind2]==1){
//         for(int i=ind;i>ind2;i--) if(v2[i]) mid += (1<<i);
//         for(int i=ind2-1;i>=0;i--){
//             if(v1[i]==v2[i] && v1[i] == 0) mid += (1<<i);
//         }
//     }else{
//         for(int i=ind;i>ind2;i--) if(v1[i]) mid += (1<<i);
//         mid += (1<<ind2);
//         for(int i=ind2-1;i>=0;i--){
//             if(v1[i] == v2[i] && v1[i] == 0) mid += (1<<i);
//         }
//     }
//     cout<<l<<" "<<mid<<" "<<r<<endl;
// }

// class info{

//     public:
//         int max1,max2,min1,min2,best;
//         info(){
//             max1 = INT_MIN;
//             min1 = INT_MAX;
//             max2 = INT_MIN;
//             min2 = INT_MAX;
//             best = INT_MIN;
//         }
// };

// vector<info> tree(1e6);

// void build(vector<int> &arr,int node,int st,int end){
//     if(st==end){
//         tree[node].min1 = arr[st] - st;
//         tree[node].max1 = arr[st] - st;
//         tree[node].min2 = arr[st] + st;
//         tree[node].max2 = arr[st] + st;
//         tree[node].best = 0;
//         return;
//     }
//     int left = 2*node;
//     int right = 2*node+1;
//     int mid = (st+end)/2;
//     build(arr,left,st,mid);
//     build(arr,right,mid+1,end);

//     // if l & r both lies at left or at right
//     tree[node].best = max(tree[left].best,tree[right].best);

//     // calculating the maximum and minimum values
//     tree[node].max1 = max(tree[left].max1,tree[right].max1);
//     tree[node].min1 = min(tree[left].min1,tree[right].min1);
//     tree[node].max2 = max(tree[left].max2,tree[right].max2);
//     tree[node].min2 = min(tree[left].min2,tree[right].min2);

//     // case 1 : min -> left && max -> right;
//     int case1 = tree[right].max1 - tree[left].min1;

//     // case2 : min -> right && max -> left;
//     int case2 = tree[left].max2 - tree[right].min2;

//     tree[node].best = max(tree[node].best , case1);
//     tree[node].best = max(tree[node].best , case2);
// }

// // int query(vector<int> &arr,int node,int st,int end,int l,int r){
// //     // completly inside
// //     if(l<=st && r>=end){
// //         return tree[node];
// //     }
// //     // not in the range
// //     if(st>r || end<l) return INT_MIN;

// //     int mid = (st+end)/2;
// //     int left = query(arr,2*node,st,mid,l,r);
// //     int right = query(arr,2*node+1,mid+1,end,l,r);
// //     return max(left,right);
// // }

// void update(vector<int> &arr,int node,int st,int end,int pos,int val){
//     // base condidtion
//     if(st==end){
//         arr[st]=val;
//         tree[node].min1 = arr[st] - st;
//         tree[node].max1 = arr[st] - st;
//         tree[node].min2 = arr[st] + st;
//         tree[node].max2 = arr[st] + st;
//         tree[node].best = 0;
//         return;
//     }

//     int mid = (st+end)/2;
//     if(st<=pos && pos<=mid){
//         update(arr,2*node,st,mid,pos,val);
//     }else{
//         update(arr,2*node+1,mid+1,end,pos,val);
//     }

//     int left = 2*node;
//     int right = 2*node + 1;

//     // if l & r both lies at left or at right
//     tree[node].best = max(tree[left].best,tree[right].best);

//     // calculating the maximum and minimum values
//     tree[node].max1 = max(tree[left].max1,tree[right].max1);
//     tree[node].min1 = min(tree[left].min1,tree[right].min1);
//     tree[node].max2 = max(tree[left].max2,tree[right].max2);
//     tree[node].min2 = min(tree[left].min2,tree[right].min2);

//     // case 1 : min -> left && max -> right;
//     int case1 = tree[right].max1 - tree[left].min1;

//     // case2 : min -> right && max -> left;
//     int case2 = tree[left].max2 - tree[right].min2;

//     tree[node].best = max(tree[node].best , case1);
//     tree[node].best = max(tree[node].best , case2);
// }

// void print(vector<info> &v){
//     for(int i=1;i<5;i++) cout<<i<<" "<<v[i].min1<<" "<<v[i].max1<<" "<<v[i].min2<<" "<<v[i].max2<<" "<<v[i].best<<endl;
// }

// void solve(){
//     int n,q;
//     cin>>n>>q;
//     vector<int> arr(n+1);
//     for(int i=1;i<=n;i++) cin>>arr[i];

//     // build the segment tree
//     build(arr,1,1,n);
//     // print(tree);

//     vector<int> ans;
//     ans.push_back(tree[1].best);

//     while(q--){
//         int pos,val;
//         cin>>pos>>val;
//         update(arr,1,1,n,pos,val);
//         ans.push_back(tree[1].best);
//     }
//     for(int &ele : ans) cout<<ele<<endl;
// }

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> adj[n + 1];
    set<int> weights;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
        weights.insert(wt);
        // cout << u << " " << v << " " << wt << endl;
    }

    vector<vector<vector<int>>> query(n + 1);
    for (int i = 0; i < q; i++)
    {
        int a, b, k;
        cin >> a >> b >> k;
        query[a].push_back({b, k, i});
    }

    // constructing the ans;
    vector<int> ans(q, INT_MAX);

    // fixing the start position
    for (int a = 1; a <= n; a++)
    {
        // fixing the weigth
        for (int weight : weights)
        {

            // cout << a << " " << weight << endl;

            // 0 / 1 bfs
            vector<int> dis(n + 1, 1e9);
            dis[a] = 0;
            deque<int> dq;
            dq.push_back(a);
            while (!dq.empty())
            {
                int node = dq.front();
                dq.pop_front();
                for (auto &it : adj[node])
                {
                    int ele = it.first;
                    int wt = it.second;
                    int dist = (wt > weight) ? 1 : 0;

                    if (dist + dis[node] < dis[ele])
                    {
                        if (dist == 1)
                            dq.push_back(ele);
                        else
                            dq.push_front(ele);
                        dis[ele] = dist + dis[node];
                    }
                    // cout << "*" << endl;
                }
            }

            // for (int i = 1; i <= n; i++)
            //     cout << dis[i] << " ";
            // cout << endl;

            for (auto &v : query[a])
            {
                int b = v[0];
                int k = v[1];
                int ind = v[2];
                if (dis[b] < k)
                    ans[ind] = min(ans[ind], weight);
            }
        }
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    FIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}