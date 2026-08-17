#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
int solve_by_recursion(int ind,int target,vector<int>&coins){
    if(ind==0){
        if(target%coins[ind]==0){
            return target/coins[ind];
        }
        else return 1e9;
    }
    int not_take=solve_by_recursion(ind-1,target,coins);
    int take=INT_MAX;
    if(target>=coins[ind]){
        take=1+solve_by_recursion(ind,target-coins[ind],coins);
    }
    return min(take,not_take);
}
int solve_by_memoization(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
    if(ind==0){
        if(target%coins[ind]==0){
            return target/coins[ind];
        }
        else return 1e9;
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    int not_take=solve_by_memoization(ind-1,target,coins,dp);
    int take=INT_MAX;
    if(target>=coins[ind]){
        take=1+solve_by_memoization(ind,target-coins[ind],coins,dp);
    }
    return dp[ind][target]=min(take,not_take);
}

int solve_by_tabulation(int target,vector<int>&coins,vector<vector<int>>&dp){
    for(int t=0;t<=target;t++){
       if(t%coins[0]==0) dp[0][t]=t/coins[0];
       else dp[0][t]=1e9;
    }
    for(int i=1;i<coins.size();i++){
        for(int t=0;t<=target;t++){
            int not_take=dp[i-1][t];
            int take=INT_MAX;
            if(t>=coins[i]){
                take=dp[i][t-coins[i]]+1;
            }
            dp[i][t]=min(take,not_take);
        }
    }
    return dp[coins.size()-1][target];
}
int solve_by_space_optimization(int target,vector<int>&coins){
    vector<int>prev(target+1,0);
    vector<int>curr(target+1,0);
    for(int t=0;t<=target;t++){
       if(t%coins[0]==0) prev[t]=t/coins[0];
       else prev[t]=1e9;
    }
    for(int i=1;i<coins.size();i++){
        for(int t=0;t<=target;t++){
            int not_take=prev[t];
            int take=INT_MAX;
            if(t>=coins[i]){
                take=curr[t-coins[i]]+1;
            }
            curr[t]=min(take,not_take);
        }
        prev=curr;
    }
    return prev[target];
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    vector<int>coins(n,0);
    cout<<"Enter the coin : ";
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int target;
    cout<<"Enter target : ";
    cin>>target;
    vector<vector<int>>dp1(n,vector<int>(target+1,-1));
    vector<vector<int>>dp2(n,vector<int>(target+1,-1));
    cout<<"Solving by recursion : "<<solve_by_recursion(n-1,target,coins)<<endl;
    cout<<"Solving by memoization : "<<solve_by_memoization(n-1,target,coins,dp1)<<endl;
    cout<<"Solving by tabulation : "<<solve_by_tabulation(target,coins,dp2)<<endl;
    cout<<"Solving by space optimization : "<<solve_by_space_optimization(target,coins)<<endl;


}