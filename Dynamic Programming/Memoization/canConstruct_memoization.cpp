#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool canConstruct(string target , vector<string> & wordbank ,unordered_map<string,bool> & memo){
if(memo.find(target)!=memo.end())return memo[target];
if(target=="") return true;
for (auto word : wordbank)
{
    if(target.find(word)==0){
        string suffix=target.substr(word.length());
    
    if(canConstruct(suffix,wordbank,memo)==true) {
        memo[target]=true;
        return memo[target];
    }
}
}
memo[target]=false;
return memo[target];
}
int main(){
    unordered_map<string,bool>memo;
     vector<string> wordBank = {"a", "p", "ent", "enter", "ot", "o", "t"};
    string target =  "enterapotentpot";
     if (canConstruct(target, wordBank, memo))
        cout << "Can construct\n";
    else
        cout << "Cannot construct\n";

    return 0;
}