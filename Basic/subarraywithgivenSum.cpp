#include<vector>
#include<iostream>
using namespace std;

vector<int> subarraySum(int arr[], int n, long long s)
    {
        
        int startIndex=0;
        int endIndex=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
           int sum=0;
           for(int j=i; j<n;j++)
            {   
               sum = sum + arr[j]; 
               if(sum==s){
                   ans.push_back(i);
                   ans.push_back(j);
                   return ans;
               }
            }
        }
    }
int main(){

    int arr[] ={1,2,3,7,5};

    vector<int> ans = subarraySum(arr,5,12);

    for(int i=0;i<2;i++){
        cout<<ans[i]<<endl;
    }

}