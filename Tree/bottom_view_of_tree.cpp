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
void bottom_view(Tree*root){
    queue<pair<Tree*,int>>q;
    map<int,int>mpp;
    vector<int>ind;
    if(root==nullptr)return;
    q.push({root,0});
   
    while(!q.empty()){
        auto it=q.front();q.pop();
        Tree*node=it.first;
        int pos=it.second;
       
            mpp[pos]=node->val;
        
        if(node->left!=nullptr){
            q.push({node->left,pos-1});
        }
        if(node->right!=nullptr){
            q.push({node->right,pos+1});
        }
    }
    for(auto [a,b]:mpp){
        ind.push_back(a);
    }
    sort(ind.begin(),ind.end());
    for(int i=0;i<ind.size();i+=1){
        cout<<mpp[ind[i]]<<" ";
    }

}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    cout<<"Bottom View of Tree : ";
    bottom_view(root);
}