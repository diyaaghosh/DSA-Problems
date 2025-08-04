#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<map>
#include<string>
using namespace std;
bool canConstruct(const string &target, vector<string>wordbank){
    vector<bool>table(target.size()+1,false);
    table[0]=true;
    for(int i=0;i<table.size();i++){
if(table[i]==true){
    for(auto & word:wordbank){
        if(target.substr(i,word.size())==word){
            table[i+word.size()]=true;
        }
    }
}
    }
    return table[target.size()];
}
int main() {
   
    cout << boolalpha;

    cout << canConstruct("abcde", {"ab", "abc", "cd", "def", "abcd"}) << endl; // true
    cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl; // false
    cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl; // true
    cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e"}) << endl; // false

    return 0;
}
