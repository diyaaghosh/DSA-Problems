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
node*delete_anynode(node*head,int val){
    if(head==nullptr) return head;
    // delete head
    if(head->data==val){
node*temp=head;
head=head->next;
free(temp);
return head;
    }
   
    node*prev=nullptr;
    node*temp=head;
    while(temp!=nullptr){
     
        if(temp->data==val){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
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
int val;
cout<<"Enter the value to be deleted : ";
cin>>val;
cout<<"Before Deleting the head node : ";
traverse(head);
head=delete_anynode(head,val);
cout<<"\nAfter Deleting the head node : ";
traverse(head);

}