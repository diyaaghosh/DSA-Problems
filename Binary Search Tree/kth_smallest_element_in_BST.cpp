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
    if (root == nullptr )
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
void inorder(Tree*root,int&cnt ,int k,int &ans){
    if(root==nullptr  || cnt>=k)return;
    inorder(root->left,cnt,k,ans);
    cnt++;
    if(cnt==k){
        ans=root->val;
        return;
    }
    inorder(root->right,cnt,k,ans);
    return;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    printTree(root);
    int k;
    cout<<"Enter k : ";
    cin>>k;
    int cnt=0;
    int ans=0;
    inorder(root,cnt,k,ans);
    cout<<"K th smallest element of the BST : "<<ans;

  
}