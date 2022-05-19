#include<iostream>
#include<math.h>
using namespace std;

int firstOcc(vector<int>& arr,int size,int key){
    int start=0;
    int end=size-1;
    int mid = start + (end - start)/2;
    int ans=-1;
    while(start <= end){
        if(arr[mid]==key){
            ans= mid;
            end= mid-1;
        }
        else if(arr[mid]>key){
            end=mid -1;
        }
        else{
            start=mid+1;
        }

        mid = start + (end - start)/2;
    }
    return ans;
}
int lastOcc(vector<int>& arr,int size,int key){
    int start=0;
    int end=size-1;
    int mid = start + (end - start)/2;
    int ans=-1;
    while(start <= end){
        if(arr[mid]==key){
            ans= mid;
            start = mid+1;
        }
        else if(arr[mid]>key){
            end=mid -1;
        }
        else{
            start=mid+1;
        }

        mid = start + (end - start)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;
    p.first = firstOcc(arr,n,k);
    p.second = lastOcc(arr,  n,k);
    return p;
}
/*You have been given a sorted array/list
 ARR consisting of ‘N’ elements. You are also given
  an integer ‘K’.
Now, your task is to find the first and last occurrence
 of ‘K’ in ARR.
 For example, if ARR = [0, 1, 1, 5] and K = 1, then the first 
 and last occurrence of 1 will be 1(0 - indexed) and 2.*/

 //we can find total no of occurences as well since array is sorted 
 //find frst and last occcurence by last occ - frst occ + 1