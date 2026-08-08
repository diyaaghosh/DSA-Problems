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
    if (x == "null")  
        return nullptr;
        int y=stoi(x);
    Tree* root = new Tree(y);
    cout << "Enter left child of " << x << ": ";
    root->left = buildTree();
    cout << "Enter right child of " << x << ": ";
    root->right = buildTree();
    return root;
}
void printTree(Tree* root, string indent = "", bool last = true) {
    if (root == nullptr)
        return;

    cout << indent;

    if (last) {
        cout << "R----";
        indent += "     ";
    } else {
        cout << "L----";
        indent += "|    ";
    }

    cout << root->val << endl;

    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
}
// extreme left node==minimum element of the BST
int min_element(Tree*root){
    Tree*curr=root;
    while(curr->left!=nullptr){
        curr=curr->left;
    }
    return curr->val;
}
//extreme right node==maximum element of the BST
int max_element(Tree*root){
    Tree*curr=root;
    while(curr->right!=nullptr){
        curr=curr->right;
    }
    return curr->val;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    printTree(root);
    cout<<"Minimum element of the BST : "<<min_element(root)<<endl;
    cout<<"Maximum element of the BST : "<<max_element(root)<<endl;


}