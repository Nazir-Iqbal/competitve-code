#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    oset<pair<int,int>> os;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        os.insert({arr[i],i});
    }
    for(int i=0;i<q;i++){
        char type;cin>>type;
        if(type == '?'){
            int a,b;
            cin>>a>>b;
            int cnt1 = os.order_of_key({a-1,n});
            int cnt2 = os.order_of_key({b,n});
            // cout<<cnt1<<" "<<cnt2<<endl;
            cout<<cnt2-cnt1<<endl;
        }else{
            int k,x;
            cin>>k>>x;
            k--;
            os.erase({arr[k],k});
            os.insert({x,k});
            arr[k] = x;
        }
    }
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    solve();

    return 0;
}