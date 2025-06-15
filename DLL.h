#ifndef ITERATOR_H
#define ITERATOR_H

#include<iostream>
using namespace std;


template<typename T>
class DLL {
public:
    class node {
    public:
        T data;         //obj to store cards
        node* next;
        node* prev;
        node(T c) : data(c), next(nullptr), prev(nullptr) {}
    };
    node* head;
    node* tail;
    int size;

    DLL() : head(nullptr), tail(nullptr), size(0) {}

    class iterator {
        friend class DLL;
        iterator(node* p) : curr(p) {}
        node* curr;
    public:
        iterator() : curr(nullptr) {}
        node* getcurr() {
            return curr;
        }
        T& operator*() {
            return curr->data;
        }
        iterator& operator=(const iterator& rhs) {
            if (this != &rhs) {  // Check for self-assignment
                this->curr = rhs.curr;
            }
            return *this;
        }
        iterator& operator++() {   // pre-increment
            curr = curr->next;
            return *this;
        }
        iterator operator++(int) {    // post-increment
            iterator old = *this;
            curr = curr->next;
            return old;
        }
        iterator& operator--() {   // pre-decrement
            curr = curr->prev;
            return *this;
        }
        iterator operator--(int) {   // post-decrement
            iterator old = *this;
            curr = curr->prev;
            return old;
        }
        bool operator==(iterator rhs) const {
            return curr == rhs.curr;
        }
        bool operator!=(iterator rhs) const {
            return curr != rhs.curr;
        }
    };
    iterator begin() {
        return iterator(head);
    }
    iterator end() {
        return iterator(tail);
    }
    void insertatstart(card c) {
        node* t = new node(c);
        if (head == nullptr) {  // List is empty
            head = tail = t;
        }
        else {
            t->next = head;
            head->prev = t;
            head = t;
        }
        size++;
    }
    void insertatend(T c) {
        node* t = new node(c);
        if (head == nullptr) {  // List is empty
            head = tail = t;
        }
        else {
            t->prev = tail;
            tail->next = t;
            tail = t;
        }
        size++;
    }
    int getsize() {
        return size;
    }
    void deletestart() {
        if (head == nullptr) {
            cout << "emptyyyyyy";
            return;
        }  // List is empty

        node* t = head;
        if (head == tail) {  // Only one element in the list
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        size--;
        delete t;
    }
    T deleteend() {                                  //this function removes a card from column end and returns it so can e added to other column
        if (head == nullptr)
            cout << "empty";
        T removed = tail->data;  // Store the card to return later

        if (head == tail) {  // Only one node in the list
            delete tail;
            head = tail = nullptr;
        }
        else {
            node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        size--;
        return removed;  // Return the card that was removed
    }
    T gettail() {
        return tail->data;
    }
    T gethead() {
        return head->data;
    }
    void printlinkedlist() {
        node* t = head;
        cout << size << " cards" << endl;
        while (t != nullptr) {
            cout << t->data << endl;
            t = t->next;
        }
    }
    bool isEmpty() {
        return size == 0;
    }
    void erase(iterator& it) {
        if (it.curr == nullptr) return;  // Iterator is null, nothing to erase
        node* toDelete = it.curr;
        if (toDelete == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;  // If the list becomes empty
        }
        else if (toDelete == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;  // If the list becomes empty
        }
        else {
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
        }
        if (toDelete == tail) {
            it.curr = nullptr;
        }
        else {
            it.curr = toDelete->next;
        }
        delete toDelete;
        size--;
    }
    ~DLL() {
        while (head != nullptr) {
            deletestart();
        }
    }
};

#endif //ITERATOR_H
