#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

void selectionsort(int arr[],int size)
{
    for(int i=0;i<size-1;i++){
        int minIndex = i;
        for(int j=i+1;j< size;j++){

            if(arr[j] < arr[minIndex]){

                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main(){

    int arr[]={5,6,7,8,1,2,9};

    selectionsort(arr,7);

    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

}