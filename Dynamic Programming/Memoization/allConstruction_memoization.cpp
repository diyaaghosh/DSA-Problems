#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
vector<vector<string>> allConstruct(string target ,vector<string> & wordBank,unordered_map<string,vector<vector<string>>>& memo ){

if(memo.find(target)!=memo.end()) return memo[target];
if(target=="")return {{}};
vector<vector<string>> waysToBuild;
for (auto word : wordBank){
    if(target.find(word)==0){
          string suffix=target.substr(word.length());
          vector<vector<string>> remainingways=allConstruct(suffix,wordBank,memo);
          for(auto way:remainingways){
            way.insert(way.begin(),word);
              waysToBuild.push_back(way);
          }
    }
}
memo[target]=waysToBuild;
return memo[target];
}
int main(){
 unordered_map<string,vector<vector<string>>>memo;
     vector<string> wordBank = {"purp", "p", "ur", "le", "purpl"};
    string target =  "purple";
     
   vector<vector<string>> result = allConstruct(target, wordBank, memo);

    for (auto combination : result) {
        cout << "[ ";
        for (auto word : combination) {
            cout << word << " , ";
        }
        cout << "]" << endl;
    }

    return 0;
}