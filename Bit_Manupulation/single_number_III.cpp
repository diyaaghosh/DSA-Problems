#include<bits/stdc++.h>
using namespace std;
// using bucket
vector<int>single_number(vector<int>& arr){
    int n=arr.size();
    long long x=0;
    for(int i=0;i<n;i++){
     x=x^arr[i];
    }
    // find the right most set bit
    int b1=0;
    int b2=0; // two buckets
    long long right_most=(x & (x-1)) ^ x;
    for(int i=0;i<n;i++){
        if((arr[i] & right_most )!=0){
        // turned to 1
        b1 = b1 ^ arr[i];
        }
        else{
            b2=b2^arr[i];
        }
    }
    return {b1,b2};
}
int main(){
    int n;
    cout<<"enter the dimemsion : ";
    cin>>n;
    cout<<"enter the elements of the array : ";
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans=single_number(arr);
    cout<<"two distinct numbers are : "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}