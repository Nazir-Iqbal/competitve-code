#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void merge(vector<int> &arr,int lo,int mid,int hi){
    vector<int> temp;
    int left = lo,right = mid+1;
    while(left<=mid && right<=hi){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=hi){
        temp.push_back(arr[right]);
        right++;
    }
    //copying the result into the original array
    for(int i=lo;i<=hi;i++){
        arr[i] = temp[i-lo];
    }
}

//algorithm for dividing the array on the basis of the index
void sort(vector<int> &arr,int lo,int hi){
    // base case
    if(lo>=hi) return;
    int mid = (lo+hi)/2;
    sort(arr,lo,mid);
    sort(arr,mid+1,hi);
    merge(arr,lo,mid,hi);
}

void mergeSort(vector < int > & arr, int n) {
    sort(arr,0,n-1);
}

void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
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