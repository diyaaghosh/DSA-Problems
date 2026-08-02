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
vector<int>morish_inorder_traversal(Tree*root){
    Tree*curr=root;
    vector<int>inorder;
    while(curr!=nullptr){
        // no left subtree
        if(curr->left==nullptr){
            inorder.push_back(curr->val);
            curr=curr->right;
        }
        else{
            // left subtree present then the rightmost node of the left subtree is to be find
            Tree*prev=curr->left;
            while(prev->right!=nullptr && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==nullptr){
                prev->right=curr; // set a temporary link
                curr=curr->left;
            }
            else{
                // if already the link is set then destroy it
                prev->right=nullptr;
                inorder.push_back(curr->val);
                curr=curr->right; // move right side
            }
        }
    }
    return inorder;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
   vector<int>inorder=morish_inorder_traversal(root);
   cout<<"Inorder Traversal : ";
   for(auto it:inorder){
    cout<<it<<" ";
   }
   cout<<endl;
}