#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int maxi=arr[0];
        int k=0;
        for(int i=1;i<n;i++){
            if(arr[i]<maxi){
                int diff=maxi-arr[i];
                k=max(k,diff);
            }
            else maxi=arr[i];
        }
        int flag=1;
        if(k==0){
            cout<<"Yes"<<endl;
            
        }
        else{
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1])continue;
            else if(arr[i]+k>=arr[i-1]){
                arr[i]+=k;
            }
            else {
                flag=0;
                cout<<"No"<<endl;
                break;
            }
        }
        if(flag==1){
            cout<<"Yes"<<endl;
            
        }
    }

    }
return 0;
}