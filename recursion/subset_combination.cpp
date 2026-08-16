# include<bits/stdc++.h>
using namespace std;
// subsequence should be in sorted order
// subsequence should not be repeated i.e one element will be used for one times
// solve this with all dupliacte combination
void solve_(int ind,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans){
    int n=arr.size();
    
        ans.push_back(temp);
       
    
    for(int i=ind;i<n;i++){
        if(i>ind && arr[i]==arr[i-1])continue;
       
      
            // pick
            temp.push_back(arr[i]);
            solve_(i+1,arr,temp,ans);
           
           temp.pop_back();
          
            
        
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
    sort(arr.begin(),arr.end());

    cout<<"Subset : "<<endl;
    vector<int>temp;
    vector<vector<int>>ans;
    // solve(0,arr,target,temp,ans);
    solve_(0,arr,temp,ans);
        for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}