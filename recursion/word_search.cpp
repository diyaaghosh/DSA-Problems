#include<bits/stdc++.h>
using namespace std;
bool search_in_all_direction(vector<vector<char>>&board,string & target,int n,int m,int index,int i,int j){
if(index==target.size())return true; // base case
if (i<0 || j<0 ||i==n || j==m || board[i][j]=='!' || board[i][j]!=target[index] ) return false;
char c=board[i][j];
board[i][j]='!'; // avoiding used cell
bool top=search_in_all_direction(board,target,n,m,index+1,i-1,j); // top
bool bottom =search_in_all_direction(board,target,n,m,index+1,i+1,j); // bottom
bool left=search_in_all_direction(board,target,n,m,index+1,i,j-1);// left
bool right=search_in_all_direction(board,target,n,m,index+1,i,j+1);// right
board[i][j]=c;
return top|| left||right||bottom;
}
bool exist(vector<vector<char>>&board,string & target,int n,int m){
int index=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(board[i][j]==target[index]){
         if(search_in_all_direction(board,target,n,m,index,i,j)){
            return true;
         }
        }
    }
}
return false;
}
int main(){
    int n,m;
    cout<<"enter the no of rows : ";
    cin>>n;
    cout<<"enter the no of columns : ";
    cin>>m;
    
      vector<vector<char>> board(n, vector<char>(m));
    cout<<"enter the characters in the board \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    string target;
    cout<<"enter the target : ";
    cin>>target;
bool ans=exist(board,target,n,m);
if(ans==0){
    cout<<"False"<<endl;
}
else{
    cout<<"True"<<endl;
}
}