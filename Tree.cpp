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
Tree<T>* Tree<T>::operator=(const Tree<T>& tree)
{
    if(this == &tree)
        return *this;

    clearTree();

    _size = tree._size;

    tree.preorder(&push,&tree); //copy tree?

    return *this;
}

template <typename T>
Tree<T>::Tree(const Tree<T>& tree) : _size(tree._size)
{
    tree.preorder(&push,&tree); //copy tree?
}

template <typename T>
Tree<T>::~Tree()
{
    clearTree();
}

template <typename T>
void Tree<T>::clearTree()
{
    //do this
}


template <typename T>
void Tree<T>::push(Node<T>* &parent, const T& data)
{
    if(parent == nullptr)
    {
        parent = createNode(data);
    } else
    {
        if(data <= parent->data)
            push(parent->leftChild, data);
        else
            push(parent->rightChild, data);
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
        inorder(parent->leftChild);
        inorder(parent->rightChild);
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
void Tree<T>::push(const T& data)
{
    push(root, data);
}


template <typename T>
void Tree<T>::output(T &data)
{
    std::cout << data << ' ';
}

template <typename T>
void Tree<T>::inorder()
{
    inorder([](T& data)->void{std::cout << data;});
    //inorder(&output, *this);
}




template <typename U>
std::ostream& operator<<(std::ostream& out, const Tree<U>& tree)
{
    tree.inorder();
    return out;
}


#endif