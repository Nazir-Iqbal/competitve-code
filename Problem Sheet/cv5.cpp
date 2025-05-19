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

bool check(int x,int y,vector<set<pair<int,int>>> &vs,int k){
    int total = 0;
    for(int i=0;i<int(vs.size());i++){
        if(vs[i].find({x,y})!=vs[i].end()) total++;
    }
    if(total == k) return true;
    return false;
}

int sum(vector<pair<int,int>> &point,vector<set<pair<int,int>>> &vs){
    int total = 0,temp = 0;
    for(int i=0;i<int(point.size());i++){
        temp = INT_MAX;
        int x = point[i].first,y = point[i].second;
        for(int j=0;j<int(vs.size());j++){
            if(vs[j].find({x,y})!=vs[j].end()){
                int x1 = (*vs[j].begin()).first,y1 = (*vs[j].begin()).second;
                int x2 = (*vs[j].rbegin()).first,y2 = (*vs[j].rbegin()).second;
                int dis1 = abs(y1-y),dis2 = abs(y2-y);
                if(x1==x2){
                    dis1 = abs(y1-y);
                    dis2 = abs(y2-y);

                }else if(y1==y2){
                    dis1 = abs(x-x1);
                    dis2 = abs(y-y2);
                }
                if(dis1 != 0) temp = min(dis1,temp);
                if(dis2 != 0) temp = min(dis2,temp);
                // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
            }
        }
        total += temp;
    }
    return total;
}

void solve(){
    int n;cin>>n;
    vector<set<pair<int,int>>> vs;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        set<pair<int,int>> temp;
        temp.insert({x1,y1});
        temp.insert({x2,y2});
        if(x1==x2){
            for(int j=min(y1,y2);j<=max(y1,y2);j++) temp.insert({x1,j});
        }else if(y1==y2){
            for(int j=min(x1,x2);j<=max(x1,x2);j++) temp.insert({j,y1});
        }else{
            int j = 0;
            if(x2>x1 && y2>y1){
                while(x1+j<=x2){
                    temp.insert({x1+j,y1+j});
                    j++;
                }
            }else if(x2>x1 && y2<y1){
                while(x1+j<=x2){
                    temp.insert({x1+j,y1-j});
                    j++;
                }
            }else if(x2<x1 && y2>y1){
                while(x2+j<=x1){
                    temp.insert({x1-j,y1+j});
                    j++;
                }
            }else{
                while(x2+j<=x1){
                    temp.insert({x1-j,y1-j});
                    j++;
                }
            }
        }
        vs.push_back(temp);
    }

    // for(int i=0;i<n;i++){
    //     cout<<i<<": "<<endl;
    //     for(auto ele : vs[i]) cout<<ele.first<<" "<<ele.second<<endl;
    // }

    int k;cin>>k;
    vector<pair<int,int>> point;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(check(i,j,vs,k)) point.push_back({i,j});
        }
    }

    // for(int i=0;i<point.size();i++){
    //     cout<<i<<": "<<point[i].first<<" "<<point[i].second<<endl;
    // }

    cout<<sum(point,vs);
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();

    return 0;
}