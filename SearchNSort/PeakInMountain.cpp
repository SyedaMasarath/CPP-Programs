#include<iostream>
using namespace std;

    int peakIndexInMountainArray(int arr[],int size) {
        
        int s=0;
        int end=size-1;
        int mid= s +(end-s)/2;
        
        while(s<end){

            if(arr[mid] < arr[mid+1]){
                s = mid + 1;
            }
            else{
                end=mid;
            }

            mid= s +(end-s)/2;
        }
        return s;
    }

int main(){

        int arr[]={0,2,1,0};
        int ans= peakIndexInMountainArray(arr,4);

        cout<<"ans"<<ans;
    }