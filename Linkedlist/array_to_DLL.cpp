#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node*next;
    node*back;
    node(int data1,node*next1,node*back1){
        data=data1; // Constructor
        next=next1;
        back=back1;
    }
    node(int data1){
        data=data1; // Constructor
    }
};
node* array_to_DLL(vector<int>& arr){
    if(arr.size()==0)return nullptr;
    node*head=new node(arr[0]);
    node*prev=head;
    for(int i=1;i<arr.size();i++){
node*temp=new node(arr[i],nullptr,prev);
prev->next=temp;
prev=prev->next;
    }
    return head;
}
void print_DLL(node*head){
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
vector<int>arr={58,69,1,5};
node*head=array_to_DLL(arr);
print_DLL(head);
}