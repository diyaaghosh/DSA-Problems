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
int floor(Tree*root,int key){
    Tree*curr=root;
    int floor=-1;
    while(curr!=nullptr){
        if(curr->val==key){
            floor=curr->val;
            return floor;
        }
        else if(curr->val<key){
             floor=curr->val;
            curr=curr->right;
        }
        else{
           
            curr=curr->left;
        }
    }
    return floor;
    
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    int key;
    cout<<"Enter key : ";
    cin>>key;
    cout<<"floor value of BST : "<<floor(root,key);
}