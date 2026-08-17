#include<bits/stdc++.h>
using namespace std;
int solve_by_recursion(int ind,int buy,int cap,vector<int>&prices){
    int n=prices.size();
    if(cap==0)return 0;
    if(ind==n)return 0;
    if(buy==1){
        return max((-prices[ind]+solve_by_recursion(ind+1,0,cap,prices)),solve_by_recursion(ind+1,1,cap,prices));
    }
    else{
        return max((prices[ind]+solve_by_recursion(ind+1,1,cap-1,prices)),solve_by_recursion(ind+1,0,cap,prices));
    }
    
}
int solve_by_memoization(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
    int n=prices.size();
     if(cap==0)return 0;
    if(ind==n)return 0;
    if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
    if(buy==1){
       return dp[ind][buy][cap]=max((-prices[ind]+solve_by_memoization(ind+1,0,cap,prices,dp)),solve_by_memoization(ind+1,1,cap,prices,dp));
    }
    else{
       return dp[ind][buy][cap]=max((prices[ind]+solve_by_memoization(ind+1,1,cap-1,prices,dp)),solve_by_memoization(ind+1,0,cap,prices,dp));
    }
   
}

int solve_by_tabulation(vector<int>&prices){
    int n=prices.size();
   vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
   for(int ind=0;ind<n;ind++){
    for(int buy=0;buy<2;buy++){
        dp[ind][buy][0]=0;
    }
}
    for(int buy=0;buy<2;buy++){
        for(int cap=0;cap<3;cap++){
            dp[n][buy][cap]=0;
        }
    }
   
    for(int ind=n-1;ind>=0;ind--){
       for(int buy=0;buy<2;buy++){
        for(int cap=1;cap<3;cap++){
            if(buy==1){
                dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
            }
            else{
                dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
            }

        }
       }
    }
    return dp[0][1][2];
}

int solve_space_optimization(vector<int>&prices){
    int n=prices.size();
    vector<vector<int>>curr(2,vector<int>(3,0));
    vector<vector<int>>next(2,vector<int>(3,0));
   
   for(int ind=0;ind<n;ind++){
    for(int buy=0;buy<2;buy++){
       next[buy][0]=0;
    }
}
    for(int buy=0;buy<2;buy++){
        for(int cap=0;cap<3;cap++){
            next[buy][cap]=0;
        }
    }
   
    for(int ind=n-1;ind>=0;ind--){
       for(int buy=0;buy<2;buy++){
        for(int cap=1;cap<3;cap++){
            if(buy==1){
                curr[buy][cap]=max(-prices[ind]+next[0][cap],next[1][cap]);
            }
            else{
                curr[buy][cap]=max(prices[ind]+next[1][cap-1],next[0][cap]);
            }

        }
       }
       next=curr;
    }
    return next[1][2];
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
vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

cout<<"Solving by recursion : "<<solve_by_recursion(0,1,2,prices)<<endl;
cout<<"Solving by memoization "<<solve_by_memoization(0,1,2,prices,dp)<<endl;
cout<<"Solving by tabulation : "<<solve_by_tabulation(prices)<<endl;
cout<<"Solving by space optimization : "<<solve_space_optimization(prices)<<endl;
}