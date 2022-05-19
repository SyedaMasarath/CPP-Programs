#include <iostream>
#include<math.h>
using namespace std;

int main(){

int a=9,b=8;

char ch;
cin >> ch;

switch(ch){


    case '+': cout<<a+b<<"a+b is "<<endl;
              break;
    
    case '*': cout<<a*b<<"a*b is "<<endl;
              break;
    default: cout<<"no case";
}

}




