#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int>mpp;
        vector<int>ans;
        for(int i=1;i<=2*n;i++){
            if(mpp.find(i)==mpp.end()){
                mpp[i]++;
                if(ans.size()!=0)mpp[i+ans.back()]++;
                ans.push_back(i);
                if(ans.size()==n)break;
            }
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}