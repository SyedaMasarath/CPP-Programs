//leetcode
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); //no of rows
        int n= matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(matrix[i][j]==0){
                    
                    for(int p=0;p<n;p++){
                        if(matrix[i][p]!=0)
                        {
                            matrix[i][p]=-178900;
                        }
                    }
                    
                    for(int q=0;q<m;q++){
                        if(matrix[q][j]!=0)
                        { 
                            matrix[q][j]=-178900;
                        }    
                    }
                }
            }   
        }
        
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(matrix[i][j] == -178900){
                    matrix[i][j]=0;
                }
                
            }
          }
    }
};
