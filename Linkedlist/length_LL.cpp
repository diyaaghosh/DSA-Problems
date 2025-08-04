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
int main(){
vector<int>arr={56,2,3,4};
node*head=array_to_ll(arr);
node*temp=head;
int cnt=0;
while(temp!=nullptr){
    cnt++;
    temp=temp->next;
}

   cout<<"Length of array : "<<cnt<<endl;
}