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
    int cnt=0;
    if(arr[0]<=arr[1])cnt++;
    int j=0;
    while(j!=n && arr[0]==arr[j]){
  j++;
    }
    int maxi=arr[j];
  
    for(int k=j+1;k<n;k++){
        if(maxi<=arr[k]){
            maxi=arr[k];
            cnt++;
        }
    }
    cout<<cnt<<endl;
 }
}
