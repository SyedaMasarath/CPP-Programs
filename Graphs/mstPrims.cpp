//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> parent(V+1);
        vector<bool> mst(V+1);
        vector<int> key(V+1);
        
        for(int i=0;i<V;i++){
            parent[i]=-1;
            key[i]=INT_MAX;
            mst[i]=false;
        }
        
        key[0]=0;
        parent[0]=-1;
        
        for(int i=0;i<V;i++){
            int mini=INT_MAX;
            
            int u;
            //find min node from array
            for(int c=0;c<V;c++){
                //not visited     //minimum
                if(mst[c]==false && key[c]<mini){
                    u=c;
                    mini=key[c];
                }
            }
            mst[u]=true;
            
            //checking adj nodes
            for(auto it: adj[u]){
                int x= it[0];
                int w= it[1];
                
                if(mst[x]==false && w<key[x]){
                    parent[x]=u;
                    key[x]=w;
                }
            }
        }
        
        int ans=0;
        for(int i = 0 ; i < V ; i++){
            ans += key[i];
        }
        return ans;
        
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends