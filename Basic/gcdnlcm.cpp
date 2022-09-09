//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  
   long long gcd(long A,long B){
       if(B==0){
           return A;
       }
       
       return gcd(B,A%B);
   }
   
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
       long long gcd1= gcd(A,B);
       
       long long lcm1=(A*B)/gcd1;
       //long long lcm1=lcm(A,B);
       
       vector<long long> ans;
       ans.push_back(lcm1);
       ans.push_back(gcd1);
       
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends