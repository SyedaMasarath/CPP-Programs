int main(){
	int n;
	cout << "enter number "<< endl;
	cin >> n;
    int row=1;
    
    while(row<=n){

        int space = n-row;

        while(space){
            cout<<" ";
            space--;
        }