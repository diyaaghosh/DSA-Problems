# include<bits/stdc++.h>
// asked in wells fargo interview
using namespace std;
void traverse(int ind,vector<int>&arr){
    int n=arr.size();
    if(ind==n){
        return;
    }
    cout<<arr[ind]<<" ";
    traverse(ind+1,arr);
    return;
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    vector<int>arr(n,0);
    cout<<"Enter the lements of the arary : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Traversing the array using recursion : ";
    traverse(0,arr);
}