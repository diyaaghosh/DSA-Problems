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
node*delete_tail_DLL(node*head){
    if(head==nullptr || head->next==nullptr){
        return nullptr; // no node or 1 node
    }
    node*tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    node*prev=tail->back;
    prev->next=nullptr;
    tail->back=nullptr;
    delete tail;
    return head;
}
node*delete_head_DLL(node*head){
    if(head==nullptr || head->next==nullptr){
        return nullptr; // no node or 1 node
    }
    node*prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}
node *delete_kth_node_DLL(node*head,int k){
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
node*front=temp->next;
if(prev==nullptr && front==nullptr){ //  no node is there
    return nullptr;
}
else if(prev==nullptr){
    // head node
    head=delete_head_DLL(head);
    return head;
}
else if(front==nullptr){
    // tail node
    head=delete_tail_DLL(head);
    return head;
}
// eneral case
prev->next=front;
front->back=prev;
temp->next=nullptr;
temp->back=nullptr;
free(temp);
return head;
}
void delete_any_node(node*temp){
    node*prev=temp->back;
    node*front=temp->next;
    if(front==nullptr){
        // tail node
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    free(temp);
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
cout<<"Before Deleting the Kth node of the Linkelist : ";
print_DLL(head);
cout<<endl;
delete_any_node(head->next->next->next);
cout<<"After Deleting the Kth node of the Linkelist : ";
print_DLL(head);
}