#include<iostream>
#include<exception>
//#include <memory>

using namespace std;

template<class T>
class singleLinkedList {
private:
    struct Node {
        Node* next;
        T data;
        Node() :next(0) {}
        Node(T value, Node* p = 0) :data(value), next(p) {}
    };

    Node* head;
    Node* tail;
    size_t length;

    // Helper functions
    Node* find(size_t )const;
    void checkIndex(size_t index) const{
        if(index < 0 || index > length-1)
            throw out_of_range("");
        else return;
    }

public:
    singleLinkedList() :head(0), tail(0), length(0) {}
    ~singleLinkedList();
    void push_front(const T&);
    void push_back(const T&);
    void pop_back();
    void pop_front();
    void removeAt(size_t );
    T& getAt(size_t );
    const T& getAt(size_t ) const;
    void display() const;
    size_t size() const;
    T& front();
    T& back();
    bool exist(const T&) const;
    bool empty()const;
    void clear();

};


template<class T>
singleLinkedList<T>::~singleLinkedList() {
    Node* temphead = head;
    while (temphead != 0) {
        Node* next = temphead->next;
        delete temphead;
        temphead = next;
    }
}

template<class T>
typename singleLinkedList<T>::Node* singleLinkedList<T>::find(size_t index)const{
    Node* targetNode = head;
    while(index--){
        targetNode = targetNode->next;
    }
    return targetNode;
}

template<class T>
void singleLinkedList<T>::push_front(const T& value) {
    Node* newNode = new(nothrow) Node(value);

    if (newNode == 0)
        throw overflow_error("the list is full!");

    if (length == 0) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }

    length++;

}

template<class T>
void singleLinkedList<T>::push_back(const T& value) {

    Node* newNode = new(nothrow) Node(value);

    if (newNode == 0)
        throw overflow_error("the list is full!");

    if (length == 0) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    length++;

}

template<class T>
void singleLinkedList<T>::pop_back() { // O(n)
    if (length == 0)
        throw underflow_error("the list is empty!");

    if (length == 1) {
        delete head;
        head = tail = 0;
    }
    else {

        Node* tempHead = head;
        while (tempHead->next != tail)
            tempHead = tempHead->next;

        delete tail;
        tail = tempHead;
        tail->next = 0;
    }
    length--;

}

template<class T>
void singleLinkedList<T>::removeAt(size_t index){
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
        Node* temp = head;
        while(temp->next != target){
            temp = temp->next;
        }
        temp->next = target->next;
        delete target;
        length--;
    }


}

template<class T>
void singleLinkedList<T>::pop_front() {
    if (length == 0)
        throw underflow_error("the list is empty!");

    if (length == 1) {
        delete head;
        head = tail = 0;
    }else{
        Node* next = head->next;
        delete head;
        head = next;
    }

    length--;
}

template<class T>
T& singleLinkedList<T>::getAt(size_t index ){
    checkIndex(index);

    return (find(index)->data);

}

template<class T>
const T& singleLinkedList<T>::getAt(size_t index) const{
    checkIndex(index);
    return (find(index)->data);
}

template<class T>
T& singleLinkedList<T>::front() {
    return (head->data);
}

template<class T>
T& singleLinkedList<T>::back() {
    return (tail->data);
}

template<class T>
void singleLinkedList<T>::display() const {
    Node* temphead = head;
    while (temphead != 0) {
        cout << temphead->data << ' ';
        temphead = temphead->next;
    }
    cout << '\n';
}

template<class T>
size_t singleLinkedList<T>::size() const{
    return length;

}

template<class T>
bool singleLinkedList<T>::exist(const T& value)const {
    Node* tempHead = head;
    while(tempHead != 0){
        if(tempHead->data == value)
            return true;
        tempHead = tempHead->next;
    }
    return false;
}

template<class T>
bool singleLinkedList<T>::empty() const{
    return (head == 0);
}

template<class T>
void singleLinkedList<T>::clear(){
    while(!empty()){
        pop_back();
    }
}

int main() {
    singleLinkedList<int> list;
    list.push_back(1);
    list.push_back(1);
    list.push_back(1);
    list.push_back(2);
    list.display();

}
