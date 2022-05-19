#include<iostream>
#include<math.h>
using namespace std;

int findDuplicates(int nums[]) {
        
    int ans=0;
    
    for(int i=0; i<6; i++){
        ans=ans^nums[i];
    }
    
    for(int i =1;i<6;i++){
        ans=ans^i;
    }
    
    return ans;
	
    }


int main(){
int arr[]={1,2,3,4,5,5};

int ans=findDuplicates(arr);

cout<<"ans is"<<ans;


}