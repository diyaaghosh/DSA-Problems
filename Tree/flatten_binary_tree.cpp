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
    if(x == "n")  
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
void preorder_recursive(Tree*root,vector<int>&ans){
    if(root==nullptr)return;
    ans.push_back(root->val);
    preorder_recursive(root->left,ans);
    preorder_recursive(root->right,ans);
    return;
}
Tree*flatten_Binary_tree_brute_force(Tree*root){
    vector<int>preorder;
    preorder_recursive(root,preorder);
    if(root==nullptr)return nullptr;
    Tree*root1=new Tree(preorder[0]);
    Tree*curr=root1;
    int n=preorder.size();
    for(int i=1;i<n;i+=1){
        Tree*new_node=new Tree(preorder[i]);
        curr->left=nullptr;
        curr->right=new_node;
        curr=curr->right;
    }
    return root1;
}

void flatten_binary_tree_better_approach(Tree*node,Tree*&prev){
  // root->left->root (reverse of preorder)
    if(node==nullptr)return;
    flatten_binary_tree_better_approach(node->right,prev);
    flatten_binary_tree_better_approach(node->left,prev);
    node->right=prev;
    node->left=nullptr;
    prev=node;
}

Tree*Flatten_Binary_Tree_More_Better_Approach(Tree*root){
    if(root==nullptr)return nullptr;
    stack<Tree*>st;
    st.push(root);
    while(!st.empty()){
        Tree*curr=st.top();
        st.pop();
        if(curr->right!=nullptr){
            st.push(curr->right);
        }
        if(curr->left!=nullptr){
            st.push(curr->left);
        }
        if(!st.empty())
        curr->right=st.top();
        curr->left=nullptr;
    }
    return root;
}
Tree*Flatten_Binary_Tree_Optimal_Approach(Tree*root){
    Tree*curr=root;
    while(curr!=nullptr){
        if(curr->left!=nullptr){
            Tree*prev=curr->left;
            while(prev->right!=nullptr){
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=nullptr;
        }
        curr=curr->right;
    }
    return root;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    Tree*prev=nullptr;
    flatten_binary_tree_better_approach(root,prev);
}