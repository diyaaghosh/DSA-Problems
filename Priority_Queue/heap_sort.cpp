# include<bits/stdc++.h>
using namespace std;
void maxheapify(vector<int> & arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
   if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
     if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest !=i){
        swap(arr[largest],arr[i]);
        maxheapify(arr,n,largest);
    }
}
void heap_sort(vector<int>& arr,int n){
    // building max heap
    for(int i=n/2-1;i>=0;i--){
maxheapify(arr,n,i);
    }
    // deleting
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        maxheapify(arr,i,0);
    }
    
    
}
int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter elements : ";
    for(int i=0;i<n;i++){   
        cin>>arr[i];
    }   
    heap_sort(arr,n);
cout<<"sorted array :\n";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}
