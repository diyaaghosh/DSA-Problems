#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insertion_sort(vector<int>&arr,int index,int n){
   if(index==n)return;
        int j=index;
        while(j>0 && arr[j-1]>arr[j]){
            swap(& arr[j] , & arr[j-1]);
            j--;
        }
        insertion_sort(arr,index+1,n);
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
    insertion_sort(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}