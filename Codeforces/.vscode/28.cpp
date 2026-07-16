#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
       int a[n];
        for(int j=1;j<=n;j++){
        a[j-1]=j;
        }
        int n_half=(n%2==0)?n/2-1:n/2;
        int ans[n];
        
        for(int k=0;k<n_half;k++){
            ans[k]=a[k+1];
        }
        ans[n_half]=a[n-1];
        ans[n-1]=a[0];
        for(int k=n_half+1;k<n-1;k++){
            ans[k]=a[k];
        }
        for(int k=0;k<n;k++){
            cout<<ans[k]<<" ";
        }
        cout<<endl;
    
    }
}