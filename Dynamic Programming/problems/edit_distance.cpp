# include<bits/stdc++.h>
using namespace std;
int solve_by_recursion(int i,int j,string s1,string s2){
if(i<0)return j+1;
if(j<0)return i+1;

if(s1[i]==s2[j]){
    return solve_by_recursion(i-1,j-1,s1,s2);
}
else{
  int  insert_cnt=1+solve_by_recursion(i,j-1,s1,s2);
  int delete_cnt=1+solve_by_recursion(i-1,j,s1,s2);
  int replace_cnt=1+solve_by_recursion(i-1,j-1,s1,s2);
  return min(insert_cnt,min(delete_cnt,replace_cnt));
}
}
int solve_by_memoization(int i,int j,string s1 ,string s2,vector<vector<int>>&dp){
    if(i==0)return j;
    if(j==0)return i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1]){
        return dp[i][j]=solve_by_memoization(i-1,j-1,s1,s2,dp);
    }
    else{
         int  insert_cnt=1+solve_by_memoization(i,j-1,s1,s2,dp);
         int delete_cnt=1+solve_by_memoization(i-1,j,s1,s2,dp);
         int replace_cnt=1+solve_by_memoization(i-1,j-1,s1,s2,dp);
         return dp[i][j]=min(insert_cnt,min(delete_cnt,replace_cnt));
    }
}
int solve_by_tabulation(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int insert_cnt=dp[i][j-1]+1;
                int delete_cnt=dp[i-1][j]+1;
                int replace_cnt=dp[i-1][j-1]+1;
                dp[i][j]=min(insert_cnt,min(delete_cnt,replace_cnt));
            }
        }
    }
    return dp[n][m];
}

int solve_by_space_optimization(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
   vector<int>prev(m+1,0);
    for(int j = 0; j <= m; j++){
        prev[j] = j;
    }
    
    for(int i=1;i<=n;i++){
        vector<int>curr(m+1,0);
        curr[0] = i;
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]=prev[j-1];
            }
            else{
                int insert_cnt=curr[j-1]+1;
                int delete_cnt=prev[j]+1;
                int replace_cnt=prev[j-1]+1;
                curr[j]=min(insert_cnt,min(delete_cnt,replace_cnt));
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
    for(int j = 0; j <= m; j++){
        prev[j] = j;
    }
    
    for(int i=1;i<=n;i++){
       int prevDiag = prev[0];  
        prev[0] = i;  
        for(int j=1;j<=m;j++){
             int temp = prev[j];  

            if(s1[i-1] == s2[j-1]){
                prev[j] = prevDiag;
            }
            else{
                int insert_cnt=prev[j-1]+1;
                int delete_cnt=prev[j]+1;
                int replace_cnt=prevDiag + 1;
                prev[j]=min(insert_cnt,min(delete_cnt,replace_cnt));
            }
              prevDiag = temp;
        }
      
      
    }
    return prev[m];
}
int main(){
    string s1;
    string s2;
    cout<<"Enter 1st string : ";
    cin>>s1;
    cout<<"Enter 2nd string : ";
    cin>>s2;
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<"Solving by recursion : "<<solve_by_recursion(n-1,m-1,s1,s2)<<endl;
    cout<<"Solving by memoization : "<<solve_by_memoization(n,m,s1,s2,dp)<<endl;
    cout<<"Solving by tabulation : "<<solve_by_tabulation(s1,s2)<<endl;
    cout<<"Solving by space optimization : "<<solve_by_space_optimization(s1,s2)<<endl;
    cout<<"Solving by 1D Space optimization : "<<solve_by_space_optimization_1D(s1,s2)<<endl;

}