//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
//custom data type to store array ele as well as row and col of that element
class node{
    public:
        int data;
        int row;
        int col;
    
    node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
    
};

//custom comparator
class Compare{
    public:
        bool operator()(node* a,node* b){
            return a->data > b->data;
        }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        //min heap
          priority_queue<node*,vector<node*>,Compare> minHeap;
          int mini=INT_MAX;
          int maxi=INT_MIN;
          //push first ele of each row/list in heap
          //set min and max as well
          for(int i=0;i<k;i++){
              int ele = KSortedArray[i][0];
              mini=min(mini,ele);
              maxi=max(maxi,ele);
              minHeap.push(new node(ele,i,0));
          }
          //start and end should not be blank
          int start=mini,end=maxi;
          //while all elements are not processed
          while(!minHeap.empty()){
            //get mini ele from heap
              node* temp = minHeap.top();
              minHeap.pop();
              //set that ele as min 
              mini=temp->data;
              
              //check if range is smaller than current range
              if(maxi-mini < end-start){
                  start=mini;
                  end=maxi;
              }
              
              //if next ele present in row
              if(temp->col+1<n){
                //update max
                  maxi=max(maxi,KSortedArray[temp->row][temp->col+1]);
                  //push ele in heap so next ele can be processed as well
                  minHeap.push(new node(KSortedArray[temp->row][temp->col+1],temp->row,temp->col+1));
              }
              else{
                //array out of bounds/end of list
                  break;
              }
          }
          
         
          return {start,end};
          
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends