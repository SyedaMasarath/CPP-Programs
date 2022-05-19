#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "enter number "<< endl;
	cin >> n;
    int row=1;
    
    while(row<=n){

       int space= n-row;

        while(space){
           cout<<" ";
           space--;
       }
      

       int col=1;
       while(col<=row){
           cout<<"*";
           col++;
       }

       cout<<endl;
       row++;
    }
}