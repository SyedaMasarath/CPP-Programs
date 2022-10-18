//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
void createMap(map<int,int> &NodeToIndex,int n,int in[]){
    for(int i=0;i<n;i++){
        NodeToIndex[in[i]]=i;
    }
}

Node *solve(int in[],int post[], int &index, int inOrderStart,int inOrderEnd,int n, map<int,int> &NodeToIndex){

    if(index<0 || inOrderStart > inOrderEnd ){
        return NULL;
    }
    //get ele to be inserted in tree tracked using index, inc/dec index
    int ele = post[index--];
    Node *root = new Node(ele);
    int pos = NodeToIndex[ele];
    
    root->right = solve(in,post,index,pos+1,inOrderEnd,n,NodeToIndex);
    root->left = solve(in,post,index,inOrderStart,pos-1,n,NodeToIndex);
    
    return root;
    
}


Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex= n-1;
    map<int,int> NodeToIndex;
    createMap(NodeToIndex,n,in);
    
    Node *ans=solve(in,post,postOrderIndex,0,n-1,n,NodeToIndex);
    return ans;
}
