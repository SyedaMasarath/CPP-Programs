#include<iostream>
using namespace std;
long long int binarySearch(long long int N){
    int start=0;
    int end= N;
    long long int ans=-1;
    long long int mid = start + (end - start)/2;
        
    while(start <=end){
        long long int square=mid*mid;
        
        if(square == N) {
            return mid;
        }
        
        if(square < N){
             ans=mid;
             start=mid+1;
        }
        else{
           end = mid-1;
        }
        
        mid = start + (end - start)/2;
    }
  return ans;  
}
    
int mySqrt(int x) {
    return binarySearch(x); 
}

//precison can be calculated using bruteforce