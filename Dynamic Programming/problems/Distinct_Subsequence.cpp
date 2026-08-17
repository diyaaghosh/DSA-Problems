# include<bits/stdc++.h>
using namespace std;
int solve_by_recursion(int i,int j,string s1,string s2){
    if(j<0)return 1;
    if(i<0)return 0;
    if(s1[i]==s2[j]){
        return solve_by_recursion(i-1,j-1,s1,s2)+solve_by_recursion(i-1,j,s1,s2);
    }
    else{
        return solve_by_recursion(i-1,j,s1,s2);
    }
}
int solve_by_memoization(int i,int j,string s1,string s2,vector<vector<int>>dp){
    if(j<0)return 1;
    if(i<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]=solve_by_memoization(i-1,j-1,s1,s2,dp)+solve_by_memoization(i-1,j,s1,s2,dp);
    }
    else{
        return dp[i][j]=solve_by_memoization(i-1,j,s1,s2,dp);
    }
}
int solve_by_tabulation(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}
int solve_by_space_optimization(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<int>prev(m+1,0);
    
        prev[0]=1;
    
    
    for(int i=1;i<=n;i++){
        vector<int>curr(m+1,0);
        curr[0] = 1;
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]=prev[j]+prev[j-1];
            }
            else{
                curr[j]=prev[j];
            }
        }
        prev=curr;
    }
    return prev[m];
}

int solve_by_space_optimization_1D(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<int>prev(m+1,0);
    
        prev[0]=1;
    
    
    for(int i=1;i<=n;i++){
        
         for(int j=m;j>=1;j--){
            if(s1[i-1]==s2[j-1]){
                prev[j]=prev[j]+prev[j-1];
            }
           
        }
       
    }
    return prev[m];
}
int main(){
    string str1,str2;
    cout<<"Enter the string 1 : ";
    cin>>str1;
    cout<<"Enter the string 2 : ";
    cin>>str2;
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<"Solving by recursion : "<<solve_by_recursion(n-1,m-1,str1,str2)<<endl;
    cout<<"Solving by memoization : "<<solve_by_memoization(n-1,m-1,str1,str2,dp)<<endl;
    cout<<"Solving by tabulation : "<<solve_by_tabulation(str1,str2)<<endl;
    cout<<"Solving by space optimization : "<<solve_by_space_optimization(str1,str2)<<endl;
    cout<<"Solving by 1D Space Optimization : "<<solve_by_space_optimization_1D(str1,str2)<<endl;
}