#include<bits/stdc++.h>
using namespace std;
int compare(string s1,string s2){
    int n1=s1.size();
    int n2=s2.size();
    if(abs(n1-n2)!=1)return 0;  
    int cnt=0;
    int i=0;
    int j=0;
    while(i<n1){
        if(j<n2 && s1[i]==s2[j]){
            i++;
            j++;
        }
        else{
            cnt++;
            i++;
        }
    }
    return (cnt==1);
}
int solve(vector<string>&nums){
    int n=nums.size();
    vector<int>dp(n,1);
    int maxi=INT_MIN;
    for(int ind=0;ind<n;ind++){
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(compare(nums[ind],nums[prev_ind])==1){
                dp[ind]=max(dp[ind],1+dp[prev_ind]);
                maxi=max(maxi,dp[ind]);
            }
        }
    }
    return maxi;
}
int main(){
    int n;
    cout<<"Enter dimension : ";
    cin>>n;
    vector<string>nums(n,"");
    cout<<"Enter the elemnets of the array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end(),
     [](string &a, string &b){
        return a.size() < b.size();
     });
  
   
   cout<<"Length of longest string chain : "<<solve(nums)<<endl;
 
}