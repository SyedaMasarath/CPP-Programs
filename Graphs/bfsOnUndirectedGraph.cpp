//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> solve(int v,vector<int> adj[],unordered_map<int,bool> &vis){
        queue<int> q;
        vector<int> ans;
        
        q.push(0);
        vis[0]=1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            //vis[front]=1;
            
            for(auto i: adj[front]){
                if(!vis[i])
               { 
                   q.push(i); 
                   vis[i]=1;
               }
            }
        }
        return ans;
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
       unordered_map<int,bool> vis;
       
       return solve(V,adj,vis);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends