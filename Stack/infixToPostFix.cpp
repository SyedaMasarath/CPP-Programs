//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int precedence(char ch){
        if(ch=='^'){
            return 3;
        }
        else if(ch=='/' || ch=='*'){
            return 2;
        }
        else if(ch=='+' || ch=='-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string ans="";
        stack<char> st;
        for(int i=0;i<s.length();i++){
            
            char ch=s[i];
            
            if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') ){
                ans.push_back(s[i]);
            }
            
            else if(ch=='('){
               st.push('(');
            }
            
            else if(ch==')') {
                
                while(st.top()!= '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop(); //popping opening brace
            }
            
            else{
                while(!st.empty() && precedence(ch) <= precedence(st.top()) ){
                    
                    ans.push_back(st.top());
                    st.pop();
                }
                
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends