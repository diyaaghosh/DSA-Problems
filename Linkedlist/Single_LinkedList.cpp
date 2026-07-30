#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
void print_linkedlist(Node *head)
{
    Node *temp = head;
    cout << "LinkedlIst : ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *implementation()
{
    int n;
    cout << "Enter dimension of LinkedList : ";
    cin >> n;
    cout << "Enter the elements  : ";
    int first_ele;
    cin >> first_ele;
    Node *head = new Node(first_ele);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        int new_node_val;
        cin >> new_node_val;
        Node *new_node = new Node(new_node_val);
        temp->next = new_node;
        temp = temp->next;
    }
    print_linkedlist(head);
    return head;
}
bool is_present(Node *head, int ele)
{

    Node *temp = head;
    int flag = 1;
    while (temp != nullptr)
    {
        if (temp->data == ele)
        {
            cout << ele << " is present in the Linkedlist" << endl;
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        cout << ele << " is not present in the Linkedlist" << endl;
        return false;
    }
    return true;
}
int len(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    cout << "Length of the LinkedList : " << cnt << endl;
    return cnt;
}
Node *deletion(Node *head)
{
    cout << "Enter 1 : Delete Head of the LinkedList\nEnter 2 : Delete Tail of the LinkedList\nEnter 3 : Delete Kth Element of the LinkedList\nEnter 4 : Delete a particular value from LinkedList\n";
    int choice;
    cout << "Enter your choice : ";
    cin >> choice;
    if (choice == 1)
    {
        Node *temp = head;
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        head = temp->next;
        free(temp);
        return head;
    }
    else if (choice == 2)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        free(temp->next);
        return head;
    }
    else if (choice == 3)
    {
        int k;
        cout << "Enter k : ";
        cin >> k;
        if (head == nullptr)
            return nullptr;
        else if (k == 1)
        {
            // delete head
            Node *temp = head;
            if (head == nullptr || head->next == nullptr)
                return nullptr;

            head = temp->next;
            free(temp);
        }
        else
        {
            Node *temp = head;
            int cnt = 0;
            Node *prev = temp;
            while (temp != nullptr)
            {
                cnt++;
                if (cnt == k)
                {
                    prev->next = temp->next;
                    free(temp);
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
    else if (choice == 4)
    {
        int ele;
        cout << "Enter element to be deleted : ";
        cin >> ele;
        if (is_present(head, ele))
        {
            Node *temp = head;
            if (temp->data == ele)
            {
                Node *temp = head;
                head = temp->next;
                free(temp);
            }
            Node *prev = nullptr;
            while (temp != nullptr)
            {
                if (temp->data == ele)
                {
                    prev->next = temp->next;
                    free(temp);
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
    else
    {
        cout << "Invalid Option" << endl;
    }

    return head;
}
Node *insertion(Node *head)
{
    cout << "Enter 1 : Insert at Head of the linkedList\nEnter 2 : Insert at Tail\nEnter 3 : Insert at K-th position\nEnter 4 : Insert before a particular value \n";
    int choice;
    cout << "Enter your choice : ";
    cin >> choice;
    int ele;
    cout << "Enter element to be inserted : ";
    cin >> ele;
    Node *temp = head;
    Node *newnode = new Node(ele);
    if (choice == 1)
    {
        newnode->next = temp;
        head = newnode;
    }
    else if (choice == 2)
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    else if (choice == 3)
    {
        int k;
        cout << "Enter k : ";
        cin >> k;
        if (head == nullptr)
        {
            if (k == 1)
            {
                head = newnode;
            }
        }
        else if (k == 1)
        {
            newnode->next = temp;
            head = newnode;
        }
        else
        {
            int cnt = 0;
            while (temp != nullptr)
            {
                cnt += 1;
                if (cnt == k - 1)
                {
                    newnode->next = temp->next;
                    temp->next = newnode;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    else if (choice == 4)
    {
        int element;
        cout << "Enter the element after which insertion will be done : ";
        cin >> element;
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->data == element)
        {
            newnode->next = temp;
            head = newnode;
        }
        Node *prev = nullptr;
        while (temp != nullptr)
        {
            if (temp->data == element)
            {
                prev->next = newnode;
                newnode->next = temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    else
    {
        cout << "Invalid Choice" << endl;
    }
    return head;
}
Node*middle_node(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle Node : "<<slow->data<<endl;
    return slow;
}
Node*reverse_LL(Node*head){
    Node*temp=head;
    Node*prev=nullptr;
    while(temp!=nullptr){
        Node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    head=prev;
    return head;
}
Node*reverse_LL_recursively(Node*head){
    if(head==nullptr || head->next==nullptr)return head;
    Node*new_head=reverse_LL_recursively(head->next);
    Node*front=head->next;
    front->next=head;
    head->next=nullptr;
    head=new_head;
    return head;
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
            cout<<"Starting node value of the loop of the LinkedList : "<<slow->data<<endl;
            return slow;
          }
        }
        cout<<"No loop is present"<<endl;
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
bool is_palindrome_brute_force(Node*head){
    Node*temp=head;
    stack<int>st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(temp->data!=st.top())return false;
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
    Node*new_head=reverse_LL(slow->next);
    Node*second=new_head;
    while(second!=nullptr){
        if(second->data !=first->data){
            slow->next=reverse_LL(new_head);
            return false;
        }
        second=second->next;
        first=first->next;
    }
    slow->next=reverse_LL(new_head);
    return true;
}
int main()
{
    Node *head = implementation();
    int ele;
    cout << "Enter element to be searched : ";
    cin >> ele;
    is_present(head, ele);
    len(head);
    head=reverse_LL_recursively(head);
    cout<<"Reversing LL : ";
    print_linkedlist(head);
    if(palindrome_optimized(head)){
        cout<<"This LinkedList is a palindrome"<<endl;
    }
    else{
        cout<<"This LinkedList is not a palindrome"<<endl;
    }
    middle_node(head);
    head = deletion(head);
    print_linkedlist(head);
    head = insertion(head);
    print_linkedlist(head);
}