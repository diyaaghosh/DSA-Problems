# include<bits/stdc++.h>
using namespace std;
bool is_safe(int row,int col,vector<string>&board){
      int n=board.size();
      int r=row;
      int c=col;
      while(row>=0 and col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
      }
      row=r;
      col=c;
      while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
      }
     row=r;
      col=c;
      while(col>=0 and row<n){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col--;
      }
      return true;
}
void solve(int col,vector<string>&board,vector<vector<string>>&ans){
    int n=board.size();
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row+=1){
        if(is_safe(row,col,board)){
            board[row][col]='Q';
            solve(col+1,board,ans);
            board[row][col]='.';
        }
    }
}
int main(){
    int n;
    cout<<"Enter n  : ";
    cin>>n;
    vector<string>board(n);
    cout<<"Enter the board position : ";
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        board[i]=s;
    }
    vector<vector<string>>ans;
    solve(0,board,ans);
    cout<<"Differenet Combinations : \n";
    for(auto it :ans){
        for(auto i: it){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
}