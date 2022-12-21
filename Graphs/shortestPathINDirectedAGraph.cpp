//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void topo(int node,unordered_map<int,list<pair<int,int>>> &adj,stack<int> &s,unordered_map<int,bool> &vis){
        vis[node]=true;
        for(auto i:adj[node]){
            if(!vis[i.first]){
                topo(i.first,adj,s,vis);
            }
        }
        s.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,list<pair<int,int>>> adj;
        
        for(int i=0;i<M;i++){
            int u= edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back(make_pair(v,w));
        }
    
        //shortest path in DAG Weighted
        
        //step1 : topo se sequence nikalo
        unordered_map<int,bool> vis;
        stack<int> s;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topo(i,adj,s,vis);
            }
        }
        
        //now we have a stack
        vector<int> dist(N);
        for(int i=0;i<N;i++){
            dist[i]=INT_MAX;
        }
        
        dist[0]=0;
        
        while(!s.empty()){
            int temp=s.top();
            s.pop();
            
            if(dist[temp]!=INT_MAX){
                for(auto i:adj[temp]){
                    if(dist[temp] +i.second < dist[i.first]){
                            dist[i.first]=dist[temp]+i.second;
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends