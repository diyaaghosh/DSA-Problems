#include<bits/stdc++.h>
using namespace std;
void func(int ind,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums,int n){
ans.push_back(ds);
for(int i=ind;i<n;i++){
    if(i>ind && nums[i]==nums[i-1]){
        continue;
    }
    ds.push_back(nums[i]);
    func(i+1,ds,ans,nums,n);
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
    cin>>arr[i];}
vector<int>ds;
vector<vector<int>>ans;
sort(arr.begin(),arr.end());
func(0,ds,ans,arr,n);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}
