//
// Created by larry on 10/7/2024.
//

#ifndef NODE_H
#define NODE_H


template <typename T>
struct Node
{
    Node(T data);

    T data;
    Node<T> *leftChild = nullptr, *rightChild = nullptr;
};

template <typename T>
Node<T>::Node(T data) : data(data) {}



#endif //NODE_H
