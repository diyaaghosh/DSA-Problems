#include<bits/stdc++.h>
using namespace std;
int solve_by_recursion(int ind,int transaction_no,vector<int>&prices,int k){
    int n=prices.size();
if(ind==n || transaction_no==2*k)return 0;
if(transaction_no%2==0){
    return max(-prices[ind]+solve_by_recursion(ind+1,transaction_no+1,prices,k),solve_by_recursion(ind+1,transaction_no,prices,k));
}
else{
    return max(prices[ind]+solve_by_recursion(ind+1,transaction_no+1,prices,k),solve_by_recursion(ind+1,transaction_no,prices,k));
}
}
int solve_by_memoization(int ind,int transaction_no,vector<int>&prices,int k,vector<vector<int>>&dp){
    int n=prices.size();
if(ind==n || transaction_no==2*k)return 0;
if(dp[ind][transaction_no]!=-1)return dp[ind][transaction_no];
if(transaction_no%2==0){
    return dp[ind][transaction_no]=max(-prices[ind]+solve_by_memoization(ind+1,transaction_no+1,prices,k,dp),solve_by_memoization(ind+1,transaction_no,prices,k,dp));
}
else{
    return dp[ind][transaction_no]=max(prices[ind]+solve_by_memoization(ind+1,transaction_no+1,prices,k,dp),solve_by_memoization(ind+1,transaction_no,prices,k,dp));
}
}
int solve_by_tabulation(vector<int>&prices,int k){
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
    for(int transaction_no=0;transaction_no<2*k;transaction_no++){
        dp[n][transaction_no]=0;
    }
    for(int ind=0;ind<n;ind++){
        dp[ind][2*k]=0;
    }
    for(int ind=n-1;ind>=0;ind--){
        for(int transaction_no=0;transaction_no<2*k;transaction_no++){
            if(transaction_no%2==0){
                dp[ind][transaction_no]=max(-prices[ind]+dp[ind+1][transaction_no+1],dp[ind+1][transaction_no]);
            }
            else{
                dp[ind][transaction_no]=max(prices[ind]+dp[ind+1][transaction_no+1],dp[ind+1][transaction_no]);
            }
        }
    }
    return dp[0][0];
}
int solve_by_space_optimization(vector<int>&prices,int k){
    int n=prices.size();
    vector<int>curr(2*k+1,0);
    vector<int>next(2*k+1,0);
    
    for(int transaction_no=0;transaction_no<2*k;transaction_no++){
        next[transaction_no]=0;
    }
    for(int ind=0;ind<n;ind++){
         next[2*k]=0;
    }
    for(int ind=n-1;ind>=0;ind--){
        for(int transaction_no=0;transaction_no<2*k;transaction_no++){
            if(transaction_no%2==0){
                curr[transaction_no]=max(-prices[ind]+next[transaction_no+1],next[transaction_no]);
            }
            else{
                curr[transaction_no]=max(prices[ind]+next[transaction_no+1],next[transaction_no]);
            }
        }
        next=curr;
    }
    return next[0];
}
int main(){
    int k;
cout<<"Enter k : ";
cin>>k;
    int n;
cout<<"Enter the dimension : ";
cin>>n;
vector<int>prices(n,0);
cout<<"Enter the price of the stock : ";
for(int i=0;i<n;i++){
    cin>>prices[i];
}

vector<vector<int>>dp(n,vector<int>(2*k,-1));

cout<<"Solving by recursion : "<<solve_by_recursion(0,0,prices,k)<<endl;
cout<<"Solving by memoization "<<solve_by_memoization(0,0,prices,k,dp)<<endl;
cout<<"Solving by tabulation : "<<solve_by_tabulation(prices,k)<<endl;
cout<<"Solving by space optimization : "<<solve_by_space_optimization(prices,k)<<endl;
}