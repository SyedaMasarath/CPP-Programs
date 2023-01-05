//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//kosarajus algorithm to count stronly connected components in graph
//strongly connected cmp : any component in which you can reach all nodes ,from every node of cmp

//algo
//1.Get topo sort of graph in a stack
//2.transpose graph--> reverse direction of edges
//3.do dfs, count++ before each call(since it is called for unvis nodes)

class Solution
{
	public:
	void dfsTopo(int node,unordered_map<int,bool> &vis,vector<int> adj[],stack<int> &s){
	    vis[node]=true;
	    
	    for(auto nbr: adj[node]){
	        if(!vis[nbr]){
	            dfsTopo(nbr,vis,adj,s);
	        }
	    }
	    s.push(node);
	}
	
	void Revdfs(int node,unordered_map<int,list<int>> &newGraph,unordered_map<int,bool> &vis){
	    vis[node]=true;
	    
	    for(auto nbr: newGraph[node]){
	        if(!vis[nbr]){
	            Revdfs(nbr,newGraph,vis);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        unordered_map<int,bool> vis;
        stack<int> s;
        //1.toposort to get order
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsTopo(i,vis,adj,s);
            }
        }
        
        //2.transpose graph reveerse direction of edges
        
       unordered_map<int,list<int>> newGraph;
        for(int i=0;i<V;i++){
            vis[i]=0;
            
            for(auto nbr: adj[i]){
                newGraph[nbr].push_back(i);
            }
        }
        
        int count=0;
        
        //dfs on new graph
        while(!s.empty()){
            
            int top=s.top();
            s.pop();
            if(!vis[top]){
                Revdfs(top,newGraph,vis);
                count++;
            }
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends