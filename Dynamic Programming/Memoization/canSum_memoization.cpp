#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
bool canSum(long long targetSum , const vector<long long> & nums , unordered_map<long long , bool> & memo){
if(memo.find(targetSum)!=memo.end()) return memo[targetSum];
if(targetSum==0) return true;
if (targetSum < 0) return false;
for (long long num : nums){
    long long remainder= targetSum-num;
    if(canSum(remainder,nums,memo)==true){
        memo[targetSum]=true;
        return memo[targetSum];
    }
}
memo[targetSum]=false;
return memo[targetSum];
}
int main(){
unordered_map<long long , bool>memo;
 cout << boolalpha;
    cout << canSum(7, {2, 3}, memo) << endl;     // true
    memo.clear();
    vector<long long> nums2 = {5, 3, 4, 7};
    cout << canSum(7, nums2, memo) << endl;      // true
    memo.clear();
    cout << canSum(7, {2, 4}, memo) << endl;     // false
    memo.clear();
    cout << canSum(8, {2, 3, 5}, memo) << endl;  // true
    memo.clear();
    cout << canSum(300, {7, 14}, memo) << endl;  // false
}