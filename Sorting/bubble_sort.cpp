#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(vector<int>&arr){
    int swapno=0;
    int n=arr.size();
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapno=1;
            }
        }
        // best case
        if(swapno==0){
            break;
        }
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
    bubble_sort(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}
