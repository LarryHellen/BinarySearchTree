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


    //each one fails to Process finished with exit code 139 (interrupted by signal 11:SIGSEGV)

    std::cout << "Inorder:" << std::endl;
    t.inorder();

    std::cout << "\nPreorder Traversal:" << std::endl;
    t.preorder();

    std::cout << "\nPostorder Traversal:" << std::endl;
    t.postorder();
    std::cout << std::endl;

    t.clearTree();

    t.push(1);
    t.push(2);

    t.inorder();

    return 0;
}
