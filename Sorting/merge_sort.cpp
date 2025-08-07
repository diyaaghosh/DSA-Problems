#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
         temp.push_back(arr[left]);
            left++;
    }
    while(right<=high){
temp.push_back(arr[right]);
            right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergersort(vector<int>&arr,int low,int high){
    if(low>=high)return; // base case
    int mid=(low+high)/2;
    mergersort(arr,low,mid);
    mergersort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    
    cout<<"Enter the dimension : ";
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergersort(arr,0,arr.size()-1);
    cout<<"Sorted array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
