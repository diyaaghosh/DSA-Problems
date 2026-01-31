# include<bits/stdc++.h>
using namespace std;
int ceil_func(vector<int>&arr,int x){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the dimension : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the lemnets in the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Sorted array : ";
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nEnter Key : ";
    int x;
    cin>>x;
    cout<<"Lower bound : "<<ceil_func(arr,x);
}
