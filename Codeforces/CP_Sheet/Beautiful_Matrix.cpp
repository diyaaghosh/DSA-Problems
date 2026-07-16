#include<bits/stdc++.h>
using namespace std;
int main(){
    int row=0,col=0;
    vector<vector<int>>mat(5,vector<int>(5,0));
    for(int i=0;i<5;i+=1){
        for(int j=0;j<5;j+=1){
            
            cin>>mat[i][j];
            if(mat[i][j]==1){
                row=i;
                col=j;
            }
        }
    }
   cout<<abs(2-row)+abs(2-col)<<endl;
    
}