#include <iostream>
#include<math.h>
using namespace std;

int main(){
    int ans=0;
    int i=0;
    int n=7;
    while(n != 0){

        int bit = n & 1; //gives the last bit..
        
        ans = (bit * pow(10,i) ) + ans;
        
        n = n >> 1; //right shift to get the next bit
        i++;

    }
    cout<<"ans is "<<ans<<endl;
}
