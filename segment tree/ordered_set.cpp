#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace __gnu_pbds;

#define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve(){
    // to declare the orderd set
    oset<int> os;

    // to insert the element in the ordered set
    os.insert(1);
    os.insert(10);
    os.insert(2);
    os.insert(7);
    os.insert(2);

    // displaying the elements of the ordered set
    cout<<"A = ";
    for(int ele : os) cout<<ele<<" ";
    cout<<endl;
    cout<<endl;
    // finding the kth element
    cout<<"0 th element: "<<*os.find_by_order(0)<<endl;
    cout<<"1 th element: "<<*os.find_by_order(1)<<endl;
    cout<<"2 th element: "<<*os.find_by_order(2)<<endl;
    cout<<"3 rd element: "<<*os.find_by_order(3)<<endl;
    cout<<endl;

    // finding the no. of elements smaller than x
    cout<<"No. of elements smaller than 6: "<<os.order_of_key(6)<<endl;
    cout<<"No. of elements smaller than 11: "<<os.order_of_key(11)<<endl;
    cout<<"No. of elements smaller than 1: "<<os.order_of_key(1)<<endl;
    cout<<endl;

    // provides the upper bound and the lower_bound;
    cout<<"Lower bound of 2: "<<*os.lower_bound(2)<<endl;
    cout<<"Upper bound of 2: "<<*os.upper_bound(2)<<endl;
    cout<<endl;

    // To remove elements from the set
    cout<<"To remove element 11 from the set "<<endl;
    os.erase(11);
    for(int ele : os) cout<<ele<<" ";
    cout<<endl;
    cout<<endl;
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