#include<iostream>
#include<math.h>
using namespace std;

int BinarySearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
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

int main(){

    int arr[]={1,3,5,7,8,9,19};
    int ans = BinarySearch(arr,7,9);

    cout<<"element found !! ans is"<<ans;
}