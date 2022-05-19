#include <iostream>
using namespace std;

//0,1,1,2,3,5,8
int Fibo(int n){

    int frst = 0;
    int second = 1;
    int third;
    cout << " "<< frst <<" " << second ;
    for(int i=1; i<=n; i++){

        third = frst + second;
        cout << " "<<third;

        frst= second;
        second = third;

    }
    return 1;
}


int main(){
    Fibo(17);
}