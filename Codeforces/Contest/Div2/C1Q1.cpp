# include<iostream>
# include<vector>
# include<algorithm>
# include<map>
# include<unordered_map>
# include<set>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  map<int,char>mpp;
  for(int i=0;i<n;i++){
    if(i%2==0){
        mpp[arr[i]]='R';
    }
    else{
        mpp[arr[i]]='B';
    }
  }
  int flag=1;
  sort(arr.begin(),arr.end());
  for(int i=1;i<n;i++){
if(mpp[arr[i]]==mpp[arr[i-1]]){
    cout<<"No"<<endl;
    flag=0;
    break;
}

  }
  if(flag==1){
    cout<<"Yes"<<endl;
  }
    }
}