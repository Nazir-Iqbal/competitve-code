#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int hash(string &s, int raddix, int m){
    long long pow = 1, ans = 0;
    for(int i=m-1;i>=0;i--){
        ans = (ans + ((s[i]-'a')*pow)%mod)%mod;
        pow = (pow * raddix)%mod;
    }
    return ans;
}

int RabinKarp(string &text,string &pattern){
    int n = text.size(), m = pattern .size();

    long long hash1 = hash(pattern,26,m);

    long long wt = 1;
    for(int i=0;i<m;i++) wt = (wt * 26)%mod;

    long long hash2 = 0;
    for(int i=0;i<=n-m;i++){
        if(i==0){
            hash2 = hash(text,26,m);
        }else{
            hash2 = (((hash2*26)%mod - ((text[i-1]-'a')*wt)%mod + mod)%mod + (text[i+m-1]-'a'))%mod;
        }

        if(hash1 == hash2) return i;
    }
    return -1;
}
