//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node, int parent,vector<int> &disc,vector<int> &low,
  unordered_map<int,bool> &vis,vector<int>adj[], vector<int> &ap,int &timer){
      
      vis[node]=true;
      disc[node]=low[node]=timer++;
      
      int child=0;
      
      for(auto nbr : adj[node]){
          if(nbr==parent){
              continue;
          }
          
          if(!vis[nbr]){
              dfs(nbr,node,disc,low,vis,adj,ap,timer);
              
              //updatelow when return from call
              
              low[node]=min(low[node],low[nbr]);
              
              //check articulation point
              if(low[nbr]>= disc[node] && parent!=-1){
                  ap[node]=true;
              }
              child++;
          }
          else{
              //backedge
              low[node]=min(low[node],disc[nbr]);
          }
      }
      
      //handling 0
      if(parent==-1 && child>1){
          ap[node]=true;
      }
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> disc(V);
        vector<int> low(V);
        
        //vector<int> parent(V);
        unordered_map<int,bool> vis;
        
        vector<int> ap(V,0);
        
        for(int i=0;i<V;i++){
            disc[i]=-1;
            low[i]=-1;
        }
        int timer=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,disc,low,vis,adj,ap,timer);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(ap[i]==true){
                ans.push_back(i);
            }
        }
        if(ans.size()==0){
            return {-1};
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends