#include <iostream>
#include <exception>
using namespace std;

template<class T>
class SortedLinkedList{
    struct Node{
        Node * next;
        T data;
        Node():next(0){}
        Node(T value, Node* p = 0):data(value),next(p){}
    };
    Node* head;
    size_t size;
    public:
        SortedLinkedList():head(0), size(0){}
        ~SortedLinkedList();

        void insert(T );
        T getMin();
        void display();
        void merge(SortedLinkedList<T>& list2);


};



template<class T>
void SortedLinkedList<T>::insert(T val) {
    Node* newNode = new(nothrow) Node(val);

    // Now the newNode is the Head
    if(!head || val < head->data){
        newNode->next = head;
        head = newNode;
    }
    else{
        Node* currentNode = head;

        // find the position to insert the newNode
        while(currentNode->next && currentNode->next->data < val){
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    size++;
}
template<class T>
T SortedLinkedList<T>::getMin() {
    if(!head)
        throw underflow_error("the list is empty!");
    else
        return head->data;

}
template<class T>
void SortedLinkedList<T>::display() {
    Node* cHead = head;
    while(cHead){
        cout << cHead->data << ' ';
        cHead = cHead->next;
    }
    cout << '\n';

}

template<class T>
void SortedLinkedList<T>::merge(SortedLinkedList<T> &list2) { //O(n + m)
    Node* current1 = head;
    Node* current2 = list2.head;
    SortedLinkedList<T> newList;

    while(current1 && current2) {
        if (current1->data <= current2->data) {
            newList.insert(current1->data);
            current1 = current1->next;
        }
        else{
            newList.insert(current2->data);
            current2 = current2->next;
        }
    }


    while (current1) {
        newList.insert(current1->data);
        current1 = current1->next;
    }
    while (current2) {
        newList.insert(current2->data);
        current2 = current2->next;
    }

    head = newList.head;
    newList.head = 0;
}


template<class T>
SortedLinkedList<T>::~SortedLinkedList() { //O(n)
    Node* cHead = head, *next;
    while(cHead){
        next = cHead->next;
        delete cHead;
        cHead = next;
    }
}

int main()
{
    SortedLinkedList<int> l;
   
    return 0;
}
