#include<bits/stdc++.h>
using namespace std;
void helper(int i,vector<int>&arr,int sum,int n,vector<int>&ans){
if(i==n){
    ans.push_back(sum);
    return;
}
// pick
helper(i+1,arr,sum+arr[i],n,ans);
// not pick
helper(i+1,arr,sum,n,ans);
}
int main(){
    int n;
    cout<<"Enter Dimension : ";
    cin>>n;
    vector<int>arr(n);
cout<<"Enter the elements of array : ";
for(int i=0;i<n;i++){
    cin>>arr[i];}
vector<int>ans;
helper(0,arr,0,n,ans);
cout<<"The combinations are : ";
sort(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++){
  cout<<ans[i]<<" ";
    }
    cout<<endl;
}
