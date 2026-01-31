# include<bits/stdc++.h>
using namespace std;
struct heap{
int capacity;
int size;
vector<int>arr;
int left(int index){
    return 2*index+1;
}
int right(int index){
    return 2*index+2;
}
int parent(int child_index){
    return (child_index-1)/2;
}
heap(int cap){
    capacity=cap;
    size=0;
    arr = vector<int>(cap);
}
};
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(heap*Binary_heap,int i){
    int n=Binary_heap->size;
   vector<int>& arr = Binary_heap->arr;
    int smallest=i;
    int left=Binary_heap->left(i);
    int right=Binary_heap->right(i);
   if(left<n && arr[smallest]>arr[left]){
        smallest=left;
    }
     if(right<n && arr[smallest]>arr[right]){
        smallest=right;
    }
    if(smallest !=i){
        swap(&arr[smallest],&arr[i]);
        heapify(Binary_heap,smallest);
    }
}
void insert(int val,heap*Binary_heap){
if(Binary_heap->size==Binary_heap->capacity){
    cout<<"Heap overflow"<<endl;
}
else{
    Binary_heap->arr[Binary_heap->size]=val;
    Binary_heap->size++;
    int k=Binary_heap->size-1;
    while(k>0 && Binary_heap->arr[Binary_heap->parent(k)]>Binary_heap->arr[k]){
        swap(&Binary_heap->arr[Binary_heap->parent(k)],&Binary_heap->arr[k]);
        k=Binary_heap->parent(k);
    }
}

}
int get_min(heap*Binary_heap){
    return Binary_heap->arr[0];
}
int extract_min(heap*Binary_heap){
    int mini=INT_MAX;
if(Binary_heap->size<=0){
    cout<<"Heap Underflow!\n";
   
}
else if(Binary_heap->size==1){
    mini=Binary_heap->arr[0];
Binary_heap->size--;

}
else{
    mini=Binary_heap->arr[0];
    Binary_heap->arr[0]=Binary_heap->arr[Binary_heap->size-1];
    Binary_heap->size--;
    heapify(Binary_heap,0);
    
}
return mini;
}
void decrease_key(int i,int val,heap*Binary_heap){
    if(i>=Binary_heap->capacity){
         cout<<"Heap overflow\n"<<endl;

    }
    else{
        Binary_heap->arr[i]=val;
        int k=i;
        while(k>0 && Binary_heap->arr[Binary_heap->parent(k)]>Binary_heap->arr[k]){
        swap(&Binary_heap->arr[Binary_heap->parent(k)],&Binary_heap->arr[k]);
        k=Binary_heap->parent(k);
    }
    }
}
void delete_key(int i,heap*Binary_heap){
decrease_key(i,INT_MIN,Binary_heap);
extract_min(Binary_heap);
}
void print(heap*Binary_heap){
    cout<<"Heap : \n";
for(int i=0;i<Binary_heap->size;i++){
    cout<<Binary_heap->arr[i]<<" ";
}
cout<<endl;
}
int main(){
    int capacity;
    cout<<"Enter capacity of the heap : ";
    cin>>capacity;
heap*Binary_heap=new heap(capacity);
cout<<"Enter the elemnts in the heap : ";
for(int i=0;i<capacity;i++){
    int temp;
    cin>>temp;
    insert(temp,Binary_heap);
}
cout<<endl;
cout<<"Minimum value : ";
cout<<get_min(Binary_heap);
cout<<endl;
cout<<"Deleting the min val : \n";
int x=extract_min(Binary_heap);
cout<<x<<" is deleted \n";
print(Binary_heap);
cout<<endl;
int index,val;
cout<<"Updating the value in heap : \n";
cout<<"Enter the index : ";
cin>>index;
cout<<"Enter the value : ";
cin>>val;
decrease_key(index,val,Binary_heap);
print(Binary_heap);
cout<<"Deleting the value in a particular index : \n";
cout<<"Enter the index : ";
cin>>index;
delete_key(index,Binary_heap);
print(Binary_heap);
}
