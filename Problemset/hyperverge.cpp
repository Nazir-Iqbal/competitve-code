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

// vector<vector<string>> getSearchResults(vector<string> words, vector<string> queries){
//     map<string,vector<string>> mp;
//     for(int i=0;i<words.size();i++){
//         string temp = words[i];
//         sort(temp.begin(),temp.end());
//         mp[temp].push_back(words[i]);
//     }
//     vector<vector<string>> ans;
//     for(int i=0;i<queries.size();i++){
//         string temp = queries[i];
//         sort(temp.begin(),temp.end());
//         sort(mp[temp].begin(),mp[temp].end());
//         ans.push_back(mp[temp]);
//     }
//     return ans;
// }

int findTotalWeight(vector<int> cans){
    int n = cans.size();
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++) vp.push_back({cans[i],i});
    sort(vp.begin(),vp.end());
    vector<bool> used(n,0);
    int sum = 0;
    for(int i=0;i<n;i++){
        int val = vp[i].first;
        int ind = vp[i].second;
        if(!used[ind]){
            int left = ind-1,right = ind+1;
            while(left>=0 && used[left]) left--;
            while(right<n && used[right]) right++;
            if(left>=0) used[left] = 1;
            if(right<n) used[right] = 1;
            sum += val;
        }
    }
    return sum;
}

void solve(){
    int n;cin>>n;
    vector<int> cans(n);
    for(int i=0;i<n;i++) cin>>cans[i];
    cout<<findTotalWeight(cans)<<endl;
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