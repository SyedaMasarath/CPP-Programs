//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
       priority_queue<int,vector<int>,greater<int>> pq;
       //push k elements in min heap
       for(int i=0;i<k;i++){
           pq.push(arr[i]);
       }
       
       //for remaining ele comp top with curr arr element if top is less, pop n push arr[i]
       for(int i=k;i<n;i++){
           if(pq.top()<arr[i]){
               pq.pop();
               pq.push(arr[i]);
           }
       }
       //now only k largest elements are left in heap store n return them
       vector<int> ans;
       for(int i=0;i<k;i++){
             ans.push_back(pq.top());
             pq.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends