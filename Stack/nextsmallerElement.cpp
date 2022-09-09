#include<stack>
#include<iostream>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for(int i=n-1;i>=0;i--){

        int curr=arr[i];

            while(s.top() >= curr){
                
                s.pop();
            }
            ans[i]=s.top();
            s.push(arr[i]);
        }
    return ans;
}
/*
test case ip:
2
4
2 1 4 3
3
1 3 2

o/p:
1 -1 3 -1 
-1 2 -1 */

