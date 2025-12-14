# include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode*next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
};
ListNode* alternate_node(ListNode*head){
ListNode*temp=head;
vector<int>st;
while(temp){
    st.push_back(temp->val);
    temp=temp->next;
}

ListNode*ans=new ListNode();
ListNode*a=ans;
for(int i=0;i<2;i++){
 
        ListNode*newnode=new ListNode(st[i]);
        ans->next=newnode;
        ans=ans->next;
    
}
for(int i=2;i<st.size();i++){
    int x=st[i]+st[i-2];
     ListNode*newnode=new ListNode(x);
        ans->next=newnode;
        ans=ans->next;
}
return a->next;
}
int main(){
ListNode*head=new ListNode();
ListNode*temp=head;
int n;
cout<<"Enter number of nodes : ";
cin>>n;
cout<<"Enter the elements of the linked list : ";
for(int i=0;i<n;i++){
    int item;
    cin>>item;
    ListNode*newnode=new ListNode(item);
    temp->next=newnode;
    temp=temp->next;
}
ListNode*t=head->next;
cout<<"The linked list is : ";
while(t!=NULL){
    cout<<t->val<<" ";
    t=t->next;
}
cout<<endl;
ListNode*alternate_linkedlist=alternate_node(head->next);
ListNode*t1=alternate_linkedlist;
cout<<"Enter the alternate LinkedList : ";
while(t1!=nullptr){
    cout<<t1->val<<" ";
    t1=t1->next;
}
}
