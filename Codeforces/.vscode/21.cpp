#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int t;
    

     
    cin>>t;
    for(int i=0;i<t;i++){
    int n;
    cin>>n;
    int arr[n];
    for(int j=0;j<n;j++){
    cin>>arr[j];
    }
    if(arr[0]!=1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    }
}