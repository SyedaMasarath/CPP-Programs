#include<iostream>
#include<math.h>
using namespace std;

/*
int swapAlternate(int arr[] , int size){
    int i=0;
    while(i < size){

        swap(arr[i],arr[i+1]);
        i=i+2;

    }
}*/

int swapAlternate(int arr[], int size){

    for(int i=0; i <size ;i=i+2){

        if(i+1<size){
            swap(arr[i],arr[i+1]);

        }
    }
}

int printArray(int arr[], int size){

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={1,2,3,4,5,6};

    swapAlternate(arr,6);

    printArray(arr, 6);



}