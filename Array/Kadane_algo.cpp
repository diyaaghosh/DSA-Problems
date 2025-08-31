# include<bits/stdc++.h>
using namespace std;
int kadane_algo(vector<int> & arr){
    int sum=0;
    int maxi=INT_MIN;
    int start=0;
    int end=0;
    for(int i=0;i<arr.size();i++){
        if(sum==0){
         start=i;
        }
      sum+=arr[i];
      if(maxi<sum){
        end=i;
      }
      maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
    }
    if(maxi<0){maxi=0;
    return maxi;
    }
    cout<<"The subarray with maximum sum is : ";
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return maxi;
}
int main(){
    int n;
    cout<<"enter dimension : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elments of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
int ans=kadane_algo(arr);
cout<<"Maximum Subarray Sum : "<<ans;
}
