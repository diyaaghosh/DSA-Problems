#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<long long>a(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<long long>c(n,0);
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        int flag=1;
        for(int i=1;i<n;i++){
            if(c[i]<c[i-1]){
                flag=0;
                break;
            }
        }
        if(s[0]=='1' && a[0]!=c[0]){
            flag=0;
        }
        if(flag==0){
            cout<<"No"<<endl;
            continue;
        }
        vector<long long>lower_bound(n,LONG_LONG_MIN);
        lower_bound[0]=c[0];
        // forced increase
        for(int i=1;i<n;i++){
            if(c[i]>c[i-1]){
                lower_bound[i]=c[i];
            }
        }
        //Forward Propagation
   
     for(int i=1;i<n;i++){
    if(s[i]=='1'){
        c[i]=min(c[i],c[i-1]+a[i]);

        if(lower_bound[i-1]!=LLONG_MIN){
            lower_bound[i]=max(lower_bound[i],lower_bound[i-1]+a[i]);
        }
    }
}
        // backwatd propagation
   for(int i=n-1;i>=1;i--){
    if(s[i]=='1'){
        c[i-1]=min(c[i-1],c[i]-a[i]);

        if(lower_bound[i]!=LLONG_MIN){
            lower_bound[i-1]=max(lower_bound[i-1],lower_bound[i]-a[i]);
        }
    }
}
        for(int i=0;i<n;i++){
            if(c[i]<lower_bound[i]){
                flag=0;
                break;
            }
        }
        if(flag==0){
            cout<<"No"<<endl;
            continue;
        }
        vector<long long>b(n,0);
        b[0]=c[0];
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                b[i]=b[i-1]+a[i];
            }
            else{
                b[i]=c[i];
            }
        }
        vector<long long>ans;
        ans.push_back(b[0]);
        for(int i=1;i<n;i++){
            ans.push_back(b[i]-b[i-1]);
        }
        cout<<"Yes"<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}