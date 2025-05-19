#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// segment tree
struct segmenttree
{
    int n;
    vector<int> st, lazy;
 
    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
 
    void push(int start, int ending, int node)
    {
        if (lazy[node])
        {
            st[node] = max(lazy[node], st[node]);
 
            if (start != ending)
            {
                lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
                lazy[2 * node + 2] = max(lazy[2 * node + 2], lazy[node]);;
            }
 
            lazy[node] = 0;
        }
    }
 
    int query(int start, int ending, int l, int r, int node)
    {
        push(start, ending, node);
 
        if (start > r || ending < l)
        {
            return 0;
        }
 
        if (start >= l && ending <= r)
        {
            return st[node];
        }
 
        int mid = (start + ending) / 2;
 
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
 
        return max(q1 , q2);
    }
 
    void update(int start, int ending, int node, int l, int r, int value)
    {
        push(start, ending, node);
 
        if (start > r || ending < l)
        {
            return;
        }
 
        if (start >= l && ending <= r)
        {
            lazy[node] = value;
            push(start, ending, node);   
            return;
        }
 
        // partial case
        int mid = (start + ending) / 2;
 
        update(start, mid, 2 * node + 1, l, r, value);
 
        update(mid + 1, ending, 2 * node + 2, l, r, value);
 
        st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
 
        return;
    }
 
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
 
    void update(int l, int r, int x)
    {
        update(0, n - 1, 0, l, r, x);
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