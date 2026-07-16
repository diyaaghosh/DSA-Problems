# include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i+=1){
        cin>>arr[i];
    }
    map<int,int>mpp;
    for(int i=0;i<n;i+=1){
        mpp[arr[i]-1]=i+1;
    }
    vector<int>ans(n,0);
    for(auto [a,b]:mpp){
        ans[a]=b;
    }
    for(int i=0;i<n;i+=1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}