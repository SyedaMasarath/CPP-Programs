#include <iostream>
using namespace std;

int primenumber(int n){
bool isprime=1;
    for(int i =2; i<n ;i++){

        if(n%i ==0){
            isprime=0;
            break;
        } 
    }
    return isprime;
}

int main(){
    int n = 7;
    cin >> n;
    int a = primenumber(n);

    if(a==0){
        cout << "Not prime";
    }
    else{
        cout <<"Prime";
    }
}