#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node* next;
    node(int data1) {
        data = data1;
        next =nullptr;
    }
};
node*array_to_ll(vector<int>& arr){
if (arr.empty()) return nullptr;
node*head=new node(arr[0]);
node*mover=head;
for(int i=1;i<arr.size();i++){
node*temp=new node(arr[i]);
mover->next=temp;
mover=mover->next;
}
return head;
}
node*reverse_recursively(node*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node*newhead=reverse_recursively(head->next);
    node*front=head->next;
    front->next=head;
    head->next=nullptr;
    head=newhead;
    return head;
}
node*reverse_iteratively(node*head){
    node*temp=head;
    node*prev=nullptr;
    while(temp!=nullptr){
        node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    head=prev;
    return head;
}
void traverse(node*head){
    node*temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
vector<int>arr={458,88,963,78};
node*head=array_to_ll(arr);

cout<<"Original Linkedlist : ";
traverse(head);
cout<<endl;
cout<<"Reversing the LinkedList iteratively : ";
head=reverse_iteratively(head);
traverse(head);
cout<<endl;
cout<<"Reversing the LinkedList recursively : ";
head=reverse_recursively(head);
traverse(head);

}