
#include<vector>
#include<iostream>
using namespace std;

void solve(string str,vector<string>& ans, int index, string output){
	
	if(index>=str.length()){
		if(output.length()>0){
			ans.push_back(output);
		}
		return;
	}
	
	solve(str,ans,index+1,output);
	
	char ch=str[index];
	output.push_back(ch);
	solve(str,ans,index+1,output);
}


vector<string> subsequences(string str){
	vector<string> ans;
	string output;
	int index=0;
	
	solve(str,ans,index,output);
	return ans;
	
}
int main(){

    string str="abc";

    vector<string> nums=subsequences(str);

    for (int i = 0; i < nums.size(); i++) {
        
            cout << nums[i] << " ";
        
    }
}
