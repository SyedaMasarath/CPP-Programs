//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n= S.length();
        int j=0;
       for(int i = 0; i <n/2;i++)
        {
            swap(S[i],S[n-i-1]);
        }
        
        for(int i=0;i<=n;i++){
            
            if(S[i]=='.' || S[i]=='\0'){
                
                for(int begin=j,end=i-1 ; begin<(i+j)/2 ; begin++,end--)
                    {
                        swap(S[begin],S[end]);
                    }
                j=i+1;
            }
        }
        
      return S;  
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}