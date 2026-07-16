#include<bits/stdc++.h>
using namespace std;
int main(){
    long long    n;
    cin>>n;
    string temp=to_string(n);
    
    int cnt=0;
    for(int i=0;i<temp.size();i+=1){
      
        if(temp[i]=='7' || temp[i]=='4')cnt+=1;
    }
    if(cnt==7 || cnt==4)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}