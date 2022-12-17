//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(int node,vector<int> adj[],unordered_map<int,bool> &vis,int parent){
       
        vis[node]=1;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                bool cycle=solve(i,adj,vis,node);
                
                if(cycle){
                    return true;
                }
            } // i is visted but its not a parent to node
            else if(i!=parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool> vis;
        
        //for loop is used to make sure that all components of graph are checked,
        //if components are unconnected or dont have an edge connecting them
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans= solve(i,adj,vis,-1);
                if(ans==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends