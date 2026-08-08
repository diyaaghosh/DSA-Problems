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
Tree*insert_node(Tree*root,int val){
    Tree*node=new Tree(val);
    Tree*prev=nullptr;
    Tree*curr=root;
    while(curr!=nullptr){
        if(curr->val>node->val){
            prev=curr;
            curr=curr->left;
        }
        else if(curr->val<node->val){
            prev=curr;
            curr=curr->right;
        }
    }
    if(prev->val>node->val){
        prev->left=node;
    }
    else{
        prev->right=node;
    }
    return root;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    printTree(root);
    int val;
    cout<<"Enter value to be inserted : ";
    cin>>val;
    insert_node(root,val);
    printTree(root);

}