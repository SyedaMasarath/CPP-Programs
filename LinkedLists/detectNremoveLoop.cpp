
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Solution
{
    private:
    Node* detectLoop(Node* head)
    {
        // your code here
        if(head==NULL){
            return NULL;
        }
        
        Node* slow=head;
        Node* fast=head;
        
        while(slow!=NULL && fast!=NULL &&  fast->next!=NULL){
            fast=fast->next;
            
            if(fast!= NULL){
                fast=fast->next;
            }
            slow=slow->next;
            
            if(slow==fast){
                return slow;
            }
        }
        return NULL;
    }
    
    Node* getStartNode(Node* head){
        
        if(head==NULL){
            return NULL;
        }
        Node* intersection=detectLoop(head);
        if(intersection==NULL){
            return NULL;
        }
        Node* slow=head;
        while(slow!=intersection){
            slow=slow->next;
            intersection=intersection->next;
        }
        return slow;
    }
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        if(head==NULL || head->next==NULL){
            return;
        }
        
        Node* startofloop= getStartNode(head);
        
        if(startofloop!=NULL){
             Node* temp=startofloop;
            while(temp->next!= startofloop){
                temp=temp->next;
            }
            temp->next=NULL;
        }
        
       
    }
};