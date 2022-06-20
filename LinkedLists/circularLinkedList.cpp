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

void insertNode(Node* &tail,int pos,int d){

    if(tail==NULL){
        Node* temp1= new Node(d);
        tail=temp1;
        temp1->next=temp1;
    }
    else{
        Node* curr=tail;

        while(curr->data != pos){
           curr=curr->next;
        }

        Node* newnode= new Node(d);
        newnode->next=curr->next;
        curr->next=newnode;
    }
    
}

void print(Node* tail){
    Node* temp=tail;
    do{
        cout<< tail->data<<" ";
        tail=tail->next;
    }
    while(temp != tail);
}
void deleteNode(Node* tail,int data){
    if(tail=NULL){
        cout<<"list is empty";
    }
    else{
        Node* prev=tail;
        Node* curr=prev->next;

        while(curr->data != data){
            prev=curr;
            curr = curr->next;
        }
        prev->next=curr->next;
        //1nodeonly
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;

}

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}
int main(){

Node* tail=NULL;
insertNode(tail,1,100);

print(tail);
insertNode(tail,100,200);
print(tail);

insertNode(tail,200,500);
print(tail);
}
