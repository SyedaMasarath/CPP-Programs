#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

void bubblesort(int arr[],int size){

    for(int i=1;i<size;i++){
        bool swapped=false;
        for(int j=0; j< size-i;j++){
            
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }

        }
        
        if(swapped==false){
        break;}
    }

}


int main(){

    int arr[]={5,6,7,8,1,2,9};

    bubblesort(arr,7);

    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

}