#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int max1=0,jump=0,halt=0;
        //int* jumps = new int[n];
        if(n<=1 && arr[0]==0){
            return 0;
        }
        
        if(arr[0]==0){
            return -1;
        }
     
       for(int i=0;i<n-1;i++){
           max1=max(max1,arr[i]+i);
           
           if(max1>= n-1){
               jump+=1;
               return jump;
           }
           
           if(i==halt){
               halt = max1;
               jump++;
           }
       }
       if(halt>=n-1){
           return jump;
       }
       
       return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends