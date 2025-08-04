#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
long long countConstruct(string target ,vector<string> & wordBank,unordered_map<string,long long>& memo ){

if(memo.find(target)!=memo.end()) return memo[target];
if(target=="")return 1;
long long totalcount=0;
for (auto word : wordBank){
    if(target.find(word)==0){
          string suffix=target.substr(word.length());
          long long countrestways=countConstruct(suffix,wordBank,memo);
          totalcount+=countrestways;
    }
}
memo[target]=totalcount;
return memo[target];
}
int main(){
 unordered_map<string,long long>memo;
     vector<string> wordBank = {"purp", "p", "ur", "le", "purpl"};
    string target =  "purple";
     
        cout << countConstruct(target, wordBank, memo);
   
    return 0;
}