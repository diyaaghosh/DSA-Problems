# include<bits/stdc++.h>
using namespace std;
bool solve_by_recursion(int i,int j,string s1,string s2){
    if(i<0 && j<0)return true;
    if(i<0 && j>=0)return false;
    if(j<0 && i>=0){
        for(int i1=0;i1<=i;i1++){
            if(s1[i1]!='*')return false;
        }
        return true;
    }
    if(s1[i]==s2[j] || s1[i]=='?'){
       return solve_by_recursion(i-1,j-1,s1,s2);
    }
    else if(s1[i]=='*'){
       return solve_by_recursion(i-1,j,s1,s2) or solve_by_recursion(i,j-1,s1,s2);
    }
    else return false;
}
int solve_by_memoization(int i,int j,string s1,string s2,vector<vector<int>>&dp){
    if(i==0 && j==0)return 1;
    if(i==0 && j>0)return 0;
    if(j==0 && i>0){
        for(int i1=1;i1<=i;i1++){
            if(s1[i1-1]!='*')return 0;
        }
        return 1;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
       return dp[i][j]=solve_by_memoization(i-1,j-1,s1,s2,dp);
    }
    else if(s1[i-1]=='*'){
       return dp[i][j]=solve_by_memoization(i-1,j,s1,s2,dp) || solve_by_memoization(i,j-1,s1,s2,dp);
    }
    else return dp[i][j]=0;
}
int solve_by_tabulation(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[0][0]=1;
    for(int j=1;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
       if(s1[i-1]=='*') dp[i][0]=1;
       else dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(s1[i-1]=='*'){
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
            else{
                dp[i][j]=0;
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
    for(int j=1;j<=m;j++){
        prev[j]=0;
    }
    
    for(int i=1;i<=n;i++){
        vector<int>curr(m+1,0);
         curr[0] = prev[0] && (s1[i-1] == '*');
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
                curr[j]=prev[j-1];
            }
            else if(s1[i-1]=='*'){
               curr[j]=prev[j] || curr[j-1];
            }
            else{
                curr[j]=0;
            }
        }
        prev=curr;
    }
    return prev[m];

}
int main(){
    string s1,s2;
    cout<<"Enter string 1 : ";
    cin>>s1;
    cout<<"Enter string 2 : ";
    cin>>s2;
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<"Solving by recursion : "<<solve_by_recursion(n-1,m-1,s1,s2)<<endl;
    cout<<"Solving by memization : "<<solve_by_memoization(n,m,s1,s2,dp)<<endl;
    cout<<"Solving by tabulation : "<<solve_by_tabulation(s1,s2)<<endl;
    cout<<"Solving by space optimization : "<<solve_by_space_optimization(s1,s2)<<endl;

}