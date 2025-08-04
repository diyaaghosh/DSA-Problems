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
node*insert_at_head(node*head,int val){
    node*temp=new node (val);
    temp->next=head;
    head=temp; // new head
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
cout<<"Enter the value to be inserted : ";
cin>>val;
cout<<"Before Deleting the head node : ";
traverse(head);
head=insert_at_head(head,val);
cout<<"\nAfter Deleting the head node : ";
traverse(head);

}