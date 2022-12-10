//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Trienode{
    public:
        char data;
        Trienode* children[26];
        bool isTerminal;


    Trienode(char ch){
        ch=data;

        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }

};

class Trie{
    public:
    Trienode* root;

    Trie(){
        root = new Trienode('\0');
    }

    void insertUtil(string word){
        insertWord(root,word);
    }

    void insertWord(Trienode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        //extract index where we have to insert char
        int index=word[0]-'a';
        Trienode* child;

        //if char already present move to that 
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //if not present 
            child=new Trienode(word[0]);
            root->children[index]=child;
        }
        insertWord(child,word.substr(1));
    }

    void printSuggestions(Trienode* curr,vector<string> &temp,string prefix){
        //base case
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        
        for(char ch='a';ch<='z';ch++){
            Trienode* next=curr->children[ch-'a'];
            
            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> solve(string query){
        Trienode* prev = root;
        vector<vector<string>> output;
        
        string prefix="";
        
        for(int i=0;i<query.length();i++){
            char ch=query[i];
            prefix.push_back(ch);
            
            Trienode* curr= prev->children[ch-'a'];
            if(curr==NULL){
                break;
            }
            
            vector<string> temp;
            printSuggestions(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;
        
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie *contacts=new Trie();
        
        for(int i=0;i<n;i++){
            contacts->insertUtil(contact[i]);
        }
        
        return solve(s);
    }

};
//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends