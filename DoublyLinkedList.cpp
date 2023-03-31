#include<iostream>
#include<exception>
#include<assert.h>
//#include <memory>

using namespace std;

template<class T>
class DoublyLinkedList {
private:
        struct Node {
            Node* next = 0;
            Node* prev = 0;
            T data;
            Node(const T& value = 0) :data(value) {}
        };

        Node* head;
        Node* tail;
        size_t length;

        // Helper fucntions
        Node* find(const size_t& )const;
        void checkIndex(const size_t& index)const ;
        void checkOverFlow(const Node* const)const;
        void checkUnderFlow()const;


    public:
        DoublyLinkedList() :head(0), tail(0), length(0) {}
        ~DoublyLinkedList();
        void push_front(const T&);
        void push_back(const T&);
        void pop_back();
        void pop_front();
        void removeAt(const size_t& );
        T& getAt(const size_t& );
        void display() const;
        void reverseDisplay()const;
        size_t size() const;
        T& front();
        T& back();
        const T& front()const;
        const T& back()const;

        bool exist(const T&) const;
        bool empty()const;
        void clear();

};

template<class T>
typename DoublyLinkedList<T>::Node *DoublyLinkedList<T>::find(const size_t& index) const {
    Node* targetNode = head;
    size_t ind = index;
    while(ind--){
        targetNode = targetNode->next;
    }
    return targetNode;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* tempHead = head;
    while(tempHead != 0){
        Node * next = tempHead->next;
        delete tempHead;
        tempHead = next;
    }
}

template<class T>
void DoublyLinkedList<T>::push_back(const T & value) {
    Node* newNode = new(nothrow) Node(value);

    checkOverFlow(newNode);

    if(length == 0){
        head = tail = newNode;
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

template<class T>
void DoublyLinkedList<T>::push_front(const T & value) {
    Node* newNode = new(nothrow) Node(value);

    checkOverFlow(newNode);

    if(length == 0){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    length++;
}

template<class T>
void DoublyLinkedList<T>::pop_back() {
    checkUnderFlow();

    if(length == 1){
        delete head;
        head = tail = 0;
    }else{
        Node* prev = tail->prev;
        delete tail;
        tail = prev;
        tail->next =0;
    }
    length--;
}

template<class T>
void DoublyLinkedList<T>::pop_front() {
    checkUnderFlow();

    if(length == 1){
        delete head;
        head = tail = 0;
    }else{
        Node* next = head->next;
        delete head;
        head = next;
        head->prev = 0;
    }
    length--;
}

template<class T>
void DoublyLinkedList<T>::removeAt(const size_t& index) {
    checkUnderFlow();
    checkIndex(index);

    Node* target = find(index);
    if(head == tail){
        delete head;
        head = tail = 0;
        length--;
        return ;
    }
    if(target == head) pop_front();
    else if(target == tail) pop_back();
    else{
        Node* next = target->next;
        Node* prev = target->prev;
        prev->next = next;
        next->prev = prev;
        delete target;
        length--;
    }

}

template<class T>
T &DoublyLinkedList<T>::getAt(const size_t& index) {
    checkIndex(index);
    return (find(index)->data);
}

template<class T>
void DoublyLinkedList<T>::display() const {
    Node* tempHead = head;
    while(tempHead != 0){
        cout << tempHead->data << ' ';
        tempHead = tempHead->next;
    }
    cout << '\n';
}

template<class T>
void DoublyLinkedList<T>::reverseDisplay() const {
    Node* tempTail = tail;
    while(tempTail != 0){
        cout << tempTail->data << ' ';
        tempTail = tempTail->prev;
    }
    cout << '\n';
}

template<class T>
size_t DoublyLinkedList<T>::size() const {
    return length;
}

template<class T>
T &DoublyLinkedList<T>::front() {
    checkUnderFlow();

    return (head->data);
}

template<class T>
T &DoublyLinkedList<T>::back() {
    checkUnderFlow();

    return (tail->data);
}

template<class T>
bool DoublyLinkedList<T>::exist(const T & value) const {
    Node* tempHead = head;
    while(tempHead != 0){
        if(tempHead->data == value)
            return true;

        tempHead = tempHead->next;
    }
    return false;
}

template<class T>
bool DoublyLinkedList<T>::empty() const {
    return (length == 0);
}

template<class T>
void DoublyLinkedList<T>::clear() {
    while(!empty())
        pop_back();
}

template<class T>
void DoublyLinkedList<T>::checkIndex(const size_t& index) const{
    if(index < 0 || index > length-1)
        throw out_of_range("");
    else return;
}

template<class T>
void DoublyLinkedList<T>::checkOverFlow(const Node* const p)const {
    if(p == 0)
        throw overflow_error("the list is full!");
}

template<class T>
void DoublyLinkedList<T>::checkUnderFlow()const{
    if(length == 0)
        throw underflow_error("the list is empty!");
}

int main() {
    DoublyLinkedList<int> l;

}

