#include<iostream>
using namespace std;
template<class T>
class LinkedStack{
    struct Node{
        Node* next;
        T data;
        Node():next(0){}
        Node(T value, Node* p = 0):data(value),next(p){}
    };
    Node* topNode;
    public:
        LinkedStack(Node* p = 0):topNode(p){}
        ~LinkedStack();

        bool empty() const;
        T top() const;
        void push(const T&);
        void pop();
        void display() const;

        // SafeGuards
        LinkedStack& operator=(const LinkedStack& );    // Assignment Operator
        LinkedStack(const LinkedStack&);    // Copy Constructor


};

template<class T>
T LinkedStack<T>::top() const{ // O(1)
    if(empty()) throw out_of_range("Stack is Empty!");

    return topNode->data;
}

template<class T>
LinkedStack<T>::LinkedStack(const LinkedStack & rhs) {// O(n)
    Node* newNode, *rhsNode = rhs.topNode;

    if(rhsNode == 0) topNode = 0;
    else{
        // Duplicate the linked nodes
        topNode = newNode = new(nothrow) Node(rhsNode->data);
        while(rhsNode->next != 0){
            rhsNode = rhsNode->next;
            newNode->next = new(nothrow) Node(rhsNode->data);
            newNode = newNode->next;
        }
    }
}

template<class T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack &rhs) { // O(n)
    Node* newTop ,*newNode, *rhsNode =  rhs.topNode;
    if(rhsNode == 0) newTop = 0;
    else{
        // Duplicate the linked nodes
        newTop = newNode= new(nothrow) Node(rhsNode->data);
        while(rhsNode->next != 0){
            rhsNode = rhsNode->next;
            newNode->next = new(nothrow) Node(rhsNode->data);
            newNode = newNode->next;
        }
        // Clean up old stack nodes
        while(!empty()) pop();

        topNode = newTop;
    }
    return *this;
}

template<class T>
bool LinkedStack<T>::empty() const { // O(1)
    return (topNode == 0);
}

template<class T>
LinkedStack<T>::~LinkedStack() { // O(n)
    while(!empty()){
        pop();
    }
}


template<class T>
void LinkedStack<T>::pop() {
    // Underflow Error
    if(topNode == 0) throw underflow_error("the stack is empty");

    Node* p = topNode->next;
    delete topNode;
    topNode = p;
}

template<class T>
void LinkedStack<T>::display() const { // O(n)
    Node* cTop = topNode;
    while(cTop != 0){
        cout << cTop->data << ' ';
        cTop = cTop->next;
    }
    cout << '\n';
}

template<class T>
void LinkedStack<T>::push(const T &item) { // O(1)
    // creating node with the item to be the topNode
    Node* newTop = new(nothrow) Node(item, topNode);

    // Overflow error
    if(newTop == 0) throw overflow_error("No space for any element!");

    topNode = newTop;
}

int main() {
    LinkedStack<string> l;
    l.pop();

}

