# include<bits/stdc++.h>
using namespace std;
void solve(int ind,vector<int>&arr,vector<int>&temp,int sum,int k,vector<vector<int>>&ans){
    int n=arr.size();
    if(ind==n){
        if(sum==k){
            ans.push_back(temp);
        }
        return;
    }
    // take
    temp.push_back(arr[ind]);
    sum+=arr[ind];
    solve(ind+1,arr,temp,sum,k,ans);
    // not take
    temp.pop_back(); // backtracking
    sum-=arr[ind];
    solve(ind+1,arr,temp,sum,k,ans);
    return;

}
int main(){
    int n;
    cout<<"Enter n  : ";
    cin>>n;
    vector<int>arr(n,0);
    cout<<"Enter the elements of the arary : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter k : ";
    cin>>k;
    vector<vector<int>>ans;
    vector<int>temp;
    int sum=0;
    solve(0,arr,temp,sum,k,ans);
    cout<<"Subsequences : "<<endl;
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}