//
// Created by larry on 10/7/2024.
//

#ifndef TREE_CPP
#define TREE_CPP

#include "Tree.h"

template <typename T>
Tree<T>::Tree(T rootData) : root(new Node<T>(rootData)) {}

template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
Tree<T>::Tree(const std::initializer_list<T>& list)
{
    for(T data : list)
    {
        push(data);
    }
}

template <typename T>
Tree<T>& Tree<T>::operator=(const Tree<T>& tree)
{
    if(this == &tree)
        return *this;

    clearTree();
    _size = 0;

    tree.preorder(tree.root, &Tree<T>::insertData);

    return *this;
}

template <typename T>
Tree<T>::Tree(const Tree<T>& tree) : _size(0), root(nullptr)
{
    tree.preorder(tree.root, &Tree<T>::insertData);
}

template <typename T>
Tree<T>::~Tree()
{
    clearTree();
}

template <typename T>
void Tree<T>::clearTree()
{
    clearTree(root);
    root = nullptr;
    _size = 0;
}

template <typename T>
void Tree<T>::clearTree(Node<T>* &node)
{
    if(node == nullptr)
        return;

    clearTree(node->leftChild);
    clearTree(node->rightChild);

    delete node;
    node = nullptr;
}


template <typename T>
void Tree<T>::push(const T& data)
{
    // Implementation remains the same, but without needing to pass node pointers
    if(root == nullptr)
    {
        root = createNode(data);
        _size++;
    }
    else
    {
        push(root, data);
    }
}

template <typename T>
void Tree<T>::push(Node<T>* &parent, const T& data)
{
    if(data <= parent->data)
    {
        if(parent->leftChild == nullptr)
        {
            parent->leftChild = createNode(data);
            _size++;
        }
        else
        {
            push(parent->leftChild, data);
        }
    }
    else
    {
        if(parent->rightChild == nullptr)
        {
            parent->rightChild = createNode(data);
            _size++;
        }
        else
        {
            push(parent->rightChild, data);
        }
    }
}

template <typename T>
void Tree<T>::inorder(Node<T>* &parent, void (*f)(T& data))
{
    if(parent != nullptr)
    {
        inorder(parent->leftChild);
        f(parent->data);
        inorder(parent->rightChild);
    }
}

template <typename T>
void Tree<T>::inorder(Node<T>* &parent, void (*f)(T& data)) const
{
    if(parent != nullptr)
    {
        inorder(parent->leftChild);
        f(parent->data);
        inorder(parent->rightChild);
    }
}

template <typename T>
void Tree<T>::preorder(Node<T>* &parent, void (*f)(T& data))
{
    if(parent != nullptr)
    {
        f(parent->data);
        preorder(parent->leftChild);
        preorder(parent->rightChild);
    }
}

template <typename T>
void Tree<T>::preorder(Node<T>* &parent, void (*f)(T& data)) const
{
    if(parent != nullptr)
    {
        f(parent->data);
        inorder(parent->leftChild);
        inorder(parent->rightChild);
    }
}


template <typename T>
void Tree<T>::postorder(Node<T>* &parent, void (*f)(T& data))
{
    if(parent != nullptr)
    {
        inorder(parent->leftChild);
        inorder(parent->rightChild);
        f(parent->data);
    }
}

template <typename T>
void Tree<T>::postorder(Node<T>* &parent, void (*f)(T& data)) const
{
    if(parent != nullptr)
    {
        inorder(parent->leftChild);
        inorder(parent->rightChild);
        f(parent->data);
    }
}

template <typename T>
Node<T>* Tree<T>::createNode(const T& data)
{
    return new Node<T>(data);
}


template <typename T>
void Tree<T>::output(T &data)
{
    std::cout << data << ' ';
}

template <typename T>
void Tree<T>::insertData(const T& data)
{
    this->push(data);
}

template <typename T>
void Tree<T>::inorder()
{

    inorder(&Tree::output, *this);
}

template<typename T>
void Tree<T>::inorder(void (*f)(T& data))
{
    inorder(root, (void (*)(void*))f);
}

template<typename T>
void Tree<T>::inorder(void (*f)(T& data)) const
{
    inorder(root, f);
}

template<typename T>
template<typename U>
void Tree<T>::inorder(void (U::*f)(T& data), U &obj)
{
    inorder(f, obj);
}

template<typename T>
void Tree<T>::preorder()
{
    preorder(&Tree::output, *this);
}

template<typename T>
void Tree<T>::preorder(void(*f)(T &data))
{
    preorder(root, (void (*)(void*))f);
}

template<typename T>
void Tree<T>::preorder(void(*f)(T &data)) const
{
    preorder(root, (void (*)(void*))f);
}

template<typename T>
template<typename U>
void Tree<T>::preorder(void(U::*f)(T &data), U &obj)
{
    preorder(f, obj);
}

template<typename T>
void Tree<T>::postorder()
{
    postorder(&Tree::output, *this);
}

template<typename T>
void Tree<T>::postorder(void(*f)(T &data))
{
    postorder(root, (void (*)(void*))f);
}

template<typename T>
void Tree<T>::postorder(void(*f)(T &data)) const
{
    postorder(root, (void (*)(void*))f);
}

template<typename T>
template<typename U>
void Tree<T>::postorder(void(U::*f)(T &data), U &obj)
{
    postorder(f, obj);
}


template <typename U>
std::ostream& operator<<(std::ostream& out, const Tree<U>& tree)
{
    tree.inorder();
    return out;
}

template <typename T>
void Tree<T>::remove(const T& data)
{
    remove(root, data);
}

template <typename T>
void Tree<T>::remove(Node<T>* &node, const T& data)
{
    if(node == nullptr)
        return;

    if(data < node->data)
        remove(node->leftChild, data);
    else if(data > node->data)
        remove(node->rightChild, data);
    else
        removeNode(node);
}

template <typename T>
void Tree<T>::removeNode(Node<T>* &node)
{
    if(node->leftChild == nullptr && node->rightChild == nullptr)
    {
        delete node;
        node = nullptr;
    }
    else if(node->leftChild == nullptr)
    {
        Node<T>* temp = node;
        node = node->rightChild;
        delete temp;
    }
    else if(node->rightChild == nullptr)
    {
        Node<T>* temp = node;
        node = node->leftChild;
        delete temp;
    }
    else
    {
        Node<T>* successor = findSuccessor(node->rightChild);
        node->data = successor->data;
        remove(node->rightChild, successor->data);
    }
}

template <typename T>
Node<T>* Tree<T>::findSuccessor(Node<T>* node)
{
    while(node->leftChild != nullptr)
        node = node->leftChild;
    return node;
}



#endif