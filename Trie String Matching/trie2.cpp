#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node * Links[26];
    bool Flag = false;
    int cnt = 0;
    int end = 0;

    bool isContains(char c){
        return Links[c-'a'] != nullptr;
    }
};

class Trie{
    Node * root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(!node->isContains(word[i])){
                node->Links[word[i]-'a'] = new Node();
            }
            node = node->Links[word[i]-'a'];
            node->cnt++;
        }
        node->Flag = true;
        node->end++;
    }

    int countWordsEqualTo(string &word){
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(!node->isContains(word[i])){
                return 0;
            }
            node = node->Links[word[i]-'a'];
        }
        if(node->Flag) return node->end;
        return 0;
    }

    int countWordsStartingWith(string &word){
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(!node->isContains(word[i])){
                return 0;
            }
            node = node->Links[word[i]-'a'];
        }
        return node->cnt;
    }

    void erase(string &word){
        // Write your code here.
        Node * node = root;
        for(int i=0;i<word.size();i++){
            node = node->Links[word[i]-'a'];
            node->cnt--;
        }
        node->end--;
        if(node->end==0) node->Flag = false;
    }
};
