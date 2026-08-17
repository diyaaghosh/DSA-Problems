#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
void print_longest_subsequence(string s1,string s2){
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
            if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int len= dp[n][m];
    string ans="";
    for(int i=0;i<len;i++){
        ans+='$';
    }
    int index=len-1;
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans[index]=s1[i-1];
            index--;
            i--;
            j--;
        }
        else{
            int val1=dp[i-1][j];
            int val2=dp[i][j-1];
            if(val1>val2){
                i--;
            }
            else {
                j--;
            }
        }
    }
   cout<<ans<<endl;
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
    cout<<"longest common subsequence : ";
    print_longest_subsequence(str1,str2);
   
}