#include<iostream>
#include<math.h>
using namespace std;
int printArray(int arr[], int size){

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void sort012(int arr[], int size){

    int left=0;
    int right=size-1;
    int mid=0;

    while(mid<=right){

        if(arr[mid]==0){
            swap(arr[left],arr[mid]);
            left++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[right]);
            right--;
        }
    }

}


int main(){
int arr[]={0,0,1,0,1,2,2,0,1,0};
sort012(arr,9);
printArray(arr,9);
}
