#include<iostream>
#include<exception>
#include"binary_tree.h"

using namespace std;

template<class Type>
class binary_search_tree : public binary_tree<Type>{
    protected:
        using typename binary_tree<Type>::Node;
        Node* find_node(const Type& element);
        void delete_node(Node* p);
    public:
        bool search(const Type& element) ;
        void insert(const Type& element);
        void delete_node(const Type& element);
};


template<class Type>
typename binary_tree<Type>::Node *binary_search_tree<Type>::find_node(const Type &element) {
    Node* current = this->root;
    Node* target = nullptr;
    if(current == nullptr){
        return target;
    }else{
        while(current != nullptr){

            if (current->value == element){
               target = current;
                break;
            }
            else if (current->value > element)
                current = current->left;
            else
                current = current->right;
        }
    }
    return target;
}

template<typename Type>
bool binary_search_tree<Type>::search(const Type &element){
    return (find_node(element) != nullptr);
}

template<typename Type>
void binary_search_tree<Type>::insert(const Type &element) {
    Node* newNode = new Node(element);
    if(this->root == nullptr){
        this-> root = newNode;
    }else{
        Node* current = this->root;
        Node* trailCurrent;
        while (current != NULL){
            trailCurrent = current;
            if(current->value > element)
                current = current->left;
            else
                current = current->right;
        }
        if(trailCurrent->value > element)
            trailCurrent->left = newNode;
        else
            trailCurrent->right = newNode;
    }

}

template<typename Type>
void binary_search_tree<Type>::delete_node(const Type &element) {
}


int main(){
    binary_search_tree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
//    tree.print_inorder();
cout << tree.search(2);
//    cout << tree.height();

}
/*
 *
 *      1
 *   4
 *
 *
 * */