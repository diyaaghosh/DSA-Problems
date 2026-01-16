#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;

        node(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    node* head;
    node* tail;
    map<int, node*> mpp;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

  
    void removeNode(node* temp) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }


    void addNode(node* temp) {
        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        node* curr = mpp[key];
        int value = curr->val;

        mpp.erase(key);
        removeNode(curr);
        addNode(curr);
        mpp[key] = curr;

        return value;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            node* curr = mpp[key];
            mpp.erase(key);
            removeNode(curr);
            delete curr;
        }

        if (mpp.size() == capacity) {
            node* lru = tail->prev;
            mpp.erase(lru->key);
            removeNode(lru);
            delete lru;
        }

        node* newNode = new node(key, value);
        addNode(newNode);
        mpp[key] = newNode;
    }
};

int main() {
    int capacity;
    cout << "Enter cache capacity: ";
    cin >> capacity;

    LRUCache cache(capacity);

    cout << "\nOperations:\n";
    cout << "1 key value  -> put(key, value)\n";
    cout << "2 key        -> get(key)\n";
    cout << "0            -> exit\n\n";

    while (true) {
        int op;
        cin >> op;

        if (op == 0) break;

        if (op == 1) {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
            cout << "Inserted (" << key << ", " << value << ")\n";
        }
        else if (op == 2) {
            int key;
            cin >> key;
            cout << "Value: " << cache.get(key) << "\n";
        }
    }

    return 0;
}
