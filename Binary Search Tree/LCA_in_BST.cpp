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
Tree*LCA(Tree*root,int val1,int val2){
    Tree*curr=root;
    while(curr!=nullptr){
    if(curr->val<val1 && curr->val<val2){
        curr=curr->right;
    }
    else if(curr->val>val1 && curr->val>val2){
        curr=curr->left;
    }
    else{
        return curr;
    }
    }
    return nullptr;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    printTree(root);
    int val1,val2;
    cout<<"Enter val 1 : ";
    cin>>val1;
    cout<<"Enter val 2 : ";
    cin>>val2;
    Tree*lca=LCA(root,val1,val2);
    cout<<"Lowest Common Ancester : "<<lca->val<<endl;

}
