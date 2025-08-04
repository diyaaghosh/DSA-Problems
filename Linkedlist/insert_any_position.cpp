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
node*insert_at_any_poistion(node*head,int val,int k){
    if(head==nullptr){
        if(k==1){
        node*newnode=new node(val);
        head=newnode;
        return head;}
        else{
            cout<<"can't be insrted"<<endl;
        }
    }
    if(k==1){
        node*temp=new node(val);
        temp->next=head;
        head=temp;
        return head;
    }
    int cnt=0;
    node*temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k-1){
            node*x=new node(val);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
if(cnt<k)
        cout<<"\ncan't be inserted"<<endl;

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
vector<int>arr={};
node*head=array_to_ll(arr);
int val;
cout<<"Enter the value to be inserted : ";
cin>>val;
int k;
cout<<"Enter the position where the value will be inserted : ";
cin>>k;
cout<<"Before inserting the head node : ";
traverse(head);
head=insert_at_any_poistion(head,val,k);
cout<<"\nAfter inserting the head node : ";
traverse(head);

}