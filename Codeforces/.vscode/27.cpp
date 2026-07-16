#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x;
        cin>>n>>x;
        int a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        int v=0;
        for(int k=0;k<n;k++){
            if(a[k]==1){
                v=k;
                break;
            }
        }
        int flag=1;
        for(int k=v+x;k<n;k++){
            if(a[k]!=0){
                 cout<<"NO"<<endl;
                 flag=0;
                 break;
            }
        }
         if(flag==1)
            cout<<"YES"<<endl;
        
        
    }
}