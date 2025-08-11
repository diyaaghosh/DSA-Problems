#include<bits/stdc++.h>
using namespace std;
void solve(int n,int m,int i,int j, vector<vector<int>>& vis,vector<string>&ans,vector<vector<int>>&a,string temp){
// base case
if(i==n-1 && j==m-1){
    ans.push_back(temp);
    return;
}
// down
if(i+1<n && vis[i+1][j]!=1 && a[i+1][j]!=0){
    vis[i+1][j]=1;
    solve(n,m,i+1,j,vis,ans,a,temp+'D');
    vis[i+1][j]=0;
}
// Left
if(j-1>=0 && vis[i][j-1]!=1 && a[i][j-1]!=0){
    vis[i][j-1]=1;
    solve(n,m,i,j-1,vis,ans,a,temp+'L');
    vis[i][j-1]=0;
}
// Right
if(j+1<m && vis[i][j+1]!=1 && a[i][j+1]!=0){
    vis[i][j+1]=1;
    solve(n,m,i,j+1,vis,ans,a,temp+'R');
    vis[i][j+1]=0;
}
// Up
if(i-1>=0 && vis[i-1][j]!=1 && a[i-1][j]!=0){
    vis[i-1][j]=1;
    solve(n,m,i-1,j,vis,ans,a,temp+'U');
    vis[i-1][j]=0;
}
return;
}
int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    int m;
    cout<<"enter m : ";
    cin>>m;
    vector<vector<int>>a(n,vector<int>(m));
    cout<<"enter elements in the matrix :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<string>ans;
    vector<vector<int>>vis(n,vector<int>(m,0));
    if(a[0][0]!=0){
        vis[0][0]=1;
    solve(n,m,0,0,vis,ans,a,"");
    }
    cout<<"Paths in lexicographical order : \n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}