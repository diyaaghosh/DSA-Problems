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
    cout << "Enter left child of " << x << " : ";
    root->left = buildTree();
    cout << "Enter right child of " << x << " : ";
    root->right = buildTree();
    return root;
}
bool is_leaf_node(Tree*node){
    if(node->left==nullptr && node->right==nullptr)return true;
    return false;
}
void children_sum(Tree*root){
    if(root==nullptr)return;
    int child=0;
    if(root->left!=nullptr)child+=root->left->val;
    if(root->right!=nullptr)child+=root->right->val;
    if(root->val>child){
        if(root->left!=nullptr){
            root->left->val=root->val;
        }
        if(root->right!=nullptr){
            root->right->val=root->val;
        }
    }
    else{
        root->val=child;
    }
    children_sum(root->left);
    children_sum(root->right);
    int tot=0;
    if(root->left!=nullptr)tot+=root->left->val;
    if(root->right!=nullptr)tot+=root->right->val;
    if(root->left!=nullptr or root->right!=nullptr){
        root->val=tot;
    }
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    children_sum(root);
}