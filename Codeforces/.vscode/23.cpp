#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    int t;
    

     
    cin>>t;
    for(int i=0;i<t;i++){
    int n,m;
    cin>>n;
    cin>>m;
   string x="",s="";
    for(int j=0;j<n;j++){
   char ch;
   cin>>ch;
   x+=ch;

    }
      for(int j=0;j<m;j++){
   char ch;
   cin>>ch;
   s+=ch;

    }
    int cnt=0;
    int ans=-1;
    int flag=0;
    for(int j=0;j<=5;j++){
    if(x.find(s) == string::npos) {
        x+=x;
        cnt++;
    }
    else{
        flag=1;
        break;
    }
    }
 if(flag==0) cout<<ans<<endl;
 else cout<<cnt<<endl;
 
 }
}

