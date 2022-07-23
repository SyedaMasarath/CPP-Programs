//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
         unordered_map<char, int> umap1;
         
         int n1= a.length();
         int n2= b.length();
         if(n1!=n2){
             return false;
         }
         for(int i=0;i<n1;i++){
             umap1[a[i]]++;
         }
        
        for(int i=0;i<n2;i++){
            if(umap1.find(b[i]) != umap1.end()){
                umap1[b[i]] -=1;
            }
        }
         
        for (auto items : umap1) {
         if (items.second != 0) {
            return false;
        }
      }
      
      return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

/*Input:a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have samecharacters with
        same frequency. So, both are anagrams. */