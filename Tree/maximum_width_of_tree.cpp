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
int maximum_width(Tree*root){
    if(root==nullptr)return 0;
    int maxi=0;
    queue<pair<Tree*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int first=0,last=0;
        int minIndex = q.front().second;
        for(int i=0;i<size;i++){
            auto it=q.front();
            Tree*node=it.first;
            int curr_id=it.second-minIndex;
            q.pop();
            if(i==0){
                first=curr_id;
            }
            if(i==size-1){
                last=curr_id;            }
                if(node->left!=nullptr){
                    q.push({node->left,2*curr_id+1});
                }
                if(node->right!=nullptr){
                    q.push({node->right,2*curr_id+2});
                }
                maxi=max(maxi,last-first+1);
        }
      
    }
    cout<<"Maximum Width : "<<maxi<<endl;
    return maxi;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    maximum_width(root);
}