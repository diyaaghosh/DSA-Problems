#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int flag=1;
        vector<int>arr(n,0);
        for(int i=0;i<n;i+=1){
            cin>>arr[i];
        }
        sort(arr.rbegin(),arr.rend());
        int x=0,y=0;
        if(n==2){
            cout<<arr[0]<<" "<<arr[1]<<endl;
        }
        else{
            for(int i=2;i<n;i++){
                x=arr[0];
                y=arr[1];
                int exp=arr[i-2]%arr[i-1];
                if(exp!=arr[i]){
                    
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                cout<<x<<" "<<y<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
}