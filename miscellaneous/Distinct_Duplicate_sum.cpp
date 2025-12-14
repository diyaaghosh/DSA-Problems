# include<bits/stdc++.h>
using namespace std;
int solve(int a,int b,int c,int d){
map<int,int>mpp;
mpp[a]++;
mpp[b]++;
mpp[c]++;
mpp[d]++;
int sum1=0;
int sum2=0;
for(auto [a,b]:mpp){
if(b==1)sum1+=a;
else sum2+=a;
}
return sum1-sum2;
}
int main(){
    int a,b,c,d;
    cout<<"Enter a,b,c,d : ";
    cin>>a>>b>>c>>d;
    int ans=solve(a,b,c,d);
    cout<<"Distinct Duplicate sum : "<<ans<<endl;
}
