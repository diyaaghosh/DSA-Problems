#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<long long>*howSum(long long targetSum , const vector<long long>numbers , unordered_map<long long,vector<long long>*> & memo){
if (memo.find(targetSum)!=memo.end()){
    return memo[targetSum];
}
if (targetSum == 0) return new vector<long long>();
    if (targetSum < 0) return nullptr;
for (long long num : numbers){
    long long remainder = targetSum-num;
  vector<long long> * remainderresult=howSum(remainder,numbers,memo);
  if(remainderresult!=nullptr){
    vector<long long>* result = new vector<long long>(*remainderresult); 
            result->push_back(num);
            memo[targetSum] = result;
            return result;
  }
}
  memo[targetSum]=nullptr;
  return nullptr;

}
int main(){
  unordered_map<long long, vector<long long>*> memo;
    vector<long long> numbers = {2, 3};
    long long targetSum = 7;

    vector<long long>* result = howSum(targetSum, numbers, memo);

    if (result != nullptr) {
        for (long long num : *result) {
            cout << num << " ";
        }
        cout << endl;
        delete result;  // clean up heap allocation
    } else {
        cout << "null" << endl;
    }

}