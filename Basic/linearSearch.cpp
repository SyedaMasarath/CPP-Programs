#include<iostream>
using namespace std;

bool LinearSearch(int arr[], int key,int size){
    bool found=0;
    for(int i=0;i <size;i++){

        if(arr[i]==key){
            found=1;
        }
    }
    return found;

}

int main(){

    int arr[5]={1,8,5,6,7};
    bool ans= LinearSearch(arr,17,5);
    if(ans){
        cout<<"element found";
    }
    else{
        cout<<"not found";
    }
}