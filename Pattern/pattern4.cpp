#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "enter number "<< endl;
	cin >> n;


	int row =1;

	while(row <= n){

        int temp=n;
		int j =1;
		while(j<=n){
			cout << temp << " "; // or n-j+1
			j++;
            temp--;
		}
	cout << endl;
	row++;
	}
}
//square of numbers from n to 1