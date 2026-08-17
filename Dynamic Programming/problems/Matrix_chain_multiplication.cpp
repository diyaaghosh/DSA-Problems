#include<bits/stdc++.h>
using namespace std;
int solve_by_recursion(int i,int j,vector<int>&arr){
if(i==j)return 0;
int mini=INT_MAX;
for(int k=i;k<=j-1;k++){
    int steps=arr[i-1]*arr[k]*arr[j]+solve_by_recursion(i,k,arr)+solve_by_recursion(k+1,j,arr);
    mini=min(mini,steps);
}
return mini;
}
int solve_by_memoization(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
if(i==j)return 0;
if(dp[i][j]!=-1)return dp[i][j];
int mini=INT_MAX;
for(int k=i;k<=j-1;k++){
    int steps=arr[i-1]*arr[k]*arr[j]+solve_by_memoization(i,k,arr,dp)+solve_by_memoization(k+1,j,arr,dp);
    mini=min(mini,steps);
}
return dp[i][j]=mini;
}
int solve_by_tabulation(vector<int>&arr){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=1;i<n;i++)dp[i][i]=0; // Base case
    for(int i=n-1;i>=1;i--){
    for(int j=i+1;j<n;j++){
        int mini=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
            mini=min(mini,steps);
}
dp[i][j] = mini;
         }
    }
    return dp[1][n-1];
}
int main(){
    int n;
    cout<<"Enter the number of matrices : ";
    cin>>n;
    vector<int>arr;
    cout<<"Enter their dimesion : \n";
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
            arr.push_back(a);
            if(i==n-1)   arr.push_back(b);
    }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        cout<<"Minimum Multiplication Cost :  "<<solve_by_memoization(1,n,arr,dp)<<endl;
        cout<<"Minimum Multiplication Cost : "<<solve_by_tabulation(arr)<<endl;
}