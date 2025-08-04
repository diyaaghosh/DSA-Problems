#include<bits/stdc++.h>
using namespace std;
   void countSubsequenceWithTargetSum(int i,vector<int>&ds,int sum,vector<int>& nums, int k,int n){
    	if(i==n){
            if(sum==k){
      for(auto it: ds){
        cout<<it<<" ";
      }
      cout<<endl;
            }
     return;
        }
        ds.push_back(nums[i]); // pick
        sum+=nums[i];
        countSubsequenceWithTargetSum(i+1,ds,sum,nums,k,n);
        ds.pop_back(); // not pick
        sum-=nums[i];
         countSubsequenceWithTargetSum(i+1,ds,sum,nums,k,n);
    }
int main(){
     int n;
        cout<<"Enter the dimension : ";
        cin>>n;
        vector<int>nums(n);
        cout<<"Enter the elements of the array : ";
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int target;
        cout<<"Enter the target : ";
        cin>>target;
        vector<int>ds;
       countSubsequenceWithTargetSum(0,ds,0,nums,target,n);
      
}