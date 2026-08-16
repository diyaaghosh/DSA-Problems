# include<bits/stdc++.h>
using namespace std;
void solve(int i,int j,vector<vector<int>>&mat,vector<string>&ans,string temp,vector<vector<int>>&vis){
    int n=mat.size();
    int m=mat[0].size();
    if(i==n-1 && j==m-1){
        ans.push_back(temp);
        return;
    }
    // down
    if(i+1<n && vis[i+1][j]!=1 && mat[i+1][j]!=0){
        vis[i+1][j]=1;
        solve(i+1,j,mat,ans,temp+'D',vis);
        vis[i+1][j]=0;
    }
    // top
    // if(i-1>=0 && vis[i-1][j]!=1 && mat[i-1][j]!=0){
    //     vis[i+1][j]=1;
    //     solve(i+1,j,mat,ans,temp+'U',vis);
    //     vis[i+1][j]=0;  
    // }

    // left

    // if(j-1>=0 && vis[i][j-1]!=1 && mat[i][j-1]!=0){
    //     vis[i][j-1]=1;
    //     solve(i,j-1,mat,ans,temp+'L',vis);
    //     vis[i][j-1]=0;  
    // }
    // right
    
    if(j+1<m && vis[i][j+1]!=1 && mat[i][j+1]!=0){
        vis[i][j+1]=1;
        solve(i,j+1,mat,ans,temp+'R',vis);
        vis[i][j+1]=0;  
    }
    return;

}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int m;
    cout<<"Enter m : ";
    cin>>m;
    vector<vector<int>>mat(n,vector<int>(m,0));
    cout<<"Enter the elements of the matrix : ";
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            cin>>mat[i][j];
        }
    }
    string temp="";
    vector<string>ans;
    vector<vector<int>>vis(n,vector<int>(m,0));
    solve(0,0,mat,ans,temp,vis);
    cout<<"Differenet combination : \n";
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }    
}