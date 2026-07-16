# include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    string ans="";
    int j=1;
    for(int i=0;i<n;i+=j){
        ans+=str[i];
        j++;
    }
    cout<<ans<<endl;
}