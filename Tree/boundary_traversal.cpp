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
    cout << "Enter left child of " << x << ": ";
    root->left = buildTree();
    cout << "Enter right child of " << x << ": ";
    root->right = buildTree();
    return root;
}
bool is_leaf_node(Tree*node){
    if(node->left==nullptr && node->right==nullptr)return true;
    return false;
}
vector<int> add_left_bondary(Tree*root){
    Tree*temp=root->left;
    vector<int>ans;
    while(temp!=nullptr){
        if(!is_leaf_node(temp)){
            ans.push_back(temp->val);
        }
        if(temp->left!=nullptr)temp=temp->left;
        else temp=temp->right;
    }
    return ans;
}
vector<int>add_right_boundary(Tree*root){
    Tree*temp=root->right;
    vector<int>ans;
    while(temp!=nullptr){
        if(!is_leaf_node(temp)){
            ans.push_back(temp->val);
        }
        if(temp->right!=nullptr){
            temp=temp->right;
        }
        else temp=temp->left;
    }
    return ans;
}
void add_leaf_node(Tree*root,vector<int>&ans){
    if(is_leaf_node(root)){
        ans.push_back(root->val);
       return;
    }
    if(root->left!=nullptr)add_leaf_node(root->left,ans);
    if(root->right!=nullptr)add_leaf_node(root->right,ans);
    return;
}
vector<int>add_boundary_traversal(Tree*root){
    vector<int>ans;
    ans.push_back(root->val);
    vector<int>t1=add_left_bondary(root);
    vector<int>t3;
    add_leaf_node(root,t3);
    vector<int>t2=add_right_boundary(root);
    reverse(t2.begin(),t2.end());
    for(auto it:t1){
        ans.push_back(it);
    }
    for(auto it:t3){
        ans.push_back(it);
    }
    for(auto it:t2){
        ans.push_back(it);
    }

    return ans;
}

int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    cout<<"Boundary Travesal : ";
    vector<int>ans=add_boundary_traversal(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}