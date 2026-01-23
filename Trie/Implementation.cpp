#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct trie
{
    trie *link[26]={nullptr};

    bool flag=false;
    bool contains_key(char ch){
        return link[ch-'a']!=nullptr;
    }
    trie*get_reference_node(char ch){
        return link[ch-'a'];
    }
    void put_char(char ch,trie*node){
        link[ch-'a']=node;
    }
    void set_end(){
        flag=true;
    }
    
};
trie *root=new trie();
void insert(string s){
    int n=s.size();
     trie*node=root;
    for(int i=0;i<n;i++){
      
 if(!node->contains_key(s[i])){
  
  node->put_char(s[i],new trie());
 
 }
  node=node->get_reference_node(s[i]);
    }
    node->set_end();
}
bool search(string word){
    trie*node=root;
    int n=word.size();
    int flag=1;
    for(int i=0;i<n;i++){
        if(!node->contains_key(word[i])){
            flag=0;
            return false;
        }
        else{
            trie*reference_node=node->get_reference_node(word[i]);
 
  node=reference_node;
        }
    }
   return node->flag;
}
bool starts_with(string prefix){
    trie*node=root;
    int n=prefix.size();
    int flag=1;
    for(int i=0;i<n;i++){
        if(!node->contains_key(prefix[i])){
            flag=0;
            return false;
        }
        else{
            trie*reference_node=node->get_reference_node(prefix[i]);
 
  node=reference_node;
        }
    }
    if(flag==1){
        return true;
    }
}
int main()
{
    int n;
    cout << "Enter the dimension : ";
    cin >> n;
   cout<<"Enter the words : \n";
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    for(int i=0;i<n;i++){
        insert(words[i]);
    }
    cout<<"Enter the word to be searched : ";
    string word;
    cin>>word;
    if(search(word)){
        cout<<"Word Found"<<endl;
    }
    else{
        cout<<"Word Not Found"<<endl;
    }
    cout<<"Enter the prefix to be searched : ";
    string prefix;
    cin>>prefix;
    if(starts_with(prefix)){
        cout<<"Prefix Found"<<endl;
    }
    else{
        cout<<"Prefix Not Found"<<endl;
    }
}
