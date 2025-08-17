#include<bits/stdc++.h>
using namespace std;
void power_set(vector<int>& arr, vector<vector<int>> & ans){
    int n=arr.size();
    int subsets=(1<<n);
    
    for(int i=0;i<subsets;i++){
        vector<int>list;
        for(int j=0;j<n;j++){
        if((i & (1<<j))!=0){
            list.push_back(arr[j]);
        }
        }
        ans.push_back(list);
    }
}
int main(){
    int n;
    cout<<"enter the dimension : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter the elements in the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
vector<vector<int>>ans;
cout<<"Possible subsets  : "<<endl;
power_set(arr,ans);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
}