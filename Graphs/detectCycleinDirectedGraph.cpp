//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool solve(int node,vector<int> adj[],unordered_map<int,bool> &vis,unordered_map<int,bool> &DFSVis){
        
        vis[node]=true;
        DFSVis[node]=true;
        
        for(auto i: adj[node]){
            if(!vis[i]){
                
                bool cycle=solve(i,adj,vis,DFSVis);
                
                if(cycle){
                    return true;
                }
            }
            else if(DFSVis[i]){
                return true;
            }
        }
        
        DFSVis[node]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int,bool> vis;
        unordered_map<int,bool> DFSVis;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans=solve(i,adj,vis,DFSVis);
                if(ans==true){
                    return true;
                }
            }
        }
        return false;
        //return solve(0,adj,vis,DFSVis);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends