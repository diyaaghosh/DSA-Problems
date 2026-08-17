#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
int solve_by_recursion(int ind,int length,vector<int>&price){
   
    if(ind==0)return length*price[0];
    
    int not_take=solve_by_recursion(ind-1,length,price);
    int take=INT_MIN;
    if((ind+1)<=length){
        take=price[ind]+solve_by_recursion(ind,length-ind-1,price);
    }
    return max(take,not_take);
}
int solve_by_memoization(int ind,int length,vector<int>&price,vector<vector<int>>&dp){
    
     if(ind==0){
        return length*price[0];
    }
    if(dp[ind][length]!=-1)return dp[ind][length];
    int not_take=solve_by_memoization(ind-1,length,price,dp);
    int take=INT_MIN;
    
    if((ind+1)<=length){
        take=price[ind]+solve_by_memoization(ind,length-ind-1,price,dp);
    }
    return dp[ind][length]=max(take,not_take);
}
int solve_by_tabulation(int length,vector<int>&price,vector<vector<int>>&dp){
    
    int n=price.size();
    for(int i=0;i<length;i++){
        dp[0][i]=i*price[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int i=0;i<=length;i++){
            int not_take=dp[ind-1][i];
            int take=INT_MIN;
            if((ind+1)<=i){
                take=dp[ind][i-ind-1]+price[ind];
            }
            dp[ind][i]=max(take,not_take);
        }
    }
    return dp[n-1][length];
}
int solve_by_space_optimization(int length,vector<int>&price){
     int n=price.size();
    vector<int>prev(length+1,0);
    vector<int>curr(length+1,0);
    for(int i=0;i<length;i++){
        prev[i]=i*price[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int i=0;i<=length;i++){
            int not_take=prev[i];
            int take=INT_MIN;
            if((ind+1)<=i){
                take=curr[i-ind-1]+price[ind];
            }
           curr[i]=max(take,not_take);
        }
        prev=curr;
    }
    return prev[length];
}
int solve_optimization_in_1d(int length,vector<int>&price){
    int n=price.size();
    vector<int>prev(length+1,0);
    
    for(int i=0;i<length;i++){
        prev[i]=i*price[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int i=0;i<=length;i++){
            int not_take=prev[i];
            int take=INT_MIN;
            if((ind+1)<=i){
                take=prev[i-ind-1]+price[ind];
            }
           prev[i]=max(take,not_take);
        }
        
    }
    return prev[length];
}
int main()
{
    int length;
    cout << "Enter length of rod : ";
   
    cin >> length;
    int n=length;
    cout << "Enter the elements of price array : ";
    vector<int> price(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    vector<vector<int>> dp(n, vector<int>(length + 1, -1));
    vector<vector<int>> dp1(length, vector<int>(length + 1));
    cout << "Solving by recursion : " << solve_by_recursion(n - 1, length, price) << endl;
    cout << "Solving by memoization : " << solve_by_memoization(n - 1, length, price, dp) << endl;
    cout << "Solving by tabulation : " << solve_by_tabulation(length, price, dp1) << endl;
    cout << "Solving by space optimization : " << solve_by_space_optimization(length, price) << endl;
    cout << "Solving by 1D space optimization : " << solve_optimization_in_1d(length, price) << endl;
}