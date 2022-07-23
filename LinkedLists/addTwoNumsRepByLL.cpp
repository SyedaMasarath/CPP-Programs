//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{   private:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* forward=NULL;
        
        while(curr!=NULL){
            forward= curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    void insertAtTail(Node* &ansHead,Node* &ansTail,int digit){
        Node* temp=new Node(digit);
        if(ansHead==NULL){
            ansHead=temp;
            ansTail=temp;
            return;
        }
        else{
            ansTail->next=temp;
            ansTail=temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry=0;
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        
        Node* temp1=first;
        Node* temp2=second;
        
        while(temp1!=NULL || temp2!=NULL || carry!=0){
            int val1=0;
            int val2=0;
            if(temp1!=NULL){
                val1=temp1->data;
            }
            if(temp2!=NULL){
                val2=temp2->data;
            }
            int sum =val1+val2+ carry;
            int digit= sum%10;
            carry=sum/10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            if(temp1!=NULL){
                temp1=temp1->next;
            }
            if(temp2!=NULL){
                temp2=temp2->next;}
            
        }
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        
        
        Node* ans= add(first,second);
        ans=reverse(ans);
        
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}