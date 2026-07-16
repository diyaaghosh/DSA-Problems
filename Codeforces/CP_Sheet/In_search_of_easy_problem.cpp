# include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i+=1){
        cin>>arr[i];
    }
    int flag=1;
    for(int i=0;i<n;i+=1){
        if(arr[i]==1){
            cout<<"Hard"<<endl;
            flag=0;
            break;
        }
    }
    if(flag==1){
        cout<<"Easy"<<endl;
    }
}