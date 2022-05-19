vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        
        for(int j=i+1; j<n; j++){
            
            for(int m=j+1; m<n; m++){
            
                    if(arr[i] + arr[j]+ arr[m] == K){
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[m]);
                        ans.push_back(temp);
            }
          }
        }
    }
    //sort(ans.begin(),ans.end());
    return ans;
}