#include "hashing.h"

DirectAddressTable::DirectAddressTable(int start, int end)
    : tbl(end - start + 1, false), offset{start} {}

void DirectAddressTable::insert(int key) {
    if (key - offset < 0 || key - offset >= tbl.size()) {
        throw std::runtime_error("DAT: insert failed, key outside bounds");
    }
            
    tbl[key - offset] = true;
}

void DirectAddressTable::remove(int key) {
    if (key - offset < 0 || key - offset >= tbl.size()) {
        throw std::runtime_error("DAT: remove failed, key outside bounds");
    }
        
    tbl[key - offset] = false;
}

bool DirectAddressTable::search(int key) {
    if (key - offset < 0 || key - offset >= tbl.size()) {
        throw std::runtime_error("DAT: search failed, key outside bounds");
    }
        
    return tbl[key - offset];
}

HashTableChaining::HashTableChaining(int _bucketSize)
    : buckets(_bucketSize, nullptr), bucketSize{_bucketSize} {}

HashTableChaining::~HashTableChaining() {
    // free up chain lists
    for (int i = 0; i < buckets.size(); i++) {
        Node *head = buckets[i];
        if (head == nullptr)
            continue;
        
        Node* next = nullptr;
        for (Node *iter = head; iter; iter = next) {
            next = iter->next;
            delete iter;
        }
    }
}

void HashTableChaining::insert(int key) {
    int index = key % bucketSize;
    Node **head = &buckets[index];
    
    if (*head == nullptr) {
        *head = new Node{key};
    } else {
        // check if the value already exists
        for (Node* iter = *head; iter; iter = iter->next) {
            if (iter->val == key) {
                return;
            }
        }
        
        Node *newNode = new Node{key};
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}

void HashTableChaining::remove(int key) {
    int index = key % bucketSize;
    
    Node **head = &buckets[index];
    
    if (*head == nullptr)
        return;
    
    Node* prev{nullptr};
    Node* curr;
    for (curr = *head; curr; curr = curr->next) {
        if (curr->val == key) {
            // if it is the head node
            if (prev == nullptr) {
                Node* oldHead = curr;
                Node* newHead = curr->next;
                *head = newHead;
                delete oldHead;
            } else {
                Node* next = curr->next;
                prev->next = next;
                delete curr;
                curr = next;
                break;
            }
        }
    }
    
    // head, prev, next, 
    
    return;
}

bool HashTableChaining::search(int key) {
    int index = key % bucketSize;
    Node *head = buckets[index];
    
    for (Node* iter = head; iter; iter = iter->next) {
        if (iter->val == key) {
            return true;
        }
    }
    
    return false;
}
