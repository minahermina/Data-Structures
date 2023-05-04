#ifdef TREESIMPLEMENTATIONS_BINARYSEARCHTREE_H
#define TREESIMPLEMENTATIONS_BINARYSEARCHTREE_H

#include<iostream>
#include<exception>

using namespace std;
#endif //TREESIMPLEMENTATIONS_BINARYSEARCHTREE_H

#include"binary_tree.h"
template<class Type>
class binary_search_tree : public binary_tree<Type> {
protected:
    using typename binary_tree<Type>::Node;
    Node* find_node(const Type& element);
    void delete_node(Node* node_to_delete);
    Node* find_parent(Node* node);
public:
    bool search(const Type& element);

    void insert(const Type& element);
    void delete_node(const Type& element);
};


template<typename Type>
bool binary_search_tree<Type>::search(const Type& element) {
    return (find_node(element) != nullptr);
}

template<typename Type>
void binary_search_tree<Type>::insert(const Type& element) {
    if(find_node(element) != nullptr) return;

    Node* newNode = new Node(element);
    if (this->root == nullptr) {
        this->root = newNode;
    }
    else {
        Node* current = this->root;
        Node* before_current = current;
        while (current != nullptr) {
            before_current = current;
            if (current->value > element)
                current = current->left;
            else
                current = current->right;
        }
        if (before_current->value > element)
            before_current->left = newNode;
        else
            before_current->right = newNode;
    }

}


template<class Type>
typename binary_tree<Type>::Node* binary_search_tree<Type>::find_node(const Type& element) {
    Node* current = this->root;
    while (current != nullptr) {
        if (current->value == element)
            return current;
        else if (current->value > element)
            current = current->left;
        else
            current = current->right;
    }
    return nullptr;
}

template<class Type>
void binary_search_tree<Type>::delete_node(Node* node_to_delete) {
    if (node_to_delete == nullptr)
        return;

    // Case 1: Node to be deleted has no children
    if (node_to_delete->left == nullptr && node_to_delete->right == nullptr) {
        if (node_to_delete == this->root)
            this->root = nullptr;
        else {
            Node* parent = this->find_parent(node_to_delete);
            if (parent->left == node_to_delete)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        delete node_to_delete;
    }

        // Case 2: Node to be deleted has one child
    else if (node_to_delete->left == nullptr || node_to_delete->right == nullptr) {
        Node* child = (node_to_delete->left != nullptr) ? node_to_delete->left : node_to_delete->right;
        if (node_to_delete == this->root)
            this->root = child;
        else {
            Node* parent = this->find_parent(node_to_delete);
            if (parent->left == node_to_delete)
                parent->left = child;
            else
                parent->right = child;
        }
        delete node_to_delete;
    }

        // Case 3: Node to be deleted has two children
    else {
        Node* successor = node_to_delete->right;
        while (successor->left != nullptr)
            successor = successor->left;
        node_to_delete->value = successor->value;
        this->delete_node(successor);
    }
}

template<class Type>
void binary_search_tree<Type>::delete_node(const Type& element) {
    Node* node_to_delete = find_node(element);
    delete_node(node_to_delete);
}

template<class Type>
typename binary_tree<Type>::Node* binary_search_tree<Type>::find_parent(Node* node) {
    if (node == nullptr || node == this->root)
        return nullptr;

    Node* current = this->root;
    Node* parent = nullptr;
    while (current != nullptr) {
        if (current == node)
            return parent;
        parent = current;
        if (current->value > node->value)
            current = current->left;
        else
            current = current->right;
    }
    return nullptr;
}

//int main() {
//    binary_search_tree<int> tree;
//    tree.insert(3);
//    tree.insert(4);
//    tree.insert(5);
//    tree.insert(50);
//    tree.insert(0);
//}
