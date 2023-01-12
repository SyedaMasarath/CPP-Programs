#include<bits/stdc++.h>
using namespace std;

//problem:You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
//Once you pay the cost, you can either climb one or two steps.
//You can either start from the step with index 0, or the step with index 1.
//Return the minimum cost to reach the top of the floor.

//Approach1 : Todp Down : Recursion + Memoization
class Solution {
public:
    int solve(vector<int>& cost,vector<int>& dp,int step){
        if(step==0){
            return cost[0];
        }
        if(step==1){
            return cost[1];
        }

        //step 3: if ans present return ans 
        if(dp[step]!=-1){
            return dp[step];
        }
        //step2: save ans for recursive calls
        dp[step]=cost[step] + min(solve(cost,dp,step-1),solve(cost,dp,step-2));
        return dp[step];
    }

    int minCostClimbingStairs(vector<int>& cost) {
      int n= cost.size();
      //step1 create dp array
      vector<int> dp(n+1,-1);

      int ans= min(solve(cost,dp,n-1),solve(cost,dp,n-2));

      return ans;  
    }
};

//Approach 2: bottom up/tabulation
class Solution {
public:
    int solve2(vector<int>& cost,int n){
     //tabulation : craete dp array
      vector<int> dp(n+1);
      //step1: analyse base case
      dp[0]=cost[0];
      dp[1]=cost[1];

      for(int i=2;i<n;i++){
          dp[i]=cost[i] + min(dp[i-1],dp[i-2]);
      }

      return min(dp[n-1],dp[n-2]);  
    }

    int minCostClimbingStairs(vector<int>& cost) {
      int n= cost.size();

      return solve2(cost,n);
    }
};

//space optimised approach
class Solution {
public:
    int solve2(vector<int>& cost,int n){
      //step1: analyse base case store in variables
      //we need only prev 2 vals
      int prev1=cost[0];
      int prev2=cost[1];

      for(int i=2;i<n;i++){
          int curr=cost[i] + min(prev2,prev1);
          prev1=prev2;
          prev2=curr;
      }

      return min(prev1,prev2);  
    }

    int minCostClimbingStairs(vector<int>& cost) {
      int n= cost.size();

      return solve2(cost,n);
    }
};