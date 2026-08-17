#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>mat){
    int n=mat.size();
    int m=mat[0].size();
    int sum=0;
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        dp[i][0]=mat[i][0];
    }
    for(int i=1;i<m;i++){
        dp[0][i]=mat[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]==0){
                dp[i][j]=0;
            }
            else{
                
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum+=dp[i][j];
        }
    }
    return sum;
}
int main(){
    int n;
    cout<<"Enter n  : ";
    cin>>n;
    int m;
    cout<<"Enter m  : ";
    cin>>m;
    cout<<"Enter the lements of the matrix : \n";
    vector<vector<int>>mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    cout<<"Maximum no of summatrices filled with 1 : "<<solve(mat)<<endl;
}