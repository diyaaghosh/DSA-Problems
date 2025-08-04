#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
vector<long long>*howSum(long long targetSum,vector<long long> number ){
    vector<vector<long long>*>ans(targetSum+1, nullptr);
    ans[0]=new vector<long long>;
    for(int i=0;i<=targetSum;i++){
if(ans[i]!=nullptr){
    for(auto num:number){
        if(num+i<=targetSum){
            ans[i+num]=new vector<long long>(*ans[i]);
            ans[i+num]->push_back(num);
        }
    }
}
    }
    return ans[targetSum];
}
void printResult(vector<long long>* result) {
    if (result == nullptr) {
        cout << "null" << endl;
    } else {
        cout << "[ ";
        int i=0;
        for (int num : *result) {
            if(i!=result->size()-1){
            cout << num << " , ";
            i++;
        }
        
    }
    cout << (*result)[result->size()-1] ;
        cout << "]" << endl;
    }
}
int main(){
vector<long long> nums1 = {2, 3};
    vector<long long> nums2 = {5, 3, 4, 7};
    vector<long long> nums3 = {2, 4};
    vector<long long> nums4 = {2, 3, 5};
    vector<long long> nums5 = {7, 14};

    printResult(howSum(7, nums1));   // e.g., [3, 2, 2]
    printResult(howSum(7, nums2));   // e.g., [4, 3]
    printResult(howSum(7, nums3));   // null
    printResult(howSum(8, nums4));   // e.g., [2, 2, 2, 2]
    printResult(howSum(300, nums5)); // null

    return 0;
}