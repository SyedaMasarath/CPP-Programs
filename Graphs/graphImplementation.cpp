#include <bits/stdc++.h>
using namespace std;

class Graph{

    public:
        unordered_map<int,vector<int>> adj;

    void insertEdge(int u,int v,bool direction){
        //graph is directional or bidirectional 
        // 0 - undirected
        // 1 - directed
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i:adj){
            cout<<i.first<< "->";
            for(auto j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    int n;
    cout<<"no of vertex";
    cin>>n;

    int m;
    cout<<"no of edges";
    cin>>m;

    Graph g;

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g.insertEdge(u,v,0);
    }
    g.printGraph();
    return 0;
}