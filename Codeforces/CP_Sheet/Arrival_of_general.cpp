# include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i+=1){
        cin>>arr[i];
    }
    int maxi=INT_MIN;
    int mini=INT_MAX;
    int max_ind=0,mini_ind=0;
    for(int i=0;i<n;i++){
        if(maxi<arr[i]){
            maxi=arr[i];
            max_ind=i;
        }
        if(mini>=arr[i]){
            mini=arr[i];
            mini_ind=i;
        }
    }
    int cnt=0;
   for(int i=mini_ind;i<n-1;i+=1){
    cnt++;
    swap(&arr[i],&arr[i+1]);
   }
   for(int i=n-1;i>=0;i--){
     if(maxi<=arr[i]){
            maxi=arr[i];
            max_ind=i;
        }
   }
   for(int i=max_ind;i>=1;i--){
    cnt++;
    swap(&arr[i],&arr[i-1]);
   }
   cout<<cnt<<endl;
}