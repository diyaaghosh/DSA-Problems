# include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i+=1){
        cin>>arr[i];
    }
    int cnt=1;
    int maxi=INT_MIN;
    for(int i=1;i<n;i+=1){
        if(arr[i-1]<arr[i]){
            cnt++;
        }
        else{
            maxi=max(maxi,cnt);
            cnt=1;
        }
    }
     maxi=max(maxi,cnt);
    cout<<maxi<<endl;
}