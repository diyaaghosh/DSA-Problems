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
    int n;
    cin>>n;
    int arr[n];
    for(int j=0;j<n;j++){
    cin>>arr[j];
    }
  unordered_map<long long ,long long>mpp;
  for(int j=0;j<n;j++){
    mpp[arr[j]]++;
  }
  if(mpp.size()>2) {cout<<"No"<<endl;continue;}
 else if(mpp.size()==1){
    cout<<"Yes"<<endl;continue;
  }
  auto it=mpp.begin();

long long f1=it->second;
it++;
long long f2=it->second;
if(f1==f2){
       cout<<"Yes"<<endl;continue;
}
else if(n%2!=0 && abs(f1-f2)==1){
       cout<<"Yes"<<endl;continue;
}
else{
       cout<<"No"<<endl;continue;
}
 
 }
}

