#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int data1, node* next1) {
        data = data1;
        next = next1;
    }
};
int main(){
    node* n = new node(2, nullptr);
    cout << n->data;
}