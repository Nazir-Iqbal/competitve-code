#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans = arr[n-1];
//     ans += (*max_element(arr,arr+n-1));
//     cout<<ans<<endl;
// }

// New Bakery
// int calc(int k,int n,int a,int b){
//     int calc = k*(b+1) - (k*(k+1))/2;
//     calc += (n-k)*a;
//     return calc;
// }

// void solve(){
//     int n,a,b;
//     cin>>n>>a>>b;
//     int ans= n*a;
//     int range = min(n,b);
//     int l = 1,h = range;
//     while(l<=h){
//         int mid = (l+h)/2;
//         int m1 = calc(mid,n,a,b);
//         int m2 = calc(min(mid+1,range),n,a,b);
//         // cout<<ans<<" "<<m1<<" "<<m2<<" "<<mid<<endl;
//         if(m1>=m2){
//             ans = max(ans,m1);
//             h = mid-1;
//         }else{
//             ans = max(ans,m2);
//             l = mid+1;
//         }
//     }
//     cout<<ans<<endl;
// }

// Manhattan Permutations
// void solve(){
//     int n,k;cin>>n>>k;
//     if(k&1){
//         cout<<"No"<<endl;
//         return;
//     }
//     int mv = 0;
//     for(int i=1;i<=n;i++) mv += abs(n-i+1-i);
//     if(k>mv){
//         cout<<"No"<<endl;
//         return;
//     }
//     vector<int> ans;
//     for(int i=1;i<=n;i++) ans.push_back(i);
//     int l=0,r=n-1;
//     k/=2;
//     while(l<r){
//         if(ans[r] - ans[l] <= k) swap(ans[r],ans[l]),k-=abs(ans[r]-ans[l]),l++;
//         if(k==0) break;
//         r--;
//     }
//     cout<<"Yes"<<endl;
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Elections
// void solve(){
//     int n,c;cin>>n>>c;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> prefix(n,0);
//     prefix[0] = arr[0];
//     for(int i=1;i<n;i++) prefix[i] += prefix[i-1] + arr[i];
//     arr[0] += c;
//     int _max = *max_element(arr,arr+n);
//     int ind = 0;
//     for(int i=0;i<n;i++){
//         if(_max == arr[i]){
//             ind = i;
//             break;
//         }
//     }
//     vector<int> ans;
//     for(int i=0;i<n;i++){
//         if(i==ind){
//             ans.push_back(0);
//             continue;
//         }
//         if(prefix[i] + c < arr[ind]) ans.push_back(i+1);
//         else ans.push_back(i);
//     }
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Computing Machine
void solve(){
    int n;cin>>n;
    string s,t;
    cin>>s>>t;
    string s_,t_;
    t_.push_back(t[0]);
    for(int i=1;i<n-1;i++){
        if(t[i] == '1') t_.push_back(t[i]);
        else if(s[i-1] == '0' && s[i+1] == '0') t_.push_back('1');
        else t_.push_back('0');
    }
    t_.push_back(t[n-1]);
    s_.push_back(s[0]);
    for(int i=1;i<n-1;i++){
        if(s[i] == '1') s_.push_back('1');
        else if(t_[i-1]=='1' && t_[i+1]=='1') s_.push_back('1');
        else s_.push_back('0');
    }
    s_.push_back(s[n-1]);
    vector<int> prefix(n,0);
    prefix[0] = s_[0] - '0';
    for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + (s_[i]-'0');
    // for(int i=0;i<n;i++) cout<<prefix[i]<<" ";
    // cout<<endl;
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        l--,r--;
        int len = r-l+1;
        if(l==r){
            cout<<(s[l]-'0')<<endl;
            continue;
        }
        int ans = 0;
        if(len>4) ans += prefix[r-2]-prefix[l+1];
        ans += (s[l]-'0') + (s[r]-'0');
        if(len==2){
            cout<<ans<<endl;
            continue;
        }
        if(len==3){
            if((t[l] == '1' && t[l+2]=='1') || s[l+1] == '1') ans++;
            cout<<ans<<endl;
            continue;
        }
        if((t[l] == '1' && t_[l+2]=='1') || s[l+1] == '1') ans++;
        if((t[r] == '1' && t_[r-2]=='1') || s[r-1] == '1') ans++;
        cout<<ans<<endl;
    }
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