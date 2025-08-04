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
node*delete_anynode(node*head,int k){
    if(head==nullptr) return head;
    // delete head
    if(k==1){
node*temp=head;
head=head->next;
free(temp);
return head;
    }
    int cnt=0;
    node*prev=nullptr;
    node*temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
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
int k;
cout<<"Enter the position where the node will be deleted : ";
cin>>k;
cout<<"Before Deleting the head node : ";
traverse(head);
head=delete_anynode(head,k);
cout<<"\nAfter Deleting the head node : ";
traverse(head);

}