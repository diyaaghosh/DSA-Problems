#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s){
    int start=0;
    int end=s.size()-1;
    int flag=1;
    while(start<end){
        if(s[start]!=s[end]){
         flag=0;
         break;
        }
        start++;
        end--;
    }
    if(flag==0)return false;
    else return true;
}
void palindrome_partition(int index,string & s,vector<vector<string>>&ans, vector<string> & path,int n){
if(index==n){
    ans.push_back(path);
    return;
}
for(int i=index;i<n;i++){
    if(ispalindrome(s.substr(index,i-index+1))){
        path.push_back(s.substr(index,i-index+1));
    
    palindrome_partition(i+1,s,ans,path,n);
    path.pop_back();}
}
}
int main(){
    string str;
    cout<<"enter the string : ";
    cin>>str;
    int n=str.size();
    vector<vector<string>>ans;
    vector<string>path;
palindrome_partition(0,str,ans,path,n);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}

}