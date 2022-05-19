#include <iostream>
#include<math.h>
using namespace std;
    int reverse(int x) {
       int ans=0;
       
        int a;
        int i=0;
        while(x!=0){
            
            a = x%10;
            
            ans=ans*10+a;
            
            x=x/10;
            
            i++;
            
        }
        return ans ;
    }
    

int main(){
   int a= reverse(120);
   cout<<a<<endl;
}