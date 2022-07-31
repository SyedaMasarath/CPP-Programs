#include <bits/stdc++.h>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

 ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        
        ListNode* temp=head;
        int len=1;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        
        temp->next=head;
        k=k%len;
        k=len-k;
        int count=0;
        while(count<k){
            temp=temp->next;
            count++;
        }
       
        head=temp->next;
        temp->next=NULL;
        return head;
        
    }