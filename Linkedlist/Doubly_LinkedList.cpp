# include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node*next;
    Node*back;
    Node(int val,Node*next,Node*back){
        this->val=val;
        this->next=next;
        this->back=back;
    }
    Node(int val){
        this->val=val;
        this->next=nullptr;
        this->back=nullptr;
    }
};
Node* array_to_DLL(vector<int>&arr){
    int n=arr.size();
    Node*head=new Node(arr[0]);
    Node*temp=head;
    for(int i=1;i<n;i+=1){
        Node*newnode=new Node(arr[i],nullptr,temp);
        temp->next=newnode;
        temp=temp->next;
    }
    return head;
}
void print_DLL(Node*head){
    Node*temp=head;
    cout<<"Doubly LinkedList : ";
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node*deletion_at_head(Node*head){
    Node*temp=head;
    if(head==nullptr || head->next==nullptr)return nullptr;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    free(temp);
    return head;
}
Node*deletion_at_tail(Node*head){
    Node*temp=head;
    if(head==nullptr || head->next==nullptr)return nullptr;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node*prev=temp->back;
    prev->next=nullptr;
    temp->back=nullptr;
    free(temp);
    return head;
}
Node*delete_Kth_node(Node*head,int k){
    if(head==nullptr)return nullptr;
    if(head->next==nullptr){
        if(k==1)return nullptr;
        else return head;
    }
    Node*temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k)break;
        temp=temp->next;
    }
    Node*prev=temp->back;
    Node*next_node=temp->next;
    if(prev==nullptr)return deletion_at_head(head);
    if(next_node==nullptr)return deletion_at_tail(head);
    prev->next=next_node;
    next_node->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    free(temp);
    return head;

}
Node*delete_particular_node(Node*head,Node*del){
    if(head==nullptr)return nullptr;
    if(head->next==nullptr){
        if(head->val==del->val)return nullptr;
        else return head;
    }
    Node*temp=head;
    while(temp!=nullptr){
        if(temp->val==del->val){
            break;
        }
        temp=temp->next;
    }
    if(temp!=nullptr){
        
        Node*front=temp->next;
        Node*prev=temp->back;
        if(front==nullptr){
            return deletion_at_tail(head);
        }
        if(prev==nullptr){
            return deletion_at_head(head);
        }
        front->back=prev;
        prev->next=front;
        temp->next=nullptr;
        temp->back=nullptr;
        free(temp);
    }
    return head;
}
Node*insertion_before_head(Node*head,int value){
    if(head==nullptr){
        Node*t=new Node(value);
        head=t;
        return head;
    }
    Node*temp=head;
    Node*new_head=new Node(value,temp,nullptr);
    temp->back=new_head;
    head=new_head;
    return head;
}
Node*insertion_after_head(Node*head,int value){
     if(head==nullptr){
        Node*t=new Node(value);
        head=t;
        return head;
    }
    Node*temp=head;
    Node*new_node=new Node(value,nullptr,temp);
    Node*front=temp->next;
    new_node->next=front;
    temp->next=new_node;
    front->back=new_node;
    return head;
}
Node*insertion_before_tail(Node*head,int value){
    if(head==nullptr){
        return new Node(value);
    }
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node*prev=temp->back;
    Node*new_node=new Node(value,temp,prev);
    prev->next=new_node;
    temp->back=new_node;
    return head;
}
Node*insertion_after_tail(Node*head,int value){
    if(head==nullptr){
        return new Node(value);
    }
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }  
    
    Node*new_tail=new Node(value,nullptr,temp);
    temp->next=new_tail;
    return head;
}
Node*insertion_before_Kth_node(Node*head,int k,int value){
    if(head==nullptr)return nullptr;
    if(head->next==nullptr){
        if(k==1){
            return insertion_before_head(head,value);
        }
        else{
            return head;
        }
    }
    Node*temp=head;
    int cnt=0;
    while(temp->next!=nullptr){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    if(temp->next!=nullptr){
        Node*prev=temp->back;
        Node*new_node=new Node(value,temp,prev);
        prev->next=new_node;
        temp->back=new_node;
        return head;
    }
    return head;
}
Node*insertion_after_kth_node(Node*head,int k,int value){
    if(head==nullptr)return nullptr;
    if(head->next==nullptr){
        if(k==1){
            return insertion_after_tail(head,value);
        }
        else return head;
    }
    Node*temp=head;
    int cnt=0;
    int flag=0;
    while(temp->next!=nullptr){
        cnt++;
        if(cnt==k){
            flag=1;
            break;
        }
        temp=temp->next;
    }
        if(temp->next!=nullptr){
            Node*front=temp->next;
            Node*new_node=new Node(value,front,temp);
            front->back=new_node;
            temp->next=new_node;
        }
        else{
            if(flag==1){
                return insertion_after_tail(head,value);
            }
            else return head;
        }
    
    return head;
}
Node*insertion_before_given_node(Node*head,int value,int node){
    if(head==nullptr)return nullptr;
      if(head->val==node){
            return insertion_before_head(head,value);
        }
    Node*temp=head;
    int flag=0;
    while(temp->next!=nullptr){
        if(temp->val==node){
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0 && temp->val==node){
        return insertion_before_tail(head,value);
    }
    if(flag==1){
    Node*prev=temp->back;
    Node*new_node=new Node(value,temp,prev);
    prev->next=new_node;
    temp->back=new_node;}
    return head;
}
Node*insertion_after_given_node(Node*head,int value,int node){
    if(head==nullptr)return nullptr;
     if(head->val==node){
            return insertion_after_head(head,value);
        }
    Node*temp=head;
    int flag=0;
    while(temp->next!=nullptr){
        if(temp->val==node){
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0 && temp->val==node){
        return insertion_after_tail(head,value);
    }
    if(flag==1){
        if(temp->next!=nullptr){
            Node*front=temp->next;
            Node*new_node=new Node(value,front,temp);
            temp->next=new_node;
            front->back=new_node;
        }
        else{
            return insertion_after_tail(head,value);
        }
    }
    return head;
}
Node* reverse_DLL(Node*head){
    Node*curr=head;
    Node*last=nullptr;
    while(curr!=nullptr){
        last=curr->back;
        curr->back=curr->next;
        curr->next=last;
        curr=curr->back;
    }
    head=last->back;
    return head;
}
Node*middle_node(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
bool detect_cycle(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
       
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)return true;
    }
    return false;
}
Node*starting_node_of_loop(Node*head){
        Node*slow=head;
        Node*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
          slow=slow->next;
          fast=fast->next->next;
          if(fast==slow){
            slow=head;
            while(slow!=fast){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
          }
        }
        return nullptr;
}
int length_of_loop(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            int cnt=0;
            fast=fast->next;
            while(slow!=fast){
                fast=fast->next;
                cnt++;
            }
            cout<<"Length of the loop of the LinkedList : "<<cnt<<endl;
            return cnt;
        }
    }
    cout<<"No loop is present"<<endl;
    return 0;
}
int length_of_loop_brute_force(Node*head){
    map<Node*,int>mpp;
    int timer=0;
    Node*temp=head;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            cout<<"Length of the loop of the LinkedList : "<<(timer+1)-mpp[temp]<<endl;
           
            return (timer+1)-mpp[temp];
        }
        timer++;
        mpp[temp]=timer;
        temp=temp->next;
    }
    cout<<"No loop present"<<endl;
    return 0;  
}
bool is_palindrome_brute_force(Node*head){
    Node*temp=head;
    stack<int>st;
    while(temp!=nullptr){
        st.push(temp->val);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(temp->val!=st.top())return false;
        temp=temp->next;
        st.pop();
    }
    return true;
}
bool palindrome_optimized(Node*head){
    Node*first=head;
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node*new_head=reverse_DLL(slow->next);
    Node*second=new_head;
    while(second!=nullptr){
        if(second->val !=first->val){
            slow->next=reverse_DLL(new_head);
            return false;
        }
        second=second->next;
        first=first->next;
    }
    slow->next=reverse_DLL(new_head);
    return true;
}
int main(){
    int n;
    cout<<"Enter dimension of LinkedList : ";
    cin>>n;
    vector<int>arr(n,0);
    cout<<"Enter the elements of the arary : ";
    for(int i=0;i<n;i+=1){
        cin>>arr[i];
    }
    Node*head=array_to_DLL(arr);
    print_DLL(head);
    Node*m_node=middle_node(head);
    cout<<"Middle Node : "<<m_node->val<<endl;
    if(detect_cycle(head)){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is absent"<<endl;
    }
    cout<<"Enter 1 : Delete at Head\nEnter 2 : Delete at Tail\nEnter 3 :  Delete K-th Node\nEneter 4 : Delete Particular Node\n";
    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    if(choice==1){
        head=deletion_at_head(head);
        
    }
    else if(choice==2){
        head=deletion_at_tail(head);
      
    }
    else if(choice==3){
        int k;
        cout<<"Enter k : ";
        cin>>k;
        head=delete_Kth_node(head,k);
    }
    else if(choice==4){
        int value;
        cout<<"Enter val : ";
        cin>>value;
        Node*del=new Node(value);
        head=delete_particular_node(head,del);
    }
    else{
        cout<<"Invalid Choice\n";
    }
    print_DLL(head);
    cout<<"Enter 1 : Insert before Head of the LinkedList\nEnter 2 : Insert after Head of the LinkedList\nEnter 3 : Insert before Tail of LinkedList\nEnter 4 : Insert after Tail of LinkedList\nEnter 5 :  Insert before K-th Node of the LinkedList\nEnter 6 : Insert after K-th Node of the LinkedList\nEnter 7 : Insert before given Node of LinkedList\nEnter 8 : Insert after given Node of the Linkedlist\n";
    choice=0;
    int value;
    cout<<"Enter value to be inserted : ";
    cin>>value;
    cout<<"Enter choice : ";
    cin>>choice;
    if(choice==1){
        head=insertion_before_head(head,value);
    }
    else if(choice==2){
        head=insertion_after_head(head,value);
    }
    else if(choice==3){
        head=insertion_before_tail(head,value);
    }
    else if(choice==4){
        head=insertion_after_tail(head,value);
    }
    else if(choice==5){
        int k;
        cout<<"Enter k : ";
        cin>>k;
        head=insertion_before_Kth_node(head,k,value);
    }
    else if(choice==6){
        int k;
        cout<<"Enter k : ";
        cin>>k;
        head=insertion_after_kth_node(head,k,value);        
    }
    if(choice==7){
        int node;
        cout<<"Enter given node value : ";
        cin>>node;
        head=insertion_before_given_node(head,value,node);
    }
    else if(choice==8){
        int node;
        cout<<"Enter given node value : ";
        cin>>node;
        head=insertion_after_given_node(head,value,node);
    }
    else{
        cout<<"Invalid Choice\n";
    }
    print_DLL(head);
    cout<<"Reversing LinkedList\n";
    head=reverse_DLL(head);
    print_DLL(head);}