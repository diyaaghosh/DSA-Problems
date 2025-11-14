# include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(vector<int>&arr,int low,int high){
int i=low;
int j=high;
int rand_index=low+rand()%(high-low+1);
swap(&arr[rand_index],&arr[low]);
int pivot=arr[low];

while(i<j){
while(i<=high-1 && arr[i]<=pivot){
    i++;
}
while(j>=low+1 && arr[j]>pivot){
    j--;
}
if(j>i){
    swap(&arr[i],&arr[j]);
}
}
swap(& arr[j],& arr[low]);

return j;
}
void quick_sort(vector<int>& arr,int low,int high){
    if(low<high){
    int p=partition(arr,low,high);
    quick_sort(arr,low,p-1);
    quick_sort(arr,p+1,high);
    }

}
int main(){
    int n;
    cout<<"Enter dimension : ";
    cin>>n;
    cout<<"Enter the elements of the array : ";
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Sorted Array : ";
    quick_sort(arr,0,n-1);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}