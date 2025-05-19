#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node * Links[26];
    bool Flag = false;

    bool isContains(char c){
        return Links[c-'a']!=NULL;
    }
};

class Trie {
    Node * root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(!node->isContains(word[i])){
                node->Links[word[i]-'a'] = new Node();
            }
            node = node->Links[word[i]-'a'];
        }
        node->Flag = true;
    }
    
    bool search(string word) {
        Node * node = root;
        for(int i=0;i<word.size();i++){
            if(!node->isContains(word[i])){
                return false;
            }
            node = node->Links[word[i]-'a'];
        }
        return node->Flag;
    }
    
    bool startsWith(string prefix) {
        Node * node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->isContains(prefix[i])){
                return false;
            }
            node = node->Links[prefix[i]-'a'];
        }
        return true;
    }
};
