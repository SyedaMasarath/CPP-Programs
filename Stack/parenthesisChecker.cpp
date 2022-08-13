#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
       stack<char> st;
       
       for(int i=0;i<x.length();i++){
           
           if( x[i]=='{' || x[i]=='(' || x[i]=='[' ){
               
               st.push(x[i]);
           }
           
           else{
               
               if(!st.empty())
               {
                   char ch=st.top();
               
                   if( (ch=='{' && x[i]=='}')  ||  (ch=='(' && x[i]==')') || (ch=='[' && x[i]==']') ){
                       
                       st.pop();
                   }
                   else{
                       return false;
                     }
                }
               else
               {
                   return false;
               }
           }
       }
       
       if(st.empty()){
           return true;
       }
       else{
           return false;
       }
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends