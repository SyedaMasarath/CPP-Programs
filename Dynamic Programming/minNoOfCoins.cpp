#include<bits/stdc++.h>
using namespace std;
/*You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.*/

class Solution {
public:
int solveMem(vector<int>& coins, int amount,vector<int> &dp){
    //base case
    if(amount ==0){
        return 0;
    }

    //amount out of bound
    if(amount<0){
        return INT_MAX;
    }
    
    //memoization
    if(dp[amount]!=-1){
        return dp[amount];
    }

    //min no of coins needed to make amount
    int mini=INT_MAX;
    //try to make amount using every coin ,like a recursion tree  
    for(int i=0;i<coins.size();i++){
        //try making amount using each coin
        int ans=solveMem(coins,amount-coins[i],dp);

        //if ans is not invalid
        if(ans!=INT_MAX){
            //amount++ add curr coin to min no of coins
            mini= min(mini,1+ans);
        }
    }

    dp[amount]=mini;
    return dp[amount];
}
    
    int coinChange(vector<int>& coins, int amount) {
        //initialise dp array with -1
        vector<int> dp(amount+1,-1);

        int ans= solveMem(coins,amount,dp);
        //if cant make amount using given coins return -1
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};

/*            7    
           
           1/ 2\ 3\
           6   5  4    
         1/ 2/  3\  
         5  4   3
      ....................
      just like that for each coin, each coin is called



*/         


