# include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i+=1){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int maxi=arr[n-1];
    int mini=arr[0];
    int target=maxi+1-mini;
    cout<<target<<endl;
}
}