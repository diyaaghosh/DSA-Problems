# include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void max_heapify(vector<int>&arr,int i, int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        max_heapify(arr,largest,n);
    }
}
void heap_sort(vector<int>&arr,int n){
    for(int i=n/2-1;i>=0;i--){
        max_heapify(arr,i,n);
    }
    for(int i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        max_heapify(arr,0,i);
    }
}
void merge(vector<int>&arr,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
temp.push_back(arr[left]);
left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid ){
temp.push_back(arr[left]);
left++;
        }
        while(right<=high){
        temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
        }
}
void merge_sort(vector<int>&arr,int low,int high){
    if(low<high){
    int mid=low+(high-low)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
    }
    else return;
}
int partition(vector<int>&arr,int low,int high){
    int i=low;
    int j=high;
    int pivot=low;
    while(i<j){

    while(i<=high-1 && arr[pivot]>=arr[i])i++;
    while(j>=low+1 && arr[pivot]<arr[j])j++;
    }
    if(i<j){
        swap(&arr[i],&arr[j]);
    }
swap(&arr[j],&arr[pivot]);
return j;
}
void quick_sort(vector<int>&arr,int low,int high){
    if(low<high){
    int q=partition(arr,low,high);
    quick_sort(arr,low,q-1);
    quick_sort(arr,q+1,high);
    }
    else return;
}
int main(){
    int n;
    cout<<"Enter the dimension : ";
    cin>>n;

    int mini;
    cout<<"Enter the minimum range of the array : ";
    cin>>mini;
    int maxi;
    cout<<"Enter the maximum element of the array :";
    cin>>maxi;
    vector<int>arr;
    vector<int>arr1;
    cout<<"Array : ";
    for(int i=0;i<n;i++){
        int item=mini+rand()%(maxi-mini+1);
        arr.push_back(item);
        cout<<item<<" ";
    }
    cout<<endl;
    arr1=arr;
    vector<int>arr2=arr1;
    cout<<"Sorted array by using Heap sort : ";
    heap_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

       cout<<"Sorted array by using Merge sort : ";
    merge_sort(arr1,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
     cout<<"Sorted array by using Quick sort : ";
    merge_sort(arr2,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

}