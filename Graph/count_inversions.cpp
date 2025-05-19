#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// algorithm for finding the inversions in Nlog(N)
//applying the merge sort
void merge(vector<int> &arr,int lo,int mid,int hi,int &inversions){
    vector<int> temp;
    int left = lo,right = mid+1;
    while(left<=mid && right<=hi){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            inversions+=(mid-left+1);
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
    for(int i=lo;i<=hi;i++){
        arr[i] = temp[i-lo];
    }
}

void sort(vector<int> &a,int lo,int hi,int &inversions){
    //base case
    if(lo>=hi) return;

    int mid = (lo+hi)/2;
    // applying the breaking of the array
    sort(a,lo,mid,inversions);
    sort(a,mid+1,hi,inversions);

    merge(a,lo,mid,hi,inversions);
}

int numberOfInversions(vector<int>&a, int n) {
    int inversions = 0;
    sort(a,0,n-1,inversions);
    return inversions;
}

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