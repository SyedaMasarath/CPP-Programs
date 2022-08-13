#include<iostream>
#include<vector>
using namespace std;

class Stack{

public:
int *arr;
int size;
int top;


Stack(int size){
   this-> size = size;
   arr= new int[size];
   top =-1;
}

void push(int data){
    if(size-top > 1){
        top++;
        arr[top]=data;  
    }
    else{
        cout<<"stack overflow";
    }
}

void pop(){
    if(top>=0){
        top--;
    }
    else{
        cout<<"stack underflow";
    }
}

int peek(){
    if(top>=0){
        return arr[top];
    }
    else{
        cout<<"stack is empty";
        return -1;
    }
}

};
int main(){
    Stack s(5);
    s.push(5);
    s.push(9);
    
    s.pop();
    int a = s.peek();
    cout<<"a is"<<a;
    
}
