#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
     long long n,x1,x2,k;
     cin>>n>>x1>>x2>>k;
     long long ans=0;
     if(x1==x2){
        cout<<ans<<endl;
        continue;
     }
    int distance=abs(x1-x2);
    int reverse_distance=n-distance;
    int minimum_shortest_distance=min(distance,reverse_distance);
    if(n<=3)cout<<1<<endl;
    else
    cout<<k+minimum_shortest_distance<<endl;
    }
}