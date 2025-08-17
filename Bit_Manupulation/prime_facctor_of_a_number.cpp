#include<bits/stdc++.h>
using namespace std;
vector<int>prime_factor(int n){
    vector<int>list;
for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
        list.push_back(i);
        while(n%i==0){
            n=n/i;
        }
    
    }
}
if(n!=1){
    list.push_back(n); 
}
return list;
}
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
vector<int>ans=prime_factor(n);
cout<<"prime factors of "<<n<<" is ";
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
}