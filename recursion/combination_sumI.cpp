#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void helper(int i,vector<int>&ds,vector<int>&arr,int target,int n){
if(i==n){
    if(target==0){
        ans.push_back(ds);
    }
    return;
}
// pick
if(arr[i]<=target){
ds.push_back(arr[i]);
helper(i,ds,arr,target-arr[i],n);
ds.pop_back();
}
// not pick
helper(i+1,ds,arr,target,n);
}
int main(){
    int n;
    cout<<"Enter Dimension : ";
    cin>>n;
    vector<int>arr(n);
cout<<"Enter the elements of array : ";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int target;
cout<<"Enter the target : ";
cin>>target;
vector<int>ds;
helper(0,ds,arr,target,n);
cout<<"The combinations are : ";
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
}