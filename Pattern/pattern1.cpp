#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "enter number "<< endl;
	cin >> n;
	int row =1;
	while(row <= n){
		int j =1;
		while(j<=n){
			cout << '*';
			j++;
		}
	cout << endl;
	row++;
	}
}