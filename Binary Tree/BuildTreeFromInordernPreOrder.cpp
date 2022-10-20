//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findPosition(int ele,int in[],int n){
        for(int i=0;i<n;i++){
            if(in[i]==ele){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[], int pre[], int &index,int inOrderStart,int inorderEnd,int n){
        
        if(index >=n || inOrderStart > inorderEnd){
            return NULL;
        }
        
        int ele= pre[index++];
        Node* root= new Node(ele);
        int position= findPosition(ele,in,n);
        
        root->left = solve(in,pre,index,inOrderStart,position-1,n);
        root->right = solve(in,pre,index,position+1, inorderEnd,n);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrder=0;
        
        Node* ans= solve(in,pre,preOrder,0,n-1,n);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends