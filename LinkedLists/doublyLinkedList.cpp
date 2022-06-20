#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this -> data=data;
        this -> next=NULL;
        this -> prev= NULL;
    }

     //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }


};
void print(Node* &head){

     if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
      Node* temp=head;
       while( temp != NULL){
           cout<< temp->data <<" "<<endl;
           temp = temp->next;
       }
}
void insertAtHead(Node* &head,Node* &tail, int d){
    if(head==NULL){
        Node* node1= new Node(d);
        head=node1;
        tail=node1;
    }
    Node* node1= new Node(d);
    node1->next=head;
    head -> prev=node1;
    head=node1;
}

void insertAtTail(Node* &head,Node* &tail, int d){

    if(tail==NULL){
        Node* temp = new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node* node1= new Node(d);
    tail ->next= node1;
    node1 -> prev= tail;
    tail= node1;
    }
}

void insertAtPosition(Node* head,Node* tail,int d,int pos){
    if(pos==1){
        insertAtHead(head,tail,d);
        return;
    }
    int count =1;
    Node* temp=head;
    while(count < pos-1){
        temp = temp ->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtTail(head,tail,d);
    }
    Node* node1= new Node(d);
    node1->next= temp ->next;
    temp->next->prev=node1;
    temp ->next= node1;
    node1 -> prev = temp;
    
}

void deleteNode(Node* &head, int pos){
  
    if(pos==1){
        Node* temp=head;
        temp->next->prev= NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev= NULL;
        int count=1;
        while(count<pos){
          prev= curr;
          curr = curr ->next;
          count++;
        }
        curr -> prev = NULL;
        prev ->next = curr -> next;
        curr->next= NULL;
        delete curr;
    }
}
int main(){
    Node* temp= new Node(12);
    Node* head=temp;
    Node* tail=temp;
   

    insertAtHead(head,tail,18);
    

    insertAtTail(head,tail,78);
    print(head);

    insertAtPosition(head,tail,7,3);
    print(head);
    deleteNode(head,2);
    cout<<head-> data<<" ";
    cout<<tail-> data<<" ";

    print(head);
}