#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

int longest_common_substring(string s1,string s2){
    int ans=0;
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}
int longest_common_substring_by_space_optimization(string s1,string s2){
    int ans=0;
    int n=s1.size();
    int m=s2.size();
    
    vector<int>prev(m+1,0);
    vector<int>curr(m+1,0);
    
    for(int j=0;j<=m;j++){
        prev[j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){curr[j]=prev[j-1]+1;
                ans=max(ans,curr[j]);
            }
            else{
                curr[j]=0;
            }
        }
        prev=curr;
    }
    return ans;
}
int main(){
    int n,m;
    cout<<"Enter dimension of string 1 : ";
    cin>>n;
    string str1,str2;
    cout<<"Enter the string 1 : ";
    cin>>str1;
    cout<<"Enter the dimension of string 2 : ";
    cin>>m;
    cout<<"Enter the string 2 : ";
    cin>>str2;
    cout<<"Longest commong substring length : "<<longest_common_substring(str1,str2)<<endl;
    cout<<"Longest commong substring length : "<<longest_common_substring_by_space_optimization(str1,str2)<<endl;
}