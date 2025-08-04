#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<map>
#include<string>
using namespace std;
int canConstruct(const string &target, vector<string>wordbank){
    vector<int>table(target.size()+1,0);
    table[0]=1;
    for(int i=0;i<table.size();i++){
    for(auto & word:wordbank){
        if(target.substr(i,word.size())==word){
            table[i+word.size()]+=table[i];
        }
    }
}
    
    return table[target.size()];
}
int main() {
   
    

    cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd","ef"}) << endl; 
    cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl; 
    cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl; 
    cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e"}) << endl; 
    cout << canConstruct("purple", {"purp","purpl","le","p","ur"}) << endl; 

    return 0;
}