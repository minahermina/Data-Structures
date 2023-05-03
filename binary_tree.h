#ifndef TREESIMPLEMENTATIONS_BINARYTREE_H
#define TREESIMPLEMENTATIONS_BINARYTREE_H
#include<iostream>
using namespace std;

template<typename Type>

class binary_tree{
protected:

        struct Node{
            Node* left;
            Node* right;
            Type value;

            Node():left(nullptr), right(nullptr){
                memset(&value,0,sizeof(value));
            }

            Node(const Type& data):left(nullptr), right(nullptr), value(data){}
        };

        Node* root;
        void inorder(Node* p)const ;
        void preorder(Node* p)const;
        void postorder(Node* p)const;
        size_t count_nodes(Node* p)const ;                          // returns the number of nodes in the binary_tree rooted at 'p'.
        size_t count_leaves(Node* p)const ;
        size_t node_height(Node* p)const ;
        void destroy_node(Node*& p);                                // deleting the tree starting at node 'p';
        void copy_tree(Node *& copy_root, Node* original_root);     // copy a tree rooted at 'original_root' to a tree rooted at 'copy_root'


    public:
        binary_tree() : root(nullptr){
//            root = new Node(1);
//            root->left = new Node(2);
//            root->right = new Node(3);
//            root->left->left = new Node(4);

        }
        ~binary_tree(){clear();}

        binary_tree(const binary_tree<Type>& other);  // Copy Constructor

        binary_tree<Type>& operator=(const binary_tree<Type>& lhs);   //  Assignment Operator

        void print_postorder()const;                // L V R
        void print_preorder()const;                 // V L R
        void print_inorder()const;                  // L R V
        size_t size()const ;                        // returns number of nodes in the tree
        size_t height()const ;                      // returns the height of the tree
        size_t leaves()const ;                      // // returns number of leaves in the tree

        void clear();

};

template<typename Type>
void binary_tree<Type>::inorder(Node *p) const {
    if(p != nullptr){
        inorder(p->left);
        cout << p->value << ' ';
        inorder(p->right);

    }

}

template<typename Type>
void binary_tree<Type>::preorder(binary_tree::Node *p) const {
    if(p != nullptr){
        cout << p->value << ' ';
        inorder(p->left);
        inorder(p->right);

    }

}

template<typename Type>
void binary_tree<Type>::postorder(binary_tree::Node *p) const {
    if(p != nullptr){
        inorder(p->left);
        inorder(p->right);
        cout << p->value << ' ';

    }

}

template<typename Type>
size_t binary_tree<Type>::count_nodes(binary_tree::Node *p) const {
    if(p == nullptr)
         return 0;
    else
        return 1 + count_nodes(p->left) + count_nodes(p->right);
}

template<typename Type>
size_t binary_tree<Type>::count_leaves(binary_tree::Node *p) const {
    if(p == nullptr)
         return 0;
    else if (p->left == nullptr && p->right == nullptr)
        return 1;
    else
        return count_leaves(p->right) + count_leaves(p->right);
}

template<typename Type>
size_t binary_tree<Type>::node_height(binary_tree::Node *p) const {
    if(p == nullptr)
        return 0;
    else
        return 1 + max(node_height(p->right),node_height(p->left));
}

template<typename Type>
void binary_tree<Type>::destroy_node(Node*& p) {
    if(p != nullptr){
        destroy_node(p->left);
        destroy_node(p->right);
        delete p;
        p = nullptr;
    }
}

template<typename Type>
void binary_tree<Type>::copy_tree(Node *& copy_root, Node* original_root){
    if(original_root == nullptr)
        copy_root == nullptr;
    else{
        copy_root = new Node(original_root->value);
        copy_tree(copy_root->left, original_root->left);
        copy_tree(copy_root->right, original_root->right);
    }
}

template<typename Type>
binary_tree<Type>::binary_tree(const binary_tree<Type> &other) {
    if(other.root == nullptr)
        this->root = nullptr;
    else
        copy_tree(this->root, other.root);
}

template<typename Type>
binary_tree<Type> &binary_tree<Type>::operator=(const binary_tree<Type> &lhs) {
    if(this->root == lhs.root)
        return *this;
    else{
        destroy_node(this->root);

        if(lhs.root != nullptr)
            copy_tree(this->root, lhs.root);
        return *this;
    }
}

template<typename Type>
void binary_tree<Type>::print_postorder() const {
    postorder(root);
}

template<typename Type>
void binary_tree<Type>::print_preorder() const {
    preorder(root);
}

template<typename Type>
void binary_tree<Type>::print_inorder() const {
    inorder(root);
}

template<typename Type>
 size_t  binary_tree<Type>::size() const {
    return count_nodes(root);
}

template<typename Type>
size_t binary_tree<Type>::height() const {
    return node_height(root);
}
template<typename Type>
size_t binary_tree<Type>::leaves()const {
    return count_leaves(root);
}

template<typename Type>
void binary_tree<Type>::clear() {
    destroy_node(root);
}


#endif //TREESIMPLEMENTATIONS_BINARYTREE_H
