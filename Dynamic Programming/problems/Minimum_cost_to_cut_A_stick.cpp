#include<bits/stdc++.h>
using namespace std;
int solve_by_recursion(int i,int j,vector<int>&cuts){
if(i>j)return 0;
int mini=INT_MAX;
for(int ind=i;ind<=j;ind++){
    int cost=cuts[j+1]-cuts[i-1]+solve_by_recursion(i,ind-1,cuts)+solve_by_recursion(ind+1,j,cuts);
    mini=min(mini,cost);
}
return mini;
}
int solve_by_memoization(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
if(i>j)return 0;
if(dp[i][j]!=-1)return dp[i][j];
int mini=INT_MAX;
for(int ind=i;ind<=j;ind++){
    int cost=cuts[j+1]-cuts[i-1]+solve_by_memoization(i,ind-1,cuts,dp)+solve_by_memoization(ind+1,j,cuts,dp);
    mini=min(mini,cost);
}
return mini;
}
int solve_by_tabulation(vector<int>&cuts){
    int m=cuts.size();
    vector<vector<int>>dp(m,vector<int>(m,0));
    for(int i=m-2;i>=1;i--){
        for(int j=i;j<=m-2;j++){
            int mini=INT_MAX;
            for(int ind=i;ind<=j;ind++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini=min(mini,cost);
                    }
                     dp[i][j] = mini;
            }

         }
         return dp[1][m-2];
    }
int main(){
int n;
cout<<"Enter n : ";
cin>>n;
int m;
cout<<"Enter no of time to be cut : ";
vector<int>cuts;
cin>>m;
cout<<"Enter the elements of teh array : ";
for(int i=0;i<m;i++){
    int item;
    cin>>item;
    cuts.push_back(item);
}
cuts.push_back(n);
cuts.push_back(0);
sort(cuts.begin(),cuts.end());
vector<vector<int>>dp(n,vector<int>(n,-1));
cout<<"Minimum cost by recursion : "<<solve_by_recursion(1,m,cuts)<<endl;
cout<<"Minimum cost by memoization : "<<solve_by_memoization(1,m,cuts,dp)<<endl;
cout<<"Minimum cost by tabulation : "<<solve_by_tabulation(cuts)<<endl;
}