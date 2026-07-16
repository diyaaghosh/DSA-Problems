#include<iostream>
using namespace std;
string reverse(string ans){
     int low=0;
  int high=ans.size()-1;
  while(low<high){
 char temp= ans[low];
 ans[low]=ans[high];
 ans[high]=temp;
 low++;
 high--;
  }
  return ans;
}
string change(string a){
    string str=reverse(a);
    for(int i=0;i<str.length();i++){
        if(str[i]=='p'){
            str[i]='q';
        }
        else if(str[i]=='q'){
            str[i]='p';
        }
    }
    return str;
}
int main(){
    int t;
    string s;
    cin>>t;//no of testcases
    for(int i=0;i<t;i++){
    cin>>s;
    string ans=change(s);
    cout<<ans<<endl;    }
}