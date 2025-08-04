#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;
vector<vector<string>>allConstruct(const string target , vector<string> & wordbank){
    vector<vector<vector<string>>>table(target.size()+1);
    table[0]={{}};
    for(int i=0;i<table.size();i++){
        for(auto word : wordbank){
            vector<vector<string>>combination;
            if(target.substr(i,word.size())==word){
                for(auto subarray : table[i]){
                    subarray.push_back(word);
                    combination.push_back(subarray);
                }
                table[i+word.size()].insert(table[i+word.size()].end(),combination.begin(),combination.end());
            }
        }
    }
    return table[table.size()-1];
}
int main(){
 string target = "purple";
    vector<string> wordBank = {"purp", "p", "ur", "le", "purpl"};
    vector<vector<string>> result = allConstruct(target, wordBank);

    for (const auto &combination : result) {
        for (const string &word : combination) {
            cout << word << " ";
        }
        cout << endl;
    }

}