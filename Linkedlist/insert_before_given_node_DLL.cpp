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
int length_DLL(node*head){
    node*temp=head;
    int len=0;
    while(temp!=nullptr){
       len++;
        temp=temp->next;
    }
    return len;
}
void print_DLL(node*head){
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insert_before_given_node(node*t,int val){
    node*prev=t->back;
    node*newnode=new node (val,t,prev);
    prev->next=newnode;
t->back=newnode;
}
int main(){
vector<int>arr={54,87,589,98};
node*head=array_to_DLL(arr);
int val;
cout<<"Enter the value to be inserted at the head of the Linkelist : ";
cin>>val;
cout<<"Before Instertion of Kth node of the Linkelist : ";
print_DLL(head);
cout<<endl;
insert_before_given_node(head->next->next,val);
cout<<"After Instertion of Kth node of the Linkelist : ";
print_DLL(head);
}