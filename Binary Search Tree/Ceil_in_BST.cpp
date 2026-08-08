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
int ceil(Tree*root,int key){
    Tree*curr=root;
    int ceil=-1;
    while(curr!=nullptr){
        if(curr->val==key){
            ceil=curr->val;
            return ceil;
        }
        else if(curr->val<key){
            curr=curr->right;
        }
        else{
            ceil=curr->val;
            curr=curr->left;
        }
    }
    return ceil;
    
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    int key;
    cout<<"Enter key : ";
    cin>>key;
    cout<<"ceil value of BST : "<<ceil(root,key);
}