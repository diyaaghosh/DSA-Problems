#include<bits/stdc++.h>
using namespace std;
void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n,vector<int>&leftrow,vector<int>&lower_diagonal,vector<int>&upper_diagonal){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
    if(leftrow[row]==0 && lower_diagonal[row+col]==0 && upper_diagonal[n-1+col-row]==0){
        board[row][col]='Q';
        leftrow[row]=1;
        lower_diagonal[row+col]=1;
        upper_diagonal[n-1+col-row]=1;
        solve(col+1,ans,board,n,leftrow,lower_diagonal,upper_diagonal);
        // backtarcking
        board[row][col]='.';
        leftrow[row]=0;
        lower_diagonal[row+col]=0;
        upper_diagonal[n-1+col-row]=0;
    }
    }
}
int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
vector<vector<string>>ans;
vector<string>board(n);
string s(n,'.');
for(int i=0;i<n;i++){
    board[i]=s;
}
vector<int>lower_diagonal(2*n-1,0);
vector<int>upper_diagonal(2*n-1,0);
vector<int>leftrow(n,0);
solve(0,ans,board,n,leftrow,lower_diagonal,upper_diagonal);
for(int i=0;i<ans.size();i++){
   for(int j=0;j<ans[i].size();j++){
    cout<<ans[i][j]<<endl;
   }
   cout<<endl;
}
}