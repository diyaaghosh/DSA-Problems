#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int t;
    

     
    cin>>t;
    for(int i=0;i<t;i++){
     int n;
     cin>>n;
     string s="";
     for(int j=0;j<n;j++){
     char ch;
     cin>>ch;
     s+=ch;
     }
     int flag=0;
     int cnt=0;
     for(int j=0;j<n;j++){
        if(s[j]=='.' && j+1<n && j+2 <n && s[j+1]=='.' && s[j+2]=='.'){
            flag=1;
            cnt=2;
            break;
        }
        if(s[j]=='.'){
            cnt++;
        }
     }
     cout<<cnt<<endl;

    }
}