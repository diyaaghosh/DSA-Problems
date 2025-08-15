#include<bits/stdc++.h>
using namespace std;
int convert_to_binary(int n){
    vector<int>ans;
    while(n){
        int rem=n%2;
        ans.push_back(rem);
        n=n/2;
    }
    int p=1;
    int sum=0;
  for(int i=0;i<ans.size();i++){
sum=sum+ans[i]*p;
p=p*10;
  }
  return sum;
}

bool check_power_of_two(int n){
if(n<=0)return false;    
return ((n&(n-1))==0);
}
int main(){
    int n;
    cout<<"enter the number : ";
    cin>>n;
string ans="";
if(check_power_of_two(n)==true){
    ans+="true";
}
else{
    ans+="false";
}
cout<<n<<" is power of 2 : "<<ans;
}