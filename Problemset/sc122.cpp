#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Man of the Match
// void solve(){
//     int arr[22];
//     for(int i=0;i<22;i++){
//         int a,b;
//         cin>>a>>b;
//         arr[i] = a + 20*b;
//     }
//     int ind = (max_element(arr,arr+22)-arr)+1;
//     cout<<ind<<endl;
// }

// Arya In Grid
// void solve(){
//     int n,m,x,y,l;
//     cin>>n>>m>>x>>y>>l;
//     int left = (x-1)/l;
//     int right = (n-x)/l;
//     int up = (y-1)/l;
//     int down = (m-y)/l;
//     // cout<<left<<' '<<right<<' '<<up<<' '<<down<<endl;
//     cout<<left*up + right*up + left*down + right*down + (left + right + up + down + 1)<<endl;
// }

// Transformation Cost
void solve(){
    int n;cin>>n;
    if(n==0){
        cout<<0<<endl;
        return;
    }
    vector<int> hsn(30,0);
    for(int i=0;i<30;i++){
        if(n&(1<<i)) hsn[i]++;
    }
    // for(int i=0;i<30;i++) cout<<i<<" "<<hsn[i]<<endl;
    vector<int> bits;
    bool flag = false;
    for(int i=29;i>=0;i--){
        if(hsn[i]) flag = true;
        if(flag){
            bits.push_back(hsn[i]);
        }
    }
    reverse(bits.begin(),bits.end());

    // for(int ele : bits) cout<<ele<<' ';
    // cout<<endl;

    int cnt = 0;
    bool check = true;
    for(int i=bits.size()-2;i>=0;i--){
        if(bits[i+1]!=bits[i]) cnt++;
        if(cnt>1){
            check = false;
            break;
        }
    }

    if(check){
        cout<<0<<endl;
        return;
    }

    int num = 0;
    for(int i=bits.size()-1;i>=0;i--){
        if(bits[i]==0){
            num += (1<<i);
            break;
        }else num += (1<<i);
    }

    int ans = num - n;
    cout<<ans<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}