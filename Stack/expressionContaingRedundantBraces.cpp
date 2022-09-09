//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        
        stack<char> stack;
        
        for(int i=0;i<s.length();i++){
            char ch= s[i];
            
            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                stack.push(ch);
            }
            
            else{
                
                if(ch==')'){
                    
                    bool isRedundant=true;
                    
                    while(stack.top() != '(')
                   { 
                      char top=stack.top();
                    
                      if(top=='+' || top=='-' || top=='*' || top=='/'){
                        isRedundant=false;
                      }
                      stack.pop();
                   }
                   
                   if(isRedundant==true){
                       return true;
                   }
                   stack.pop();
                }
            }
        }
        
        return false;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends