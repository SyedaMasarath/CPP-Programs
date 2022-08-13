#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  private:
    int getMin(string arr[],int N){
        
        int min=arr[0].length();
        for(int i=1;i<N;i++){
            if(arr[i].length()<min){
                min=arr[i].length();
            }
        }
        return min;
    }
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {   //get min length string size
        int min=getMin(arr,N);
        string result="";
        char current;
        
        for(int i=0;i<min;i++){
            
            current=arr[0][i];
            
            for(int j=1;j<N;j++){
                if(arr[j][i]!= current){
                   
                    if(result==""){
                        return "-1";
                     }
                    else{
                        return result;
                    }
                }
            }
            result.push_back(current);
        }
        
       return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}
