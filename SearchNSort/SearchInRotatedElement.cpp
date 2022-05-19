#include<iostream>
using namespace std;
//code studio
int getPivot(int arr[],int n) {
        
        int s=0;
        int end=n-1;
        int mid= s +(end-s)/2;
        
        while(s<end){

            if(arr[mid] >= arr[0]){
                s = mid + 1;
            }
            else{
                end=mid;
            }
            
            mid= s +(end-s)/2;
        }
        return s; 
    }
int BinarySearch(int arr[],int start,int end,int key){

    int mid = start + (end - start)/2;
    while(start<= end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid -1;
        }
        else{
            start=mid+1;
        }

        mid = start + (end - start)/2;
    }
    return -1;
}

int findPosition(int arr[], int n, int k)
{
    int pivot=getPivot(arr,n);
    
    if(k>=arr[pivot] && k<=arr[n-1]){
        return BinarySearch(arr,pivot,n,k);
    }
    else{
        return BinarySearch(arr,0,pivot-1,k);
    }
    return -1;
       
}

