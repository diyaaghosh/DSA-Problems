#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i;j<n;j++){
        if(arr[j]<arr[mini]){
            mini=j;
        }
        }
        swap(&arr[mini],&arr[i]);
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
    selection_sort(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}