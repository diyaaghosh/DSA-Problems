//560: Subarray sum equals to M
#include<iostream>
using namespace std;
#include <map>
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
    int prefix_sum=0;
    map<int,int>hashmap;
    hashmap[0]=1;
    for(int i=0;i<n;i++){
        prefix_sum+=arr[i];
        int remove=prefix_sum-M;
        count+=hashmap[remove];
        hashmap[prefix_sum]+=1;}
    cout<<"Number of Subarrays : "<<count<<endl;

}
