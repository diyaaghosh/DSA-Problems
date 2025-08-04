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
node*insert_head_DLL(node*head,int val){
   
node*newhead=new node (val,head,nullptr);
head->back=newhead;
head=newhead;
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
node*insert_before_tail_DLL(node*head,int val){
    if(head==nullptr){
        return new node(val);
    }
    if(head->next==nullptr ){ // 1 node
return insert_head_DLL(head,val);
    }
    node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    node*prev=temp->back;
    node*newnode=new node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;
}
node*insert_before_kth_node(node*head,int k,int val){
    if(k==1){
        return insert_head_DLL(head,val);
    }
    else if(k==length_DLL(head)){
           return insert_before_tail_DLL(head,val);
    }
    node*temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    node*prev=temp->back;
    node*newnode=new node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
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
vector<int>arr={54,87,589,98};
node*head=array_to_DLL(arr);
int k;
cout<<"Enter the position before which you want to insert the value : ";
cin>>k;
int val;
cout<<"Enter the value to be inserted at the head of the Linkelist : ";
cin>>val;
cout<<"Before Instertion of Kth node of the Linkelist : ";
print_DLL(head);
cout<<endl;
head=insert_before_kth_node(head,k,val);
cout<<"After Instertion of Kth node of the Linkelist : ";
print_DLL(head);
}