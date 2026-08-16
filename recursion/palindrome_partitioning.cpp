# include<bits/stdc++.h>
using namespace std;
bool is_palindrome(string s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end])return false;
        start+=1;
        end-=1;
    }
    return true;
}
void solve(int index,string s,vector<string>&path,vector<vector<string>>&ans){
    int n=s.size();
    if(index==n){
        ans.push_back(path);
        return;
    }
    for(int i=index;i<n;i++){
        if(is_palindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            solve(i+1,s,path,ans);
            path.pop_back();
        }
    }
    return;
}
int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    vector<string>path;
    vector<vector<string>>ans;
    solve(0,s,path,ans);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}