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
        void checkIndex(const size_t& index)const ;
        void checkOverFlow(const Node* const)const;
        void checkUnderFlow()const;


    public:
        DoublyLinkedList() :head(0), tail(0), length(0) {}
        ~DoublyLinkedList();

        Node* find(const size_t& index)const;    // given an index, returns Node pointer
        void insertAtHead(const T&);
        void insertAtTail(const T&);
        void insertAt(const T&, size_t);
        void insertAfter(Node* , const T&);
        void removeAtHead();
        void removeAtTail();
        void removeAt(const size_t& );
        T& retrieveAt(const size_t& );
        void replaceAt(const T&, const size_t&);
        void forwardTraversal() const;
        void backwardTraversal()const;
        void swap(const size_t& , const size_t& );
        size_t size() const;
        T& front();
        T& back();

        void reverse();
        bool isExist(const T&) const;
        bool isItemAtEqual(const T&, const size_t& ) const;
        bool isEmpty()const;
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
void DoublyLinkedList<T>::insertAtTail(const T & value) {
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
void DoublyLinkedList<T>::insertAt(const T& newElement, size_t index) {
    checkIndex(index);

    if(index == 0)
        insertAtHead(newElement);
    else if(index == length - 1)
        insertAtTail(newElement);
    else{
        Node* current = find(index);
        Node* newNode = new(nothrow) Node(newElement);
        checkOverFlow(newNode);

        // make newNode and Node before the current points to each other
        current->prev->next = newNode;
        newNode->prev = current->prev;

        // make newNode and current  points to each other
        newNode->next = current;
        current->prev = newNode;

    }
    length++;
}

template<class T>
void DoublyLinkedList<T>::insertAfter(Node* prevNode, const T& newElement) {
    Node* newNode = new Node(newElement);

    Node* afterPrevNode = prevNode->next;
    // make newNode and prevNode points to each other
    prevNode->next = newNode;
    newNode->prev = prevNode;
    // make newNode and afterNode points to each other
    newNode->next = afterPrevNode;
    afterPrevNode->prev = newNode;

    length++;
}

template<class T>
void DoublyLinkedList<T>::insertAtHead(const T & value) {
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
void DoublyLinkedList<T>::removeAtHead() {
    checkUnderFlow();

    if(length == 1){
        delete head;
        head = tail = 0;
    }else{
        Node* prev = tail->prev;
        delete tail;
        tail = prev;
        tail->next = 0;
    }
    length--;
}

template<class T>
void DoublyLinkedList<T>::removeAtTail() {
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

    if(index == 0)
        removeAtHead();
    else if(index == length - 1)
        removeAtTail();
    else{
        Node* target = find(index);
        Node* next = target->next;
        Node* prev = target->prev;
        prev->next = next;
        next->prev = prev;
        delete target;
        length--;
    }

}

template<class T>
T &DoublyLinkedList<T>::retrieveAt(const size_t& index) {
    checkIndex(index);
    return (find(index)->data);
}

template<class T>
void DoublyLinkedList<T>::replaceAt(const T& newElement, const size_t& index) {
    checkIndex(index);
    find(index)->data = newElement;
}

template<class T>
void DoublyLinkedList<T>::forwardTraversal() const {
    Node* tempHead = head;
    while(tempHead != 0){
        cout << tempHead->data << ' ';
        tempHead = tempHead->next;
    }
    cout << '\n';
}

template<class T>
void DoublyLinkedList<T>::backwardTraversal()const {
    Node* tempTail = tail;
    while(tempTail != 0){
        cout << tempTail->data << ' ';
        tempTail = tempTail->prev;
    }
    cout << '\n';
}

template<class T>
void DoublyLinkedList<T>::swap(const size_t& index1, const size_t& index2 ){
    checkIndex(index1);
    checkIndex(index2);

    Node* node1 = find(index1);
    Node* node2 = find(index2);

    if (node1 == node2) {
        return;
    }

    // Handle the case where either node1 or node2 is the head or tail
    if (node1->prev == nullptr) {
        head = node2;
    } else if (node2->prev == nullptr) {
        head = node1;
    }

    if (node1->next == nullptr) {
        tail = node2;
    } else if (node2->next == nullptr) {
        tail = node1;
    }

    // Swap next pointers
    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    // Swap prev pointers
    temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;

    // Update next and prev pointers of adjacent nodes
    if (node1->next != nullptr) {
        node1->next->prev = node1;
    }

    if (node1->prev != nullptr) {
        node1->prev->next = node1;
    }

    if (node2->next != nullptr) {
        node2->next->prev = node2;
    }

    if (node2->prev != nullptr) {
        node2->prev->next = node2;
    }
}

template<class T>
void DoublyLinkedList<T>::reverse(){
   if(length <= 1)
       return ;

    Node* current = head; // set current to the head node of the list
    Node* temp = 0;

    while (current != 0) { // traverse the list using the current pointer until it becomes NULL
        temp = current->prev; // store the previous node in temp
        current->prev = current->next; // swap the prev and next pointers of the current node
        current->next = temp;
        current = current->prev; // move to the next node (previously the previous node)
    }

    if (temp != 0) { // update the head pointer to point to the new head of the list
        head = temp->prev;
    }
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
bool DoublyLinkedList<T>::isExist(const T & value) const {
    Node* tempHead = head;
    while(tempHead != 0){
        if(tempHead->data == value)
            return true;

        tempHead = tempHead->next;
    }
    return false;
}

template<class T>
bool DoublyLinkedList<T>:: isItemAtEqual(const T& value, const size_t& index) const{
    checkIndex(index);

    return (find(index)->data == value);
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() const {
    return (length == 0);
}

template<class T>
void DoublyLinkedList<T>::clear() {
    while(!isEmpty())
        removeAtHead();
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
        throw underflow_error("the list is isEmpty!");
}

int main() {
    DoublyLinkedList<int> l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.forwardTraversal();
    l.swap(0,3);
    l.forwardTraversal();



}