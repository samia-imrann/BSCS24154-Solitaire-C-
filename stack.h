#ifndef STACK_H
#define STACK_H

#include <iostream>
#include"DLL.h"
using namespace std;



template<class T>
class stack {
private:
    DLL<T> s;

public:
    stack() {}

    int getsize() {
        return s.getsize();
    }

    void push(T data) {
        s.insertatend(data);
    }

    bool pop(T& result) {
        if (s.getsize() == 0) {
            return false;
        }
        result = s.deleteend();
        return true;
    }

    bool top(T& result) {
        if (s.getsize() == 0) {
            return false;
        }
        result = s.tail->data;
        return true;
    }

    bool isEmpty() {
        return s.getsize() == 0;
    }

    void printStack() {
        if (s.getsize() == 0) {
            cout << "[   ]" << endl;
            cout << "( " << s.getsize() << " cards )" << endl;
        }
        else {
            T temp;
            top(temp);
            cout << temp << endl;
            cout << "( " << s.getsize() << " cards )" << endl;
        }
    }

    ~stack() {}
};

#endif
