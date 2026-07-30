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
vector<int> prostorder(Tree*root){
    Tree*curr=root;
    vector<int>post;
    stack<Tree*>st;
    while(curr!=nullptr || !st.empty()){
        if(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        else{
            Tree*temp=st.top()->right;
            if(temp==nullptr){
                temp=st.top();
                post.push_back(temp->val);
                st.pop();
                while(!st.empty() && st.top()->right==temp){
                temp=st.top();
                post.push_back(temp->val);
                st.pop();}
            }
            else{
                curr=temp;
            }
        }
    }
    return post;
}
void preorder_recursive(Tree*root,vector<int>&ans){
    if(root==nullptr)return;
    ans.push_back(root->val);
    preorder_recursive(root->left,ans);
    preorder_recursive(root->right,ans);
    return;
}
void inorder_recursive(Tree*root,vector<int>&ans){
    if(root==nullptr)return;
    inorder_recursive(root->left,ans);
    ans.push_back(root->val);
    inorder_recursive(root->right,ans);
    return;
}
void postorder_recursive(Tree*root,vector<int>&ans){
    if(root==nullptr)return;
    postorder_recursive(root->left,ans);
    postorder_recursive(root->right,ans);
    ans.push_back(root->val);
    return;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    // cout << "\nPostorder Traversal: ";
    // vector<int>post=prostorder(root);
    // for(int i=0;i<post.size();i++){
    //     cout<<post[i]<< " ";
    // }
    // cout<<endl;
    cout<<"Preorder Traversal : ";
    vector<int>pre;
    preorder_recursive(root,pre);
    for(auto x:pre){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Inorder Traversal : ";
    vector<int>in;
    inorder_recursive(root,in);
    for(auto x:in){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Postorder Traversal : ";
    vector<int>post;
    postorder_recursive(root,post);
    for(auto x:post){
        cout<<x<<" ";
    }
    cout<<endl;

}