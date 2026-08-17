#include<bits/stdc++.h>
using namespace std;
int solve_by_recursion(int ind,int buy,vector<int>&prices){
    int n=prices.size();
   
    if(ind==n)return 0;
    if(buy==1){
        return max((-prices[ind]+solve_by_recursion(ind+1,0,prices)),solve_by_recursion(ind+1,1,prices));
    }
    else{
        return max((prices[ind]+solve_by_recursion(ind+1,1,prices)),solve_by_recursion(ind+1,0,prices));
    }
    
}
int solve_by_memoization(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
    int n=prices.size();
    
    if(ind==n)return 0;
    if(dp[ind][buy]!=-1)return dp[ind][buy];
    if(buy==1){
       return dp[ind][buy]=max((-prices[ind]+solve_by_memoization(ind+1,0,prices,dp)),solve_by_memoization(ind+1,1,prices,dp));
    }
    else{
       return dp[ind][buy]=max((prices[ind]+solve_by_memoization(ind+1,1,prices,dp)),solve_by_memoization(ind+1,0,prices,dp));
    }
   
}
int solve_by_tabulation(vector<int>&prices){
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
        dp[i][0]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
    }
    return dp[0][1];
}
int solve_by_space_optimization(vector<int>&prices){
    int n=prices.size();
    vector<int>next(2,0);
   
    vector<int>curr(2,0);
    for(int i=n-1;i>=0;i--){
       curr[1]=max(-prices[i]+next[0],next[1]);
        curr[0]=max(prices[i]+next[1],next[0]);
        next=curr;
    }
    return curr[1];
}
int main(){
int n;
cout<<"Enter the dimension : ";
cin>>n;
vector<int>prices(n,0);
cout<<"Enter the price of the stock : ";
for(int i=0;i<n;i++){
    cin>>prices[i];
}
vector<vector<int>>dp(n,vector<int>(2,-1));
cout<<"Solving by recursion : "<<solve_by_recursion(0,1,prices)<<endl;
cout<<"Solving by memoization "<<solve_by_memoization(0,1,prices,dp)<<endl;
cout<<"Solving by tabulation : "<<solve_by_tabulation(prices)<<endl;
cout<<"Solving by space optimization : "<<solve_by_space_optimization(prices)<<endl;
}