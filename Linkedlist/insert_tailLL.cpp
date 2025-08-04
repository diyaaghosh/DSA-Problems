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
node*insert_at_tail(node*head,int val){
    if(head==nullptr){
        node*newnode=new node(val);
        head=newnode;
        return head;
    }
    node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    node*t1=new node(val);
    temp->next=t1;
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
head=insert_at_tail(head,val);
cout<<"\nAfter Deleting the head node : ";
traverse(head);

}