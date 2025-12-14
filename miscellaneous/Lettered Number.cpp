# include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
int n=s.size();
int ans=0;
for(int i=0;i<n;i++){
    if(s[i]=='A'){
    ans+=1;
    }
    else if(s[i]=='B'){
        ans+=10;
    }
    else if(s[i]=='C'){
        ans+=100;
    }
    else if(s[i]=='D'){
        ans+=1000;
    }
    else if(s[i]=='E'){
        ans+=10000;
    }
    else if(s[i]=='F'){
        ans+=100000;
    }
    else{
        ans+=1000000;
    }
}
cout<<"Result : "<<ans<<endl;
}
