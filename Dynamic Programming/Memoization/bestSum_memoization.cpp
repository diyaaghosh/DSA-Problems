#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<long long>*bestSum(long long targetSum , const vector<long long>numbers , unordered_map<long long,vector<long long>*> & memo){
if (memo.find(targetSum)!=memo.end()){
    return memo[targetSum];
}
if (targetSum == 0) return new vector<long long>();
    if (targetSum < 0) return nullptr;
    vector<long long>*shortestcombination=nullptr;
for (long long num : numbers){
    long long remainder = targetSum-num;
  vector<long long> * remainderresult=bestSum(remainder,numbers,memo);
  if(remainderresult!=nullptr){
    vector<long long>* result = new vector<long long>(*remainderresult); 
            result->push_back(num);
           if(shortestcombination == nullptr || result->size() < shortestcombination->size()){
            shortestcombination=result;
           }
  }
}
  memo[targetSum]=shortestcombination;
  return memo[targetSum];

}
int main(){
  unordered_map<long long, vector<long long>*> memo;
    vector<long long> numbers = {1,2,5,25};
    long long targetSum = 100;

    vector<long long>* result = bestSum(targetSum, numbers, memo);

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