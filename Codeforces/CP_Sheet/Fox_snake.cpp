#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>mat(n,vector<char>(m,'.'));
    int flag=1;
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
        if(i%2==0)mat[i][j]='#';
        else {
            if(flag==1){
                mat[i][m-1]='#';
                flag=0;
                break;
            }
            else{
                flag=1;
                mat[i][0]='#';
                break;
            }
        }
       }
    }
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}