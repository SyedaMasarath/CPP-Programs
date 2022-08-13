#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class twoStack {


int *arr;
int top1,top2,size;

public:
twoStack(int size){
    this ->size = size;
    top1=-1;
    top2= size;
    arr = new int[size];
}

void push1(int data){
    if(top2-top1>1){
        top1++;
        arr[top1]=data;
    }
    else{
        cout<<"stack overflow";
    }
}

void push2(int data){
    if(top2-top1 > 1){
        top2--;
        arr[top2]= data;
    }
    else{
        cout<<"stack overflow";
    }
}

void pop1(){
    if(top1>=0){
        top1--;
    }
    else{
        cout<<"stack underflow";
    }
}

void pop2(){
    if(top2<size){
        top2++;
    }
    else{
        cout <<"stack underflow";
    }
}

};

