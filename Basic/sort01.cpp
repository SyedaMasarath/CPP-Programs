#include<iostream>
#include<math.h>
using namespace std;

int printArray(int arr[], int size){

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void sort01(int arr[], int n)
{
  int i=0,j=n-1;
  
    while(i<=j && i<j){
        while(arr[i]==0){
            i++;
        }
        while(arr[j]==1 && i<j){
            j--;
        }
        //arr[i]==1 && arr[j]==0 &&
        if( i<j){
			swap(arr[i],arr[j]);
                   i++;
                   j--;
         }
    }   
}
int main(){
int arr[]={0,0,1,0,1,0,1};

sort01(arr,7);
printArray(arr,7);

}