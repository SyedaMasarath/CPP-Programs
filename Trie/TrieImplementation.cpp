#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;


    TrieNode(char ch){
        ch=data;

        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }

};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(string word){
        insertWord(root,word);
    }

    void insertWord(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        //extract index where we have to insert char
        int index=word[0]-'a';
        TrieNode* child;

        //if char already present move to that 
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //if not present 
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertWord(child,word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'a';
        TrieNode* child;

        //if char already present move to that 
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //if not present 
            return false;
        }

        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }

    void removeWord(){
        
    }

};

int main(){
    Trie* t=new Trie();

    t->insertUtil("arm");
    t->insertUtil("do");
    cout<<"trie created";
    cout<<"word exists"<< " "<<t->searchWord("arm")<<" ";
    return 0;
}