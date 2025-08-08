#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int f(vector<int>&arr,int low,int high){
  int i=low;
  int pivot=arr[low];
  int j=high;
  while(i<j){
    while(arr[i]<=pivot && i<=high-1){
        i++;
    }
    while(arr[j]>pivot && j>=low+1){
        j--;
    }
    if(i<j){
        swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[j],&arr[low]);
  return j;
}
void quick_sort(vector<int>&arr,int low,int high){
    int n=arr.size();
   if(low<high){
       int partition_id=f(arr,low,high);
        quick_sort(arr,low,partition_id-1);
        quick_sort(arr,partition_id+1,high);

    }
}
int main(){
    int n;
    cout<<"enter the dimension : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter the elements of array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"sorted array : ";
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}