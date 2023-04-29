#include<iostream>

#include "SingleLinkedList.cpp"

using namespace std;


// Merge two sorted linked lists
template<class T>
SingleLinkedList<T> mergeTwoSortedLists(const SingleLinkedList<T>& list1, const SingleLinkedList<T>& list2);

//

template<typename T, typename... Args>
SingleLinkedList<T> mergeSortedLists(const SingleLinkedList<T>& l1, const SingleLinkedList<T>& l2, Args... args) {
    SingleLinkedList<T> mergedList = mergeTwoLists(l1, l2);
    return mergeSortedLists(mergedList, args...);
}

template<typename T>
SingleLinkedList<T> mergeSortedLists(const SingleLinkedList<T>& l1) {
    return l1;
}


int main() {
//    SingleLinkedList<int> x = {1, 2, 3, 4}, y = {1,1,1,1,1, 2, 3, 4}, z = {0,0,8,1,8,0,10,12};
//    SingleLinkedList<int> xx = mergeSortedLists(x,y,z);
//    xx.print();
}

//template<class T>
//SingleLinkedList<T> mergeTwoLists(const SingleLinkedList<T>& list1, const SingleLinkedList<T>& list2){
//    auto current1 = list1.find(0);
//    auto current2 = list2.find(0);
//    SingleLinkedList<T> newList;
//
//    while(current1 && current2) {
//        if (current1->data <= current2->data) {
//            newList.insertAtTail(current1->data);
//            current1 = current1->next;
//        }
//        else{
//            newList.insertAtTail(current2->data);
//            current2 = current2->next;
//        }
//    }
//
//
//    while (current1) {
//        newList.insertAtTail(current1->data);
//        current1 = current1->next;
//    }
//    while (current2) {
//        newList.insertAtTail(current2->data);
//        current2 = current2->next;
//    }
//
//
//    return newList;
//}