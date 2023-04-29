#include<iostream>
#include<exception>
//#include <memory>

using namespace std;

template<class T>
class SingleLinkedList {
private:
    struct Node {
        Node* next;
        T data;
        Node() :next(0) {}
        Node(T value, Node* p = 0) :data(value), next(p) {}
    };

    Node* head = 0;
    Node* tail = 0;
    size_t length = 0;

    // Helper functions
    Node* find(size_t )const;
    void checkIndex(size_t index) const{
        if(index < 0 || index > length-1)
            throw out_of_range("");
        else return;
    }

public:
    SingleLinkedList() : head(0), tail(0), length(0) {}

    // for initialization e.g. SingleLinkedList<int> l = {1,2,3};
    SingleLinkedList(const initializer_list<T>&);

    ~SingleLinkedList();

    // Copy Constructor
    SingleLinkedList(const SingleLinkedList<T>&);

    void insertAtHead(const T&);
    void insertAtTail(const T&);
    void removeAtTail();
    void removeAtHead();
    void removeAt(size_t );
    T& retrieveAt(size_t );
    const T& retrieveAt(size_t ) const;
    void replaceAt(T , size_t );
    void insertAt(T , size_t );
    bool isExist(T);
    bool isItemAtEqual(T, size_t);
    void swap(size_t, size_t);
    void print() const;
    size_t size() const;
    T& front();
    T& back();
    bool isEmpty()const;
    void clear();

};


template<class T>
SingleLinkedList<T>::~SingleLinkedList() {
    Node* temphead = head;
    while (temphead != 0) {
        Node* next = temphead->next;
        delete temphead;
        temphead = next;
    }
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(const initializer_list<T>& list) {
    for(auto it = list.begin(); it != list.end(); it++){
        insertAtTail(*it);
    }
}



template<class T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& lhs) {

    Node* lhsHead = lhs.head;
    while(lhsHead != 0){
        this->insertAtTail(lhsHead->data);
        lhsHead = lhsHead->next;
    }
}

template<class T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::find(size_t index)const{
    checkIndex(index);
    //  returns nullptr
    if(length == 0)
        return 0;
    Node* targetNode = head;
    while(index--){
        targetNode = targetNode->next;
    }
    return targetNode;
}

template<class T>
void SingleLinkedList<T>::insertAtHead(const T& value) {
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
void SingleLinkedList<T>::insertAtTail(const T& value) {

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
void SingleLinkedList<T>::removeAtTail() { // O(n)
    if (length == 0)
        throw underflow_error("the list is isEmpty!");

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
void SingleLinkedList<T>::removeAt(size_t index){
    checkIndex(index);

    Node* target = find(index);
    if(head == tail){
        delete head;
        head = tail = 0;
        length--;
        return ;
    }
    if(target == head) removeAtHead();
    else if(target == tail) removeAtTail();
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
void SingleLinkedList<T>::removeAtHead() {
    if (length == 0)
        throw underflow_error("the list is isEmpty!");

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
T& SingleLinkedList<T>::retrieveAt(size_t index ){
    checkIndex(index);

    return (find(index)->data);

}

template<class T>
const T& SingleLinkedList<T>::retrieveAt(size_t index) const{
    checkIndex(index);
    return (find(index)->data);
}

template<class T>
void SingleLinkedList<T>::replaceAt(T newElement, size_t index){
    checkIndex(index);
    retrieveAt(index) = newElement;
}

template<class T>
void SingleLinkedList<T>::insertAt(T newElement, size_t index){
    checkIndex(index);

    if(index == 0) {
        insertAtHead(newElement);
    }
    else if(index == length - 1){
        insertAtTail(newElement);
    }
    else{
        Node* newNode = new(nothrow)Node(newElement);
        Node* prevNode = find(index - 1);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    length++;
}

template<class T>
bool SingleLinkedList<T>::isExist(T element){

    Node* Chead = head;
    while(Chead != 0){
        if(Chead->data == element) return true;

        Chead = Chead->next;
    }

    return false;
}

template<class T>
bool  SingleLinkedList<T>::isItemAtEqual(T element, size_t index){
    checkIndex(index);

    return (find(index)->data == element);
}
template<class T>
void SingleLinkedList<T>::swap(size_t index1, size_t index2) {
    checkIndex(index1);
    checkIndex(index2);

    if (index1 == index2) return;

    Node* node1 = find(index1);
    Node* node2 = find(index2);
    Node* prevNode1 = nullptr;
    Node* prevNode2 = nullptr;

    if (node1 != head)
        prevNode1 = find(index1 - 1);

    if (node2 != head)
        prevNode2 = find(index2 - 1);

    // Swap the nodes by updating their next and previous pointers
    if (prevNode1 != nullptr)
        prevNode1->next = node2;
    else
        head = node2;

    if (prevNode2 != nullptr)
        prevNode2->next = node1;
    else
        head = node1;

    
    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}


template<class T>
T& SingleLinkedList<T>::front() {
    return (head->data);
}

template<class T>
T& SingleLinkedList<T>::back() {
    return (tail->data);
}

template<class T>
void SingleLinkedList<T>::print() const {
    Node* temphead = head;
    while (temphead != 0) {
        cout << temphead->data << ' ';
        temphead = temphead->next;
    }
    cout << '\n';
}

template<class T>
size_t SingleLinkedList<T>::size() const{
    return length;

}

template<class T>
bool SingleLinkedList<T>::isEmpty() const{
    return (head == 0);
}

template<class T>
void SingleLinkedList<T>::clear(){
    while(!isEmpty()){
        removeAtTail();
    }
}

void add(SingleLinkedList<int> v){
    v.print();
}
//
//int main() {
//    SingleLinkedList<int> list = {1,2,3,4};
//}
