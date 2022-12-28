//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node,int parent,vector<int> adj[],vector<int> &disc,vector<int> &low,unordered_map<int,bool> &vis,int &timer,vector<vector<int>> &result)
	{
	    
	    vis[node]=true;
	    disc[node]=low[node]=timer++;
	    
	    for(auto nbr: adj[node]){
	        
	        if(nbr==parent){
	            continue;
	        }
	        
	        if(!vis[nbr]){
	            dfs(nbr,node,adj,disc,low,vis,timer,result);
	            
	            low[node]=min(low[node],low[nbr]);
	            
	            if(low[nbr]>disc[node]){
	                vector<int> ans;
	                ans.push_back(node);
	                ans.push_back(nbr);
	                result.push_back(ans);
	            }
	        }
	        else{
	            low[node]=min(low[node],disc[nbr]);
	        }
	    }
	    
	}
    //Function to find if the given edge is a bridge in graph.
    vector<vector<int>> isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> disc(V);
        vector<int> low(V);
        unordered_map<int,bool> vis;
        int timer=0;
        
        for(int i=0;i<V;i++){
            disc[i]=-1;
            low[i]=-1;
        }
        
        vector<vector<int>> result;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,adj,disc,low,vis,timer,result);
            }
        }
        
        return result;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	//cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends