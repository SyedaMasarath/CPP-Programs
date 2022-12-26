#include<bits/stdc++.h>
using namespace std;

 int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> vis(V,0);
        vector<pair<int,int>> mst;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
                //wt, node , parent
        pq.push({0,{0,-1}});
        
        int sum=0;
        while(pq.size()){
            int dis = pq.top().first; //wt
            int node = pq.top().second.first; //node
            int parent = pq.top().second.second;
            pq.pop();
            
            if(vis[node])continue;            
            if(parent!= -1)
             mst.push_back({node,parent});
            vis[node] = 1;
            sum += dis;
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeW = it[1];
                
                if(!vis[adjNode]){
                    pq.push({edgeW,{adjNode,node}});
                }
            }
        }
        // printing mst
        // for(auto it : mst){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        return sum;
    }

