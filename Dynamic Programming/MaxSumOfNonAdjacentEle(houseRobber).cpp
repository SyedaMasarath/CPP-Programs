#include<bits/stdc++.h>
using namespace std;
/*
You are a professional robber planning to rob houses along a street.
 Each house has a certain amount of money stashed, the only constraint stopping you 
 from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.
*/
class Solution {
public:
    int solve1(vector<int>& nums,vector<int>& dp,int n){
        //return if array exceeded
        if(n<0){
            return 0;
        }
        //single house to rob
        if(n==0){
            return nums[0];
        }
        //ans already saved
        if(dp[n]!=-1){
            return dp[n];
        }
        //include curr element and call for non adjacent element i.e n-2
        int inc=solve1(nums,dp,n-2) + nums[n];
        //exclude curr ele n call for adjacent element, ie. n-1
        int exclude = solve1(nums,dp,n-1) + 0;

        //save ans
        dp[n]= max(inc,exclude);
        return dp[n];

    }

    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n+1,-1);
        //start from right to left
        int ans = solve1(nums,dp,n-1);
        return ans;
    }
};