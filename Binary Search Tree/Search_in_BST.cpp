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
bool Search_on_BST(Tree*root,int node){
    Tree*curr=root;
    
    while(curr!=nullptr){
        if(curr->val==node)return true;
        else if(node<curr->val){
            curr=curr->left;
        }
        else {
            curr=curr->right;
        }
    }
    return false;

}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    int node;
    cout<<"Enter node value : ";
    cin>>node;
    if(Search_on_BST(root,node)){
        cout<<node<<" is present in the BST"<<endl;
    }
    else{
         cout<<node<<" isn't present in the BST"<<endl;
    }

}