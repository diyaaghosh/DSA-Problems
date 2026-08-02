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
string serialize_Binary_Tree(Tree*root){
    if(root==nullptr)return "";
    string str="";
    queue<Tree*>q;
    q.push(root);
    while(!q.empty()){
        auto it=q.front();
        Tree*node=it;
        if(node==nullptr){
            str+='#';
        }
        else{
            str+=to_string(node->val)+',';
            q.push(node->left);
            q.push(node->right);
        }
        q.pop();
    }
    cout<<str<<endl;
    return str;
}
Tree*deserialize_Binary_Tree(string data){
    if(data.size()==0)return nullptr;
    stringstream s(data);
    string str;
    getline(s,str,',');
    Tree*root=new Tree(stoi(str));
    queue<Tree*>q;
    q.push(root);
    while(!q.empty()){
        Tree*node=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#"){
            node->left=nullptr;
        }
        else{
            Tree*left_node=new Tree(stoi(str));
            node->left=left_node;
            q.push(left_node);
        }
        getline(s,str,',');
        if(str=="#"){
            node->right=nullptr;
        }
        else{
            Tree*right_node=new Tree(stoi(str));
            node->right=right_node;
            q.push(right_node); 
        }
    }
    return root;
}
int main(){
    cout << "Enter root: ";
    Tree* root = buildTree();
    serialize_Binary_Tree(root);
}