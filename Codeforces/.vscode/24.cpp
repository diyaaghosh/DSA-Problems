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
    int n,k;
    cin>>n;
    cin>>k;
    int arr[n];
   for(int j=0;j<n;j++){
    cin>>arr[j];
   }
   int flag=0;
   for(int j=0;j<n;j++){
    if(arr[j]==k) {
        cout<<"YES"<<endl;
         flag=1;
        break;
    }
   }
   if(flag==0){
    cout<<"NO"<<endl;
   }
 }
}
