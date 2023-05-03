#include<iostream>
#include<exception>
#include"binary_tree.h"

using namespace std;

template<class Type>
class binary_search_tree : public binary_tree<Type>{
    private:
    using typename binary_tree<Type>::Node;
    public:
        Node* findNode(const Type& element);
        bool search(const Type& element) const ;
        void insert(const Type& element);
        void delete_node(const Type& element);
};

template<class Type>
typename binary_tree<Type>::Node *binary_search_tree<Type>::findNode(const Type &element) {
    return nullptr;
}

template<typename Type>
bool binary_search_tree<Type>::search(const Type &element) const {
    Node* current = this->root;
    bool found = false;
    if(current == nullptr){
        return false;
    }else{
        while(current != nullptr && !found){

            if (current->value == element)
                found = true;
            else if (current->value > element)
                current = current->left;
            else
                current = current->right;
        }
    }

    return found;
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
    tree.print_inorder();
//    cout << tree.height();

}
/*
 *
 *      1
 *   4
 *
 *
 * */