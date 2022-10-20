//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    Node* createMapping(Node* root, map<Node*,Node*> &nodeToParent,int target){
        Node *res=NULL;
        
        queue<Node*> q;
        q.push(root);
        nodeToParent[root]=NULL;
        
        while(!q.empty()){
            Node *front =q.front();
            q.pop();
            
            if(front->data==target){
                res=front;
            }
            
            if(front->left){
                nodeToParent[front->left]=front;
                q.push(front->left);
            }
            
            if(front->right){
                nodeToParent[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int solve(Node *root, map<Node*,Node*> &NodeToParent){
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root]=1;
        int ans=0;
        
        while(!q.empty()){
            //flag to keep track of insertion in q
            bool flag=0;
            
            int size=q.size();
            for(int i=0;i<size;i++){
                //processing all neighbours of a node together since it burns all neighbours in 1 sec
                Node *front=q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=1;
                    flag=1;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=1;
                    flag=1;
                }
                //parent not visited yet
                if(NodeToParent[front] && !visited[NodeToParent[front]]){
                    q.push(NodeToParent[front]);
                    visited[NodeToParent[front]]=1;
                    flag=1;
                }
            }
            if(flag==1){
                ans++;
            }
        }
     return ans;   
    }
    
    
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*> NodeToParent;
        Node *targetnode=createMapping(root,NodeToParent,target);
        
        int ans= solve(targetnode,NodeToParent);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
//algo
//a node burns all neighbours ie left right and parent ek saath
//so keep track of parents by mapping each node to its parent done using level order traversal
//with that find target node that was burned frst
//pass this node to a function start from target node if it has unvisited neigbours 
//push them to q, mark them visited , flag=true
//flag keeps track of insertion in que
//when in any iteration insertion is made time++