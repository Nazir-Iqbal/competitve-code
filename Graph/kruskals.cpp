#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

class DisjointSet{
    vector<int> rank,parent,size;
    public:
        // declaring the constructor
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++) parent[i]=i;
        }

        int findUPar(int node){
            // base case
            if(parent[node]==node) return node;

            // doing the path compression
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u,int v){
            // finding the ultimate parent
            int upar_u = findUPar(u);
            int upar_v = findUPar(v);

            if(rank[upar_u]>rank[upar_v]){
                parent[upar_v] = upar_u;

            }else if(rank[upar_u]<rank[upar_v]){
                parent[upar_u] = upar_v;

            }else{
                parent[upar_u] = upar_v;
                rank[upar_u]++;
            }
        }

        void unionBySize(int u,int v){
            // finding the ultimate parent
            int upar_u = findUPar(u);
            int upar_v = findUPar(v);

            if(size[upar_u]>size[upar_v]){
                parent[upar_v] = upar_u;
                size[upar_u]+=size[upar_v];

            }else{
                parent[upar_u] = upar_v;
                size[upar_v]+=size[upar_u];
            }
        }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            int u = i;
            for(auto it : adj[u]){
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt,{u,v}});
            }
        }
        // sorting the edges
        sort(edges.begin(),edges.end());
        
        //declaring a disjoint set
        DisjointSet ds(V);
        int sum = 0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int wt = edges[i].first;
            
            if(ds.findUPar(u)!=ds.findUPar(v)){
                sum+=wt;
                ds.unionByRank(u,v);
            }
        }
        return sum;
    }
};

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