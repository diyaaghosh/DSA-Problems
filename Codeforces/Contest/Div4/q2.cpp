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
      cout<<n*maxi<<endl;
      t--;
    }
}