#include <iostream>
using namespace std;

int main(){
	int n = 5 << 1;

    //Left shifting mostly is n*2 
    //while in bigger no's it gives negative result 

    cout <<"Left shift 5 is " << n<<endl; 

    int rightshift = 5 >> 1;

    //Right shifting mostly is n/2 
 
    cout << "Right shift 5 is " << rightshift << endl;;

    int a = 5 & 4;
    cout<<"5 & 4 is "<< a<<endl; 

    int b =5 ^4;
    cout<<"5 xor 4 is "<<b<<endl;

    int c = ~5 ;
    cout <<"Not of 5 is "<<c<<endl;
    
    int v = 2 | 8;
    cout <<"2  or 8 is "<<v;

    }
    