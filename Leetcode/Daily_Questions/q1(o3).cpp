//560: Subarray sum equals to M
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the dimension of the array :";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int M;
    cout<<"Enter target sum : ";
    cin>>M;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==M){
          count++;
            }
        }

    }
    cout<<"Number of Subarrays : "<<count<<endl;

}