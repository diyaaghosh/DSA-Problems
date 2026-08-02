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
bool get_path(Tree*root,vector<int>&arr,int target){
    if(root==nullptr)return false;
    arr.push_back(root->val);
    if(root->val==target)return true;
    if(get_path(root->left,arr,target) || get_path(root->right,arr,target))return true;
    else {
        arr.pop_back();
        return false;
    }
}
Tree*Lowest_Common_Ancestor(Tree*root,int p,int q){
    if(root==nullptr|| root->val==p|| root->val==q)return root;
    Tree*left=Lowest_Common_Ancestor(root->left,p,q);
    Tree*right=Lowest_Common_Ancestor(root->right,p,q);
    if(left==nullptr)return right;
    else if(right==nullptr)return left;
    else return root;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    cout<<"Enter 1st Node : ";
    int item1;
    cin>>item1;
    vector<int>arr1;
    get_path(root,arr1,item1);
    int item2;
    cout<<"Enter 2nd Node : ";
    cin>>item2;
    vector<int>arr2;
    get_path(root,arr2,item2);
    int j=0;

    for(int i=0;i<arr1.size();i++){
        if(arr1[i]!=arr2[j]){
            break;
        }
        j++;
    }
    cout<<"Lowest Common Ancestor : "<<arr2[j-1]<<endl;
    Tree*node=Lowest_Common_Ancestor(root,item1,item2);
    cout<<"Lowest Common Ancestor : "<<node->val<<endl;
}