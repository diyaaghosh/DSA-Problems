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
    while(t){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
       int mex=0;
       vector<int>hash(maxi+2,-1);
       for(int i=0;i<n;i++){
        hash[arr[i]]++;
       }
       for(auto it:hash){
        if(it==-1)mex++;
       }
       int flag=0;
      for(int i=0;i<mex;i++){
        if(hash[i]==1){
            cout<<"Yes"<<endl;
            flag=1;
           break;
        }
      }
      if(flag==0 && mex==1){
        cout<<"No"<<endl;
       
      }
      else{
        if(flag==0)
        cout<<"Yes"<<endl;
       
      }
        t--;
    }
}