#include<iostream>

#include "SingleLinkedList.cpp"

//using namespace std;


template<class T>
SingleLinkedList<T> mergeTwoLists(const SingleLinkedList<T>& list1, const SingleLinkedList<T>& list2);

int main() {
    SingleLinkedList<int> x = {1, 2, 3, 4}, y = {1,1,1,1,1, 2, 3, 4};
    SingleLinkedList<int> z = mergeTwoLists(x,y);
    z.print();
}

template<class T>
SingleLinkedList<T> mergeTwoLists(const SingleLinkedList<T>& list1, const SingleLinkedList<T>& list2){
    auto current1 = list1.find(0);
    auto current2 = list2.find(0);
    SingleLinkedList<T> newList;

    while(current1 && current2) {
        if (current1->data <= current2->data) {
            newList.insertAtTail(current1->data);
            current1 = current1->next;
        }
        else{
            newList.insertAtTail(current2->data);
            current2 = current2->next;
        }
    }


    while (current1) {
        newList.insertAtTail(current1->data);
        current1 = current1->next;
    }
    while (current2) {
        newList.insertAtTail(current2->data);
        current2 = current2->next;
    }


    return newList;
}