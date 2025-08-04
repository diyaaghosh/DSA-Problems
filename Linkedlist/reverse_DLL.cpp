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
         next=nullptr;
        back=nullptr;
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
node*reverse(node*head){
    if(head==nullptr || head->next==nullptr){
        return head; // no node or 1 node (base case)
    }
    node*current=head;
    node*last=nullptr;
    while(current!=nullptr){
        last=current->back;
        current->back=current->next;
        current->next=last;
        current=current->back;
    }
    head=last->back;
    return head;
}
int main(){
vector<int>arr={45,87,89};
node*head=array_to_DLL(arr);
cout<<"Initial Linkelist : ";
print_DLL(head);
cout<<endl;
cout<<"After reversing the Linkelist : ";
head=reverse(head);
print_DLL(head);
}