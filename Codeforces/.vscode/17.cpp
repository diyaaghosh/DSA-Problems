#include<iostream>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n;
        cin>>k;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int brr[n];
        for(int j=0;j<n;j++){
              brr[j]=arr[j];
        }
        int flag=1;
        sort(brr,brr+n);
        for(int j=0;j<n;j++){
            if(arr[j]!=brr[j]){
                flag=0;
                break;
            }
        }
        if(flag==1|| k>1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
      

    }
}




















