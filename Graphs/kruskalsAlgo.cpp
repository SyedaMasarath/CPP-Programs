#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //custom comparator
    bool cmp(vector<int> &a,vector<int> &b){
        return a[2] <b[2];
    }

    void makeset(vector<int> &parent,vector<int> &rank,int n){
        for(int i=0;i<n;i++){
            //initially each components is its own parent n rak =0;
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findParent(vector<int> &parent,int node){
        //gpoing up to find a node whose parent is itself , since this is the node which is the root/parent
        if(parent[node]==node){
            return node;
        }
        //path compression, find parent n update the parent for curr node
        return parent[node]=findParent(parent,parent[node]);
    }

    //Function to merge two nodes a and b.
    void unionset( int a, int b, vector<int> &parent, vector<int> &rank1) 
    {
        a=findParent(parent,a);
        b=findParent(parent,b);
        //node with high rank becomes parent to less ranked node
        if(rank1[a]<rank1[b]){
            parent[a]=b;
        }
        else if(rank1[b]<rank1[a]){
            parent[b]=a;
        }
        else{
            //if ranks are equal anynode becomes parent to the other node
            parent[b]=a;
            rank1[a]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, vector<int> &parent, vector<int> &rank1)
    {
        int a=findParent(parent,x);
        int b=findParent(parent,y);
        
        if(a==b){
            return true;
        }
        return false;
    }

    int minSpanTree(vector<vector<int>> &edges,int n){
        //step1:sort edges on basis of weight
        sort(edges.begin(),edges.end(),cmp);

        //create and initialise arrays
        vector<int> parent(n);
        vector<int> rank(n);
        makeset(parent,rank,n);

        int minweight=0;

        //process edges
        for(int i=0;i<edges.size();i++){

            int u=findParent(parent,edges[i][0]); // u v wt [matrix]
            int v=findParent(parent,edges[i][1]); 
            int wt = edges[i][2];

            //if diff parents , merge nodes 
            if(u!=v){
                minweight+=wt; // add edge wt to mst total
                unionset(u,v,parent,rank);
            }
            //if same parent nodes already in same component so kip the edge
        }
        return minweight;

    }

};
