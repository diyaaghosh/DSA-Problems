#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
int  solve_by_recursion(int ind1,int ind2,string s1,string s2){
    if(ind1<0 || ind2<0)return 0;
    if(s1[ind1]==s2[ind2])return 1+solve_by_recursion(ind1-1,ind2-1,s1,s2);
    return max(solve_by_recursion(ind1-1,ind2,s1,s2),solve_by_recursion(ind1,ind2-1,s1,s2));
}
int solve_by_memoization(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
    if(ind1<0 || ind2<0)return 0;
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2])return dp[ind1][ind2]=1+solve_by_memoization(ind1-1,ind2-1,s1,s2,dp);
    return dp[ind1][ind2]=max(solve_by_memoization(ind1-1,ind2,s1,s2,dp),solve_by_memoization(ind1,ind2-1,s1,s2,dp));
}
int solve_by_tabulation(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int solve_by_space_optimization(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<int>prev(m+1,0);
    vector<int>curr(m+1,0);
    
    for(int j=0;j<=m;j++){
       prev[j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])curr[j]=prev[j-1]+1;
            else{
                curr[j]=max(prev[j],curr[j-1]);
            }
        }
        prev=curr;
    }
    return prev[m];
}
int main(){
    int n;
    cout<<"Enter dimension of string  : ";
    cin>>n;
    string str1;
    cout<<"Enter the string  : ";
    cin>>str1;
    string str2=str1;
    reverse(str2.begin(),str2.end());
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<"Solving by recursion : "<<solve_by_recursion(n-1,n-1,str1,str2)<<endl;
    cout<<"Solving by memoization : "<<solve_by_memoization(n-1,n-1,str1,str2,dp)<<endl;
    cout<<"Solving by tabulation : "<<solve_by_tabulation(str1,str2)<<endl;
    cout<<"Solving by space optimization : "<<solve_by_space_optimization(str1,str2)<<endl;

}