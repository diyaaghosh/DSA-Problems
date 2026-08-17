#include<bits/stdc++.h>
using namespace std;
int solve_by_different_tabulation(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,1);
    vector<int>dp1(n,1);
    
    for(int ind=0;ind<n;ind++){
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(nums[ind]>nums[prev_ind]){
                dp[ind]=max(dp[ind],1+dp[prev_ind]);
               
            }
        }
    }
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=n-1;prev_ind>ind;prev_ind--){
            if(nums[ind]>nums[prev_ind]){
                dp1[ind]=max(dp1[ind],1+dp1[prev_ind]);
               
            }
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp[i]+dp1[i]);
    }
  return maxi-1;
}
int main(){
    int n;
    cout<<"Enter dimension : ";
    cin>>n;
    vector<int>nums(n,0);
    cout<<"Enter the elemnets of the array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
   cout<<"length of longest biotonic subsequence : "<<solve_by_different_tabulation(nums)<<endl;
   
}