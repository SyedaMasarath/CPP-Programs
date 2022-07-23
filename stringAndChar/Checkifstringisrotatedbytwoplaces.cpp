//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{   private:
 
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
      
       int n= str1.length();
       if (str1.length() != str2.length())
        {
            return false;
            
        }
       bool clock=true,anticlock =true;
       cout<<"n is" <<n<<endl;
       for(int i=0;i<n;i++){
           
           if(str1[i]!= str2[(i+2)%n]){
               clock=false;
               break;
           }
       }
       
       for(int i=0;i<n;i++){
           if(str1[(i+2)%n]!= str2[i]){
               anticlock=false;
               break;
           }
       } 
       
       return clock or anticlock;
        
        
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
        cout<<"give input";
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}