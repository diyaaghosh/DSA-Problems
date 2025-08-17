#include<bits/stdc++.h>
using namespace std;
int single_number_I(vector<int>&arr){
    int x=0;
    for(auto it:arr){
        x=x ^ it;
    }
return x;
}
int main(){
    int n;
    cout<<"enter the dimension : ";
    cin>>n;
    cout<<"enter the elements of the array : ";
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=single_number_I(arr);
    cout<<"single number : "<<ans;
}