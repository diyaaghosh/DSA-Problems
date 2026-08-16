# include<bits/stdc++.h>
using namespace std;
void solve(int ind,vector<int>&arr,int sum,vector<int>&ans){
    int n=arr.size();
    if(ind==n){
        ans.push_back(sum);
        return;
    }
    solve(ind+1,arr,sum+arr[ind],ans);// pick
    solve(ind+1,arr,sum,ans);// not pick
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
    cout<<"Subset Sum : "<<endl;
    vector<int>ans;
    int sum=0;
    solve(0,arr,sum,ans);
        for(auto it:ans){
       
            cout<<it<<" ";
        
      
    }
}