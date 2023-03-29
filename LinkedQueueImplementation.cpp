#include <iostream>
#include <queue>
#include <exception>
using namespace std;
template<typename T>

// front->Node->Node->Node->back
class LinkedQueue{
    struct Node{
        Node* next;
        T data;
        Node():next(0){}
        Node(T value, Node* p = 0):data(value),next(p){}
    };

    Node* backNode;
    Node* frontNode;
    size_t Size = 0;

    public:
        LinkedQueue(): backNode(0), frontNode(0){}
        ~LinkedQueue();

        void pop();
        void push(const T&);
        T& back();
        T& front();
        size_t size() const;
        void display() const;
        bool empty() const;

        // SafeGuards
        LinkedQueue(const LinkedQueue&);  // Copy Constructor
        LinkedQueue& operator=(const LinkedQueue&); // Assignment Operator

};

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    while(!empty())
        pop();
}

template<typename T>
void LinkedQueue<T>::pop() {
    if(frontNode == 0)
        throw underflow_error("the queue is empty!");

    Node* oldFront = frontNode;
    frontNode = oldFront->next;

    if(frontNode == 0) backNode = 0;
    delete oldFront;
    oldFront = 0;
    Size--;
}

template<typename T>
void LinkedQueue<T>::push(const T& value) {
    Node* newNode = new(nothrow) Node(value);
    if(newNode == 0)
        throw overflow_error("the queue is full!");

    if (frontNode == backNode && frontNode == 0){
        frontNode = backNode = newNode;
    }
    else{
        backNode->next = newNode;
        backNode = newNode;
    }
    Size++;
}
template<typename T>
T &LinkedQueue<T>::back() {
    return (backNode->data);
}

template<typename T>
T &LinkedQueue<T>::front() {
    return (frontNode->data);
}


template<typename T>
size_t LinkedQueue<T>::size() const {
    return Size;
}
template<typename T>
void LinkedQueue<T>::display()const {
    Node* Cfront = frontNode;

    while(Cfront != 0){
        cout << Cfront->data << ' ';
        Cfront = Cfront->next;
    }
    cout << '\n';
}

template<typename T>
bool LinkedQueue<T>::empty() const {
    return (frontNode == 0);
}

template<typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue &rhs) {
    frontNode = backNode = 0;

    Node* temp = rhs.frontNode;
    while(temp != 0){
        this->push(temp->data);
        temp = temp->next;
    }

}

template<typename T>
LinkedQueue<T> &LinkedQueue<T>::operator=(const LinkedQueue & rhs) {
    while(!empty()){
        pop();
    }

    Node* temp = rhs.frontNode;
    while(temp != 0){
        this->push(temp->data);
        temp = temp->next;
    }

    Size = rhs.size();
    return *this;
}



int main() {
    LinkedQueue<int> v, l;

}
