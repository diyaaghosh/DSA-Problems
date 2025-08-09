#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(vector<int>&arr,int n){
   if(n==1)return;
   int isswap=0;
   for(int i=0;i<n-1;i++){
    if(arr[i]>arr[i+1]){
        swap(&arr[i],&arr[i+1]);
        isswap=1;
    }
   }
   if(isswap==0){
    return; // base case
   }
   bubble_sort(arr,n-1);
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
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}