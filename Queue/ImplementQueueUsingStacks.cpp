#include <stack>
#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
     int front=0;
    MyQueue() { 
    }
    
    void push(int x) {
        if(s1.empty()){
            front = x;
        }
        s1.push(x);
    }
    
    int pop() {
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int val = s2.top();
        s2.pop();
        if(!s2.empty())
        {front=s2.top();}
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
       return val; 
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */