#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
       priority_queue<int, vector<int>, greater<int>> pq;
       for(int i=l; i<=r; i++){
           pq.push(arr[i]);
       }
       for(int i=0; i<k-1; i++){
           pq.pop();
       }
       return pq.top();
   }

//do using binary searchs as well

