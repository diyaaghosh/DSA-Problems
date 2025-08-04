    #include <iostream>
    #include <vector>
    using namespace std;
   
   int countSubsequenceWithTargetSum(int i,vector<int>&ds,int sum,vector<int>& nums, int k,int n){
    if(sum>k)return 0;// if the array contains only positive values
    // T.C = O(2^n)
    	if(i==n){
            if(sum==k){
    return 1;
            }
     return 0;
        }
        ds.push_back(nums[i]); // pick
        sum+=nums[i];
        int left=countSubsequenceWithTargetSum(i+1,ds,sum,nums,k,n);
        ds.pop_back(); // not pick
        sum-=nums[i];
        int right= countSubsequenceWithTargetSum(i+1,ds,sum,nums,k,n);
        return left+right;
    }
    int main(){
        int n;
        cout<<"Enter the dimension : ";
        cin>>n;
        vector<int>nums(n);
        cout<<"Enter the elements of the array : ";
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int target;
        cout<<"Enter the target : ";
        cin>>target;
        vector<int>ds;
       int l=countSubsequenceWithTargetSum(0,ds,0,nums,target,n);
       cout<<"Number of Subsequences with k sum : "<<l<<endl;
    }
