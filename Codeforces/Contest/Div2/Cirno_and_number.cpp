#include<bits/stdc++.h>
using namespace std;
int func(long long sum,long long digit1,long long digit2,long long a,long long mini,long long n,long long len){
if(len>n)return  mini;
if(len>0){
    mini=min(mini,abs(a-sum));
}
 if(sum > a + mini) return mini;
// take digit1

mini=func(sum*10+digit1,digit1,digit2,a,mini,n,len+1);
// take digit2

mini=func(sum*10+digit2,digit1,digit2,a,mini,n,len+1);
return mini;

}

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long a,n;
        cin>>a>>n;
        vector<long long>d(n,0);
        for(int i=0;i<n;i++){
            cin>>d[i];
        }
        string temp=to_string(a);
        long long x=temp.size();
        long long mini=LLONG_MAX;
        mini = func(d[0], d[0], d[1], a, mini, x + 1, 1);
        mini = func(d[1], d[0], d[1], a, mini, x + 1, 1);
       cout<<mini<<endl;
    }
}