# include<bits/stdc++.h>
using namespace std;
void insertion_max_heap(vector<int>& max_heap,int value){
int n=max_heap.size();
max_heap.push_back(value);
int i=n;
while(i>1){
    int parent=(i - 1) / 2;
    if(max_heap[parent]<max_heap[i]){
        swap(max_heap[parent],max_heap[i]);
        i=parent;
    }
    else{
        return;
    }
}
}
int main(){
    int n;
    cout<<"Enter dimension of heap : ";
    cin>>n;
    vector<int>max_heap(n);
    cout<<"Enter the elements in the max heap : ";
    for(int i=0;i<n;i++){
        cin>>max_heap[i];
    }
    int val;
    cout<<"Enter the value to be inserted : ";
    cin>>val;
    cout<<"After insertion : ";
    insertion_max_heap(max_heap,val);
    for(int i=0;i<max_heap.size();i++){
        cout<<max_heap[i]<<" ";
    }

}