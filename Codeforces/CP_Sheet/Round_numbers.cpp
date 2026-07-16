#include<bits/stdc++.h>
using namespace std;
int main(){
long long t;
cin>>t;
while(t--){
    long long n;
    cin>>n;
    vector<long long>ans;
        long long p=1;
      
    while(n){
        long long rem=n%10;
        if(rem*p!=0)ans.push_back(rem*p);
        n=n/10;
        p=p*10;
        
    }
    cout<<ans.size()<<endl;
    for(auto num:ans){
        cout<<num<<" ";
    }
    cout<<endl;
}
}