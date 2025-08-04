#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void helper(int i,vector<int>&ds,vector<int>&arr,int target,int n){

    if(target==0){
        ans.push_back(ds);
    
    return;}

// pick
for(int j=i;j<n;j++){
    if(j>i && arr[j]==arr[j-1]){
continue;
    }
    if(arr[j]>target){
        break;
    }
    ds.push_back(arr[j]);
    helper(j+1,ds,arr,target-arr[j],n);
    ds.pop_back();
}
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
sort(arr.begin(),arr.end());
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