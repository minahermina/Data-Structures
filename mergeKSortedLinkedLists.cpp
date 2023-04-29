#include<iostream>

#include "SingleLinkedList.cpp"

using namespace std;


//template<T>
void merge();
int main(){
    SingleLinkedList<int> l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.print();
}