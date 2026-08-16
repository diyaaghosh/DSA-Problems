# include<bits/stdc++.h>
using namespace std;
void solve(int ind,vector<int>&arr,int target,vector<int>&temp,vector<vector<int>>&ans){
    int n=arr.size();
if(ind==n){
        if(target==0){
        ans.push_back(temp);
       
    }
     return;
}
    if(arr[ind]<=target){
        // pick
        temp.push_back(arr[ind]);
        solve(ind,arr,target-arr[ind],temp,ans);
        // not pick
        temp.pop_back();

    }
        solve(ind+1,arr,target,temp,ans);
        return;
}
// solve this with all dupliacte combination
void solve_(vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans,int target){
    int n=arr.size();
    if(target==0){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(target>=arr[i]){
            // pick
            temp.push_back(arr[i]);
            solve_(arr,temp,ans,target-arr[i]);
           
           temp.pop_back();
          
            
        }
    }
    return;
}
void solve_I(vector<int>&arr,vector<int>&temp,set<vector<int>>&ans,int target){
    int n=arr.size();
    if(target==0){
        sort(temp.begin(),temp.end());
        ans.insert(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(target>=arr[i]){
            // pick
            temp.push_back(arr[i]);
            solve_I(arr,temp,ans,target-arr[i]);
           
           temp.pop_back();
          
            
        }
    }
    return;
}
int main(){
    int n;
    cout<<"Enter n  : ";
    cin>>n;
    vector<int>arr(n,0);
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i+=1){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter target : ";
    cin>>target;
    cout<<"Combination Sum : "<<endl;
    vector<int>temp;
    set<vector<int>>ans;
    // solve(0,arr,target,temp,ans);
    solve_I(arr,temp,ans,target);
        for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}