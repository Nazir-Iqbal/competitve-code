#include<bits/stdc++.h>
using namespace std;

vector<int> adj[15];
vector<int> cap(15,0);
int bus;
// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Comparator function for sorting edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Union-Find (Disjoint Set Union) class
class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal's algorithm
int kruskalMST(vector<Edge>& edges, int n) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    UnionFind uf(n);
    vector<Edge> mst; // Store the edges of the MST
    int totalWeight = 0;

    for (const auto& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unionSet(edge.u, edge.v);
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    for (const auto& edge : mst) {
        adj[edge.u].push_back(edge.v);
        adj[edge.v].push_back(edge.u);
    }
}

void dfs1(int node,int par,vector<int> &cap,vector<int> &sum){
    sum[node] = cap[node];
    for(int ele : adj[node]){
        if(ele == par) continue;
        dfs1(ele,node,cap,sum);
        sum[node] += sum[ele];
    }
}

void dfs2(int node,int par,vector<int> &cap,vector<int> &dp,vector<int> &sum){
    if(adj[node].size()==1){
        dp[node] = (cap[node]+bus-1)/bus;
        return;
    }
    int cnt = 0;
    for(int ele : adj[node]){
        if(ele == par) continue;
        dfs2(ele,node,cap,dp,sum);
        cnt += dp[ele];
    }
    int load = cnt*bus;
    if(load>=sum[node]) dp[node] = cnt;
    else{
        int left = sum[node]-load;
        int extra = (left+bus-1)/bus;
        dp[node] = cnt+extra;
    }
}

void solve() {

    // Graph as adjacency matrix
    int n;cin>>n;
    vector<vector<int>> graph(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>graph[i][j];
    }
    for(int i=1;i<n;i++) cin>>cap[i];

    vector<Edge> edges;

    // Convert adjacency matrix to edge list
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Avoid duplicate edges
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    kruskalMST(edges, n);
    cin>>bus;
    vector<int> dp(n,0),sum(n,0);
    dfs1(0,-1,cap,sum);
    dfs2(0,-1,cap,dp,sum);
    cout<<dp[0]<<endl;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;
    while(t--){
        solve();
    }
}

