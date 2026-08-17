#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
int mod=(int)(1e9+7);
int solve_by_recursion(int ind,int target,vector<int>&arr){
    if(ind == 0){
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }
   
        int non_pick=solve_by_recursion(ind-1,target,arr);
        int pick=0;
        if(arr[ind]<=target){
            pick=solve_by_recursion(ind-1,target-arr[ind],arr);
        }
        return (pick+non_pick)%mod;
}
int solve_by_memoization(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
       if(ind == 0){
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int non_pick=solve_by_memoization(ind-1,target,arr,dp);
        int pick=0;
        if(arr[ind]<=target){
            pick=solve_by_memoization(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target]=(pick+non_pick)%mod;
}
int solve_by_tabulation(int target,vector<int>&arr,vector<vector<int>>&dp){
    int n=arr.size();
    if(arr[0]==0)dp[0][0]=2;
    else dp[0][0]=1;
    if (arr[0]!=0 && arr[0] <= target) dp[0][arr[0]] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int not_pick=dp[i-1][j];
            int pick=0;
            if(arr[i] <= j){
                pick=dp[i-1][j-arr[i]];
            }
            dp[i][j]=(pick+not_pick)%mod;
        }
    }
    return dp[n-1][target];
}
int solve_by_space_optimization(int target,vector<int>&arr){
    int n=arr.size();
    vector<int>prev(target+1,0);
    vector<int>curr(target+1,0);
    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if (arr[0]!=0 && arr[0] <= target) prev[arr[0]] = 1;
   
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int not_pick=prev[j];
            int pick=0;
            if(arr[i] <= j){
                pick=prev[j-arr[i]];
            }
            curr[j]=(pick+not_pick)%mod;
        }
        prev=curr;
    }
    return prev[target];
}
int main(){
  
   
    int n;
    cout<<"Enter n : ";
    cin>>n;
    vector<int>arr(n,0);
    cout<<"Enter the elements : ";
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
    int target;
    cout<<"Enter Difference : ";
    cin>>target;
    int total_sum=0;
    for(int i=0;i<n;i++){
        total_sum+=arr[i];
    }
    if((total_sum-target)%2==1 || (total_sum-target)<0){
        cout<<"Not Possible"<<endl;
    }
    else{
    target=(total_sum-target)/2;
    vector<vector<int>>dp1(n+1,vector<int>(target+1,-1));
    vector<vector<int>>dp2(n+1,vector<int>(target+1,0));
    cout<<"Solving by recursion : "<<solve_by_recursion(n-1,target,arr)<<endl;
    cout<<"Solving by memoization : "<<solve_by_memoization(n-1,target,arr,dp1)<<endl;
    cout<<"Solving by tabulation : "<<solve_by_tabulation(target,arr,dp2)<<endl;
    cout<<"Solving by space optimization : "<<solve_by_space_optimization(target,arr)<<endl;
    }

}