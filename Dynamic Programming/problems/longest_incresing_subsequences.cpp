#include<bits/stdc++.h>
using namespace std;
int solve_by_binary_search(vector<int>&nums){
    int n=nums.size();
    vector<int>track;
    track.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(nums[i]>track.back()){
            track.push_back(nums[i]);

        }
        else{
        int ind=lower_bound(track.begin(),track.end(),nums[i])- track.begin();;
        track[ind]=nums[i];
    }
}
return track.size();
}
int solve_by_recursion(int ind,int prev_ind,vector<int>&nums){
    int n=nums.size();
    if(ind==n)return 0;
    // not pick
    int not_pick=solve_by_recursion(ind+1,prev_ind,nums);
    //pick
     int pick=0;
    if(prev_ind==-1|| nums[ind]>nums[prev_ind]){
       pick=1+solve_by_recursion(ind+1,ind,nums);

    }
    return max(pick,not_pick);
}
int solve_by_memoization(int ind,int prev_ind,vector<int>&nums,vector<vector<int>>&dp){
    int n=nums.size();
    if(ind==n)return 0;
    if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
    // not pick
    int not_pick=solve_by_memoization(ind+1,prev_ind,nums,dp);
    //pick
     int pick=0;
    if(prev_ind==-1|| nums[ind]>nums[prev_ind]){
       pick=1+solve_by_memoization(ind+1,ind,nums,dp);

    }
    return dp[ind][prev_ind+1]=max(pick,not_pick);
}
int solve_by_tabulation(vector<int>&nums){
    int n=nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int not_pick=dp[ind+1][prev_ind+1];
            //pick
            int pick=0;
            if(prev_ind==-1|| nums[ind]>nums[prev_ind]){
                  pick=1+dp[ind+1][ind+1];
          }
          dp[ind][prev_ind+1] = max(pick, not_pick);
    }
}
return dp[0][0];
}
int solve_by_space_optimization(vector<int>&nums){
    int n=nums.size();
    vector<int>curr(n+1,0);
    vector<int>next(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int not_pick=next[prev_ind+1];
            //pick
            int pick=0;
            if(prev_ind==-1|| nums[ind]>nums[prev_ind]){
                  pick=1+next[ind+1];
          }
          curr[prev_ind+1] = max(pick, not_pick);
    }
    next = curr;
}
return curr[0];
}
int solve_by_different_tabulation(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,1);
    int maxi=INT_MIN;
    for(int ind=0;ind<n;ind++){
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(nums[ind]>nums[prev_ind]){
                dp[ind]=max(dp[ind],1+dp[prev_ind]);
                maxi=max(maxi,dp[ind]);
            }
        }
    }
    return maxi;
}
vector<int> print_longest_increasing_subsequence(vector<int>&nums){
    int n=nums.size();
    vector<int>hash(n,0);
    for(int i=0;i<n;i++){
        hash[i]=i;
    }
    vector<int>dp(n,1);
    int maxi=INT_MIN;
     for(int ind=0;ind<n;ind++){
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(nums[ind]>nums[prev_ind]){
               if(dp[ind]<1+dp[prev_ind]){
                dp[ind]=1+dp[prev_ind];
                hash[ind]=prev_ind;
                maxi=max(maxi,dp[ind]);
               }

               
            }
        }
    }
    int j=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi){
            j=i;
        }
    }
    vector<int>ans;
    while(j!=hash[j]){
    ans.push_back(nums[j]);
    j=hash[j];
    }
    ans.push_back(nums[j]);
    reverse(ans.begin(),ans.end());
    return ans;
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
   vector<vector<int>>dp(n,vector<int>(n+1,-1));
   cout<<"Solving by binary search : "<<solve_by_binary_search(nums)<<endl;
   int ind=0;
   cout<<"Solving by recursion : "<<solve_by_recursion(ind,-1,nums)<<endl;
   ind=0;
   cout<<"Solvinmg by memoization : "<<solve_by_memoization(ind,-1,nums,dp)<<endl;
   cout<<"Solving by tabulation : "<<solve_by_tabulation(nums)<<endl;
   cout<<"Solving by space optimization : "<<solve_by_space_optimization(nums)<<endl;
   cout<<"Solving by diff tabulation : "<<solve_by_different_tabulation(nums)<<endl;
   cout<<"Longest increasing subsequence : \n";
   vector<int>ans=print_longest_increasing_subsequence(nums);
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }
   cout<<endl;
}