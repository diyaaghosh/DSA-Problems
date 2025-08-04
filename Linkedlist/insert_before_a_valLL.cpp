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
node*insert_at_any_poistion(node*head,int val,int ele){
    if(head==nullptr){
     cout<<"\nCant't be inserted";
     return head;
    }
    if(head->data==val){
        node*t=new node(ele);
        t->next=head;
        head=t;
        return head;
    }
   int flag=0;
    node*temp=head;
    while(temp->next!=nullptr){
     
        if(temp->next->data==val){
            node*x=new node(ele);
            x->next=temp->next;
            temp->next=x;
            flag=1;
            break;
        }
        temp=temp->next;
    }
if(flag==0){
    cout<<"\nValue is not found";
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
vector<int>arr={54,69,47,25};
node*head=array_to_ll(arr);
int val;
cout<<"Enter the value to be inserted : ";
cin>>val;
int ele;
cout<<"Enter the value before which the value will be inserted : ";
cin>>ele;
cout<<"Before inserting the head node : ";
traverse(head);
head=insert_at_any_poistion(head,ele,val);
cout<<"\nAfter inserting the head node : ";
traverse(head);

}