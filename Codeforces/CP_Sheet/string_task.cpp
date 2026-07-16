# include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    string ans="";
    for(int i=0;i<n;i+=1){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='y' || s[i]=='Y'){
            continue;
        }
        else{
            ans+='.';
            if(s[i]>=65 && s[i]<=90){
                s[i]+=32;
            }
            ans+=s[i];
        }
    }
    cout<<ans<<endl;
}