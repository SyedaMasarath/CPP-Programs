//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	bool dfs(int node,int parent,vector<int> adj[],vector<int> &disc,
	vector<int> &low,unordered_map<int,bool> &vis,int &timer,int c,int d)
	{
	    
	    vis[node]=true;
	    disc[node]=low[node]=timer++;
	    
	    for(auto nbr: adj[node]){
	        
	        if(nbr==parent){
	            continue;
	        }
	        
	        else if(!vis[nbr]){
	            if(dfs(nbr,node,adj,disc,low,vis,timer,c,d))
	            { return true;}
	            
	            low[node]=min(low[node],low[nbr]);
	            
	            if(low[nbr]>disc[node]){
	                if((node==c && nbr==d) || (node==d && nbr==c))
	                {
	                    return true;
	                }
	            }
	        }
	        else{
	            low[node]=min(low[node],disc[nbr]);
	        }
	    }
	    return false;
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> disc(V);
        vector<int> low(V);
        unordered_map<int,bool> vis;
        int timer=0;
        
        for(int i=0;i<V;i++){
            disc[i]=-1;
            low[i]=-1;
        }
        
       
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,disc,low,vis,timer,c,d))
                {
                    return 1;
                }
            }
        }
        
        return 0;
        
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
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends