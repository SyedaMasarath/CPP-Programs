//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        //create adjacency list
        unordered_map<int,list<int>> adj;
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        
        vector<int> dist(N);
        for(int i=0;i<N;i++){
            dist[i] = INT_MAX;
        }
        dist[src]=0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int front =q.front();
            q.pop();
            
            for(auto i:adj[front]){
                /*//agar mein apne node ke adjacent node mein jaa raha hu aur uske distance mein + 1 kar raha
                //aur wo less than hain distance of adjacent node toh adjacent node ke dist mein isko daal do
                //aur queue mein push kardo usko*/
                //this means that i is neighbor of front, and if i is accesses through front(ie. distance[front]+1) and 
                //this value is less than the original value stored in dist[i] then update dist[i]
                if(dist[front]+1 < dist[i]){
                    dist[i]=dist[front]+1;
                    q.push(i);
                }
            }
        }
         for(int i=0;i<dist.size();i++){
            if(dist[i] == INT_MAX)
            dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends