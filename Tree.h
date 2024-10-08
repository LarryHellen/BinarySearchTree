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
    int _size = 0;

    void push(Node<T>* &parent, const T& data);

    void inorder(Node<T>* &parent, void (*f)(T& data));
    void inorder(Node<T>* &parent, void (*f)(T& data)) const;

    void preorder(Node<T>* &parent, void (*f)(T& data));
    void preorder(Node<T>* &parent, void (*f)(T& data)) const;

    void postorder(Node<T>* &parent, void (*f)(T& data));
    void postorder(Node<T>* &parent, void (*f)(T& data)) const;

    void clearTree();

    void output(T &data);

    Node<T>* createNode(const T& data);
public:
    Tree();
    Tree(T rootData);
    Tree(const std::initializer_list<T>& list);
    Tree(const Tree<T>& tree);
    ~Tree();

    Tree<T>* operator=(const Tree<T>& tree);

    void push(const T& data);

    void inorder();
    void inorder(void (*f)(T& data));
    void inorder(void (*f)(T& data)) const;
    template<typename U>
    void inorder(void (U::*f)(T& data), U &obj);

    void preorder();
    void preorder(void (*f)(T& data));
    void preorder(void (*f)(T& data)) const;
    template<typename U>
    void preorder(void (U::*f)(T& data), U &obj);

    void postorder();
    void postorder(void (*f)(T& data));
    void postorder(void (*f)(T& data)) const;
    template<typename U>
    void postorder(void (U::*f)(T& data), U &obj);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Tree<U>& list);
};

#include "Tree.cpp"

#endif //TREE_H
