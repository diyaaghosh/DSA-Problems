# include<bits/stdc++.h>
using namespace std;
struct Tree{
    int val;
    Tree*left;
    Tree*right;
    Tree(int val,Tree*left,Tree*right){
        this->val=val;
        this->left=left;
        this->right=right;
    }
    Tree(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};
Tree* buildTree() {
   string x;
    cin >> x;
    if(x == "null")  
        return nullptr;
    int y=stoi(x);
    Tree* root = new Tree(y);
    cout << "Enter left child of " << x << ": ";
    root->left = buildTree();
    cout << "Enter right child of " << x << ": ";
    root->right = buildTree();
    return root;
}
bool is_leaf_node(Tree*node){
    if(node->left==nullptr && node->right==nullptr)return true;
    return false;
}
bool get_path(Tree*root,vector<int>&arr,int target){
    if(root==nullptr)return false;
    arr.push_back(root->val);
    if(root->val==target)return true;
    if(get_path(root->left,arr,target) || get_path(root->right,arr,target))return true;
    else {
        arr.pop_back();
        return false;
    }
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    cout<<"Enter Target Node : ";
    int item;
    cin>>item;
    vector<int>arr;
    get_path(root,arr,item);
    cout<<"Path upto Destination Node : ";
    for(auto it:arr){
        cout<<it<< " ";
    }
    cout<<endl;
}
