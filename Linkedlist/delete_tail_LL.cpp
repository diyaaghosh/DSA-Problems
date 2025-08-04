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
node*head=new node(arr[0]);
node*mover=head;
for(int i=1;i<arr.size();i++){
node*temp=new node(arr[i]);
mover->next=temp;
mover=mover->next;
}
return head;
}
node*delete_tail(node*head){
    if(head==nullptr|| head->next==nullptr) return nullptr;
    node*temp=head;
   while(temp->next->next!=nullptr){
    temp=temp->next;
   }
   free(temp->next);
   temp->next=nullptr;
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
vector<int>arr={56,2,3,4};
node*head=array_to_ll(arr);
cout<<"Before Deleting the head node : ";
traverse(head);
head=delete_tail(head);
cout<<"\nAfter Deleting the head node : ";
traverse(head);

}