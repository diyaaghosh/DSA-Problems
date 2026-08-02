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
void count_complete_node(Tree*root,int&cnt){
    if(root==nullptr){
       
        return;
    }
     cnt++;
    count_complete_node(root->left,cnt);
    count_complete_node(root->right,cnt);
    return;
}
int height_left(Tree*root){
    int h=0;
    Tree*node=root;
    while(node!=nullptr){
        node=node->left;
        h++;
    }
    return h;
}
int height_right(Tree*root){
    int h=0;
    Tree*node=root;
    while(node!=nullptr){
        node=node->right;
        h++;
    }
    return h;
}
int count_complete_nodes(Tree*root){
    if(root==nullptr)return 0;
    int lh=height_left(root);
    int rh=height_right(root);
    if(lh==rh)return (1<<lh)-1;
    return 1+count_complete_nodes(root->left)+count_complete_nodes(root->right);
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    int cnt=0;
    count_complete_node(root,cnt);
    cout<<"Count of Complete node : "<<count_complete_nodes(root);
}