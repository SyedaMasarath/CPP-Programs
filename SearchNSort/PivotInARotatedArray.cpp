#include<iostream>
using namespace std;

int getPivot(int arr[]) {
        
        int s=0;
        int end=4;
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
        return s; //or e as well
    }

    int main(){

        int arr[]={7,8,1,2,3};
        int ans= getPivot(arr);

        cout<<"ans"<<ans;
    }
//the array is [1,2,4,5,9] now we rotate
//now arrays is =[5,9,1,2,4] we are in search of 1
//we compare mid with arr[0] , since arr[0] wll always 
//be greater than pivot but less than its next element

//so if mid>=arr[0] , we update start coz we want to go near ans
//if mid<arr[0] , we update end 
//since elemnts on right of mid are graeter than mid
//s0 updating end brings us closer to ans