# include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<long long,int>mpp;
        for(int i=0;i<n;i+=1){
            if(s[i]=='1'){
                mpp[i]=1;
            }
            else {
                mpp[i]=0;
            }
        }
        int last=n-k;
        for(int i=0;i<last;i+=1){
            int f=i;
            int l=i+k;
            if(l<n){
               if(mpp[f]==1){
                    mpp[l]=!mpp[l];
                    mpp[f]=!mpp[f];
                }
            }
        }
        int flag=1;
       for(int i=0;i<n;i+=1){
        if(mpp[i]!=0){
            cout<<"NO"<<endl;
            flag=0;
            break;
        }
       }
        if(flag==1){
            cout<<"YES"<<endl;
        }

    }
}