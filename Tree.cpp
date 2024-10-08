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
void Tree<T>::push(Node<T>*& parentNode, T data)
{
    if(parentNode == nullptr)
    {
        parentNode = new Node<T>(data);
    } else
    {
        if(data <= parentNode->data)
            push(parentNode->leftChild, data);
        else
            push(parentNode->rightChild, data);
    }
}

template <typename T>
void Tree<T>::inorder(Node<T>* parentNode)
{
    if(parentNode != nullptr)
    {
        inorder(parentNode->leftChild);
        std::cout << parentNode->data;
        inorder(parentNode->rightChild);
    }
}

template <typename T>
void Tree<T>::postorder(Node<T>* parentNode)
{
    if(parentNode != nullptr)
    {
        postorder(parentNode->leftChild);
        postorder(parentNode->rightChild);
        std::cout << parentNode->data << ' ';
    }
}


template <typename T>
void Tree<T>::push(const T& data)
{
    push(root, data);
}

template <typename T>
void Tree<T>::print()
{
    postorder(root);
}

template <typename T>
void Tree<T>::output(T &data)
{
    std::cout << data;
}

template <typename T>
void Tree<T>::inorder()
{
    inorder([](T& data)->void{std::cout << data;});
    inorder(&output, *this);
}

#endif