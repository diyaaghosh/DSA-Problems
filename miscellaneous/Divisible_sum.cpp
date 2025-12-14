# include<bits/stdc++.h>
using namespace std;
bool valid(vector<int>&arr,int val){
    int n=arr.size();
    int flag=1;
    for(int i=0;i<n;i++){
   if(val%arr[i]==0){ 
    flag=0;
    return false;
   }
    
    }
    if(flag==1)return true;
}
int main(){
    int n;
    cout<<"Enter dimension : ";
    cin>>n;
    vector<int>arr;
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        int item;
        cin>>item;
        arr.push_back(item);
    }
    int k;
    int sum=0;
    cout<<"Enter K : ";
    cin>>k;
    int i=k;
    int j=1;
    while(i){
    if(valid(arr,j)){
        cout<<j<<" ";
        sum+=j;
        i--;
    }
    j++;
    }
    cout<<"\nSum : "<<sum;

}
