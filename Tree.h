//
// Created by larry on 10/7/2024.
//

#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <iostream>

template <typename T>
class Tree
{
private:
    Node<T>* root = nullptr;


public:
    Tree();
    Tree(T rootData);

    void push(T data);
    void print();

    void push(Node<T>*& parentNode, T data);
    void inorder(Node<T>* parentNode);
};

#include "Tree.cpp"

#endif //TREE_H
