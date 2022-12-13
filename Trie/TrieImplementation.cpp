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

        // Recursive function to delete a key from given Trie
TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
    // If tree is empty
    if (!root)
        return NULL;
 
    // If last character of key is being processed
    if (depth == key.size()) {
 
        // This node is no more end of word after
        // removal of given key
        if (root->isTerminal)
            root->isTerminal = false;
 
        // If given is not prefix of any other word
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }
 
        return root;
    }
 
    // If not last character, recur for the child
    // obtained using ASCII value
    int index = key[depth] - 'a';
    root->children[index] =
          remove(root->children[index], key, depth + 1);
 
    // If root does not have any child (its only child got
    // deleted), and it is not end of another word.
    if (isEmpty(root) && root->isTerminal == false) {
        delete (root);
        root = NULL;
    }
 
    return root;
}   
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < 26; i++)
        if (root->children[i])
            return false;
    return true;
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