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
void right_side_view(Tree*root,vector<int>&ds,int level){
    if(root==nullptr)return;
    if(ds.size()==level){
        ds.push_back(root->val);
    }
    right_side_view(root->right,ds,level+1);
    right_side_view(root->left,ds,level+1);
    return;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    vector<int>ds;
    int level=0;
    cout<<"Right Side View : ";
    right_side_view(root,ds,level);
    for(auto it:ds){
        cout<<it<<" ";
    }
    cout<<endl;
}