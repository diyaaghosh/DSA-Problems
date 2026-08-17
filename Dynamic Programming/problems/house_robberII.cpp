# include<bits/stdc++.h>
using namespace std;
int max_nonadjacent_subarray_space_optimization(vector<int> & nums){
   int n=nums.size();
   int prev=nums[0];
   int prev2=0;
   int curi=0;
   for(int i=1;i<n;i++){
   int pick=nums[i];
   if(i>1)pick+=prev2;
   int non_pick=0+prev;
   curi=max(pick,non_pick);
   prev2=prev;
   prev=curi;
   }
   return prev;
}
int main(){
    int n;
    cout<<"enter dimension : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }       
      vector<int>temp1;
        vector<int>temp2;
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
              temp2.push_back(nums[i]);
           }
        }
        int a= max_nonadjacent_subarray_space_optimization(temp1);
        int b=  max_nonadjacent_subarray_space_optimization(temp2);
       cout<< max(a,b);
    }

