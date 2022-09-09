#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
   
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for(int i=n-1;i>=0;i--){

        int curr=arr[i];

            while(s.top()!=-1 && arr[s.top()] >= curr){
                
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
    return ans;
}
    

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
     stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for(int i=0;i<n;i++){

      int curr=arr[i];

            while(s.top()!=-1 && arr[s.top()] >= curr){
                
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
    return ans;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> next(n);
        next=nextSmallerElement(heights,n);
        
        vector<int> prev(n);
        prev= prevSmallerElement(heights,n);
        int area= INT_MIN;
        for(int i=0;i<n;i++){
            //if all vals in histogram are same then next becomes -1, which gives ans in -ve eg:[2,2,2,2]
            if(next[i]==-1){
                next[i]=n;
            }
            int b= next[i]-prev[i]-1;
            int newArea=b*heights[i];
            
            area=max(newArea,area);
            
        }
        
        return area;
    }
};

/*
Input: heights = [2,4]
Output: 4
*/