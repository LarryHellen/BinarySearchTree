#include <iostream>

#include "Tree.h"

int main()
{
    Tree<double> t;

    t.push(2);
    t.push(0);
    t.push(5);
    t.push(3.14);
    t.push(2.156);
    t.push(5);
    t.push(10);
    t.push(8);
    t.push(16);
    t.push(32);

    //is this the correct post-order:
    //0 2.156 5 3.14 8 32 16 10 5 2

    /*
     * model view control
     * box
     * cursor
     * model (has text), view (has font, cursor animate), contoller (sets input, gives to view)
     */

    t.print();

    return 0;
}