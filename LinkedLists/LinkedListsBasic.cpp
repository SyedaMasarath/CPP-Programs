#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data=data;
        this -> next=NULL;
    }

     //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }


};

void insertAtEnd(Node* &tail,int d){
    Node* tnode=new Node(d);
    tail -> next= tnode;
    tail =tnode;

}
void insertAtHead(Node* &head,int d){
    Node* tnode=new Node(d);
    tnode ->next = head;
    head=tnode;
}

void insertAtPosition(Node* &head,Node* &tail,int pos,int d){
    if(pos==1){
        insertAtHead(head,d);
        return;
    }

    Node* temp=head;
    int cnt =1;

    while(cnt < pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtEnd(tail,d);
        return;
    }
    Node* tnode=new Node(d);
    tnode->next=temp->next;
    temp->next=tnode;

}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}


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
int main(){

Node* node1=new Node(5);
Node* head;
head=node1;
Node* tail=node1;
cout<< "data"<< node1-> data<<endl;
cout<< "next"<< node1-> next<<endl;
insertAtEnd(tail,12);
insertAtEnd(tail,72);
insertAtHead(head,1);
insertAtPosition(head,tail,3,78);

cout<<head->data<<""<<endl;

print(head);

}