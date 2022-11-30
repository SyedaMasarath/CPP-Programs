#include <bits/stdc++.h>
using namespace std;

vector<int> median(vector<int> &arr,int n){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    int median=0;

    for(int i=0;i<n;i++){
        callMedian(arr[i],maxHeap,minHeap,median);
        ans.push_back(median);
    }

    return ans;
}

int signum(int a,int b){
    if(a==b){
        return 0;
    }
    else if(a>b){
        return 1;
    }
    else{
        return 0;
    }
}

//real median calculated here

void callMedian(int ele,priority_queue<int> &maxi,priority_queue<int,vector<int>,greater<int>> &mini,int &median){

    //get sizes of both heaps to decide in which heap to add the curr element 
    //on the basis of that new median is calculated

    switch(signum(maxi.size(),mini.size())){
        
        case 0: if(ele>median){
            mini.push(ele);
            median=mini.top();
        }
        else{
            maxi.push(ele);
            median=maxi.top();
        }
        break;

        case 1: if(ele>median){
            mini.push(ele);
            median= (mini.top() + maxi.top())/2;
        }
        else{
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(ele);
             median= (mini.top() + maxi.top())/2;
        }
        break;


        case -1: if(ele> median){
            maxi.push(mini.top());
            mini.pop();
            mini.push(ele);
            median= (mini.top() + maxi.top())/2;
        }
        else{
            maxi.push(ele);
            median= (mini.top() + maxi.top())/2;
        }

    }
}