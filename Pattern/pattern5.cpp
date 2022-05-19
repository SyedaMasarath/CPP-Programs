#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "enter number "<< endl;
	cin >> n;
    int row =1;
    int count=1;
    while(row<=n){
        int col=1;

        while(col<=n){
            cout<<count<<" ";
            col++;
            count++;
        }
        cout<<endl;
        row++;

    }




}