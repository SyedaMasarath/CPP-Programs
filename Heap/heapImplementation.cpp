#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0]=-1;
        size=0;
    }

    //masx heap
    void insert(int val){
        size=size+1;
        int index=size;

        arr[index]=val;

        while(index>1){
            int parent=index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";

        }
        cout<<endl;
    }

    void deleteFromHeap(){
        if(size==0){
            cout<<"heap is empty";
            return;
        }
        //put first ele at end n decrease size
        arr[1]=arr[size];
        size--;
        int i=1;

        while(i<size){
            int left=2*i;
            int right = 2*i+1;
            //children not out of bound
            if(left<size && arr[i]<arr[left]){
                //if root less than left child swap
                swap(arr[i],arr[left]);
                i=left;
                //update index to process its childs
            }
            else if(right<size && arr[i]<arr[right]){
                swap(arr[i],arr[right]);
                i=right;
            }
            else{
                return;
            }
        }
    }


};
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    //node within range/arr
    
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
        //just update index dont swap
        //we swap when it has reached its right position
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    //if largest has been updated
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapifyForMinHeap(int arr[],int n,int i){
    int smallest=i;
    int left=2*i;
    int right=2*i+1;
    //node within range/arr
    
    if(left<=n && arr[smallest]>arr[left]){
        smallest=left;
        //just update index dont swap
        //we swap when it has reached its right position
    }
    if(right<=n && arr[smallest]>arr[right]){
        smallest=right;
    }
    //if largest has been updated
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}
int main(){
    heap h;
    //inserting one by one
    h.insert(50);
    h.insert(51);
    h.insert(59);
    h.insert(54);
    h.insert(52);

    h.print();
    h.deleteFromHeap();
    h.print();

    int arr[6]={-1,54,56,55,5,12};
    //giving array input to makeit into a heap
    int n=6;
    //n/2 since leaf nodes are already heapified
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}