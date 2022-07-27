#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};



// } Driver Code Ends
class Solution
{
    private:
    void insertAtTail(Node* &head,Node* &tail,int data){
        Node* temp= new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        
        unordered_map<Node*,Node*> mapping;
        
        Node* orgNode=head;
        Node* copyNode=cloneHead;
        
        while(orgNode!=NULL){
            mapping[orgNode]=copyNode;
            orgNode=orgNode->next;
            copyNode=copyNode->next;
        }
        
        orgNode=head;
        copyNode=cloneHead;
        
        while(orgNode!=NULL){
            copyNode->arb= mapping[orgNode->arb];
            orgNode=orgNode->next;
            copyNode=copyNode->next;
        }
        return cloneHead;
    }

};
