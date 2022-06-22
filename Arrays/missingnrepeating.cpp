#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
 void print(int *temp, int n)
{for(int i=0;i<n;i++){
    cout <<temp[i]<<"  ";
}}


 int *findTwoElement(int *arr, int n) {

    int* ans= new int[2];

    int temp[n+1]={0};

    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(temp[i]==2){
            ans[0]=i;
            //repeatng number
        }

        if(temp[i]==0){
            ans[1]=i;
            //missing number
        }
    }
    print(temp,n);
    return ans;
 }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends