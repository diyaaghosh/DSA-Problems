# include<bits/stdc++.h>
using namespace std;
// memoization
int max_nonadjacent_subarray(int ind,vector<int> & nums,vector<int>& dp){
    if(ind==0)return nums[ind];
    else if(ind<0)return 0;
    else if(dp[ind]!=-1)return dp[ind]; // overlapping subproblem
    int pick=nums[ind]+max_nonadjacent_subarray(ind-2,nums,dp);
    int non_pick=0+max_nonadjacent_subarray(ind-1,nums,dp);
    dp[ind]=max(pick,non_pick);
    return dp[ind];
}
// tabulation
int max_nonadjacent_subarray_tabulation(vector<int> & nums,vector<int>& dp){
   int n=nums.size();
   dp[0]=nums[0];
   for(int i=1;i<n;i++){
   int pick=nums[i];
   if(i>1)pick+=dp[i-2];
   int non_pick=0+dp[i-1];
   dp[i]=max(pick,non_pick);
   }
   return dp[n-1];
}
// space optimization
int max_nonadjacent_subarray_space_optimization(vector<int> & nums){
   int n=nums.size();
   int prev=nums[0];
   int prev2=0;
   int curi=0;
   for(int i=1;i<n;i++){
   int pick=nums[i];
   if(i>1)pick+=prev2;
   int non_pick=0+prev;
   curi=max(pick,non_pick);
   prev2=prev;
   prev=curi;
   }
   return prev;
}
int main(){
    int n;
    cout<<"enter dimension : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }       
       vector<int>dp(n,-1);
       int ans=max_nonadjacent_subarray(n-1,nums,dp);
       cout<<"Memoization : "<<ans<<endl;
       dp.assign(n,-1);
       ans=max_nonadjacent_subarray_tabulation(nums,dp);    
       cout<<"Tabulation : "<<ans<<endl;
       ans=max_nonadjacent_subarray_space_optimization(nums);
       cout<<"Space Optimization : "<<ans<<endl;
    }

