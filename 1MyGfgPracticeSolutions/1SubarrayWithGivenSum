#include<vector>
#include<iostream>
using namespace std;
vector<int> subarraySum(int arr[], int n, long long s){
        long long curr_sum=arr[0],start=0;
        vector<int> ans;
        
        for(int i=1;i<=n;i++){
            
            while(curr_sum > s && start< i-1 ){
                curr_sum = curr_sum - arr[start] ;
                start++;
            }
            
            if(curr_sum==s){
                ans.push_back(start+1);
                ans.push_back(i);
                return ans;
            }
            
            if(i<n){
                curr_sum = curr_sum + arr[i];
            }
            
            
            
        }
        ans.push_back(-1);
        return ans;
    }
int main(){

    int arr[] ={1,2,3,7,5};

    vector<int> ans = subarraySum(arr,5,12);

    for(int i=0;i<2;i++){
        cout<<ans[i]<<endl;
    }

}