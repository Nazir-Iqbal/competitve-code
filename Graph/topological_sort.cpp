#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// using dfs
void dfs(int node,vector<int> adj[],vector<int> &vis,stack<int> &st){
    vis[node] = 1;
    for(auto child : adj[node]){
        if(!vis[child]) dfs(child,adj,vis,st);
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> vis(V,0);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]) dfs(i,adj,vis,st);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// topological sort using the kahn algorithm
vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto ele : adj[i]) indegree[ele]++;
    }
    queue <int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> topoSort;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto &it : adj[node]){
            indegree[it]--;
            // if the indegree becomes zero push it in the queue
            if(indegree[it]==0) q.push(it);
        }
    }
    return topoSort;
}

void solve(){
        
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}