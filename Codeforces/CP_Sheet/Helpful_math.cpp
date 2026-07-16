#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
   vector<int>a;
    for(int i=0;i<str.size();i+=1){
        if(str[i]=='1' || str[i]=='2' || str[i]=='3'){
            a.push_back(str[i]-'0');
        }
    }
sort(a.begin(),a.end());
string ans="";
int n=a.size();
for(int i=0;i<a.size()-1;i++){
ans+=(a[i]+'0');
ans+='+';
}
ans+=(a[n-1]+'0');
cout<<ans<<endl;
}