#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string &s){
    int n = s.size();
    vector<int> lps(n,0);
    int len = 0, i = 1;
    while(i<n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len !=0){
                len = lps[len-1]; // backtraking
            }else i++;
        }
    }
    return lps;
}

int KMP(string &text, string &pattern){
    int n = text.size(),m = pattern.size();
    vector<int> lps = computeLPS(pattern);
    int i=0,j=0;
    while(i<n){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j!=0) j = lps[j-1];
            else i++;
        }
        if(j==m) return (i-j);
    }
    return -1;
}

int strStr(string haystack, string needle) {
    int n = haystack.size(),m = needle.size();
    if(m>n) return -1;

    return KMP(haystack,needle);
}