#include <iostream>

#include "Tree.h"

int main()
{
    Tree<int> t;

    t.push(5);
    t.push(3);
    t.push(7);
    t.push(2);
    t.push(4);
    t.push(6);
    t.push(8);

    t.print();  // 2 3 4 5 6 7 8

    return 0;
}