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
vector<vector<int>>vertical_traversal(Tree*root){
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<Tree*,pair<int,int>>>todo;
    todo.push({root,{0,0}});;
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        Tree*node=p.first;
        int x=p.second.first;
        int y=p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left!=nullptr){
            todo.push({node->left,{x-1,y+1}});
        }
        if(node->right!=nullptr){
            todo.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>>ans;
    for(auto p:nodes){
        vector<int>col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    cout<<"Vertical Order Travesal : ";
    vector<vector<int>>ans=vertical_traversal(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}