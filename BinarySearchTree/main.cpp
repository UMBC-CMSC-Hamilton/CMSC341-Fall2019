#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BinarySearchTree bst;
    int num;
    cin >> num;
    while(num != -1)
    {
        bst.insert(num);
        bst.printTree();
        cin >> num;
    }
    return 0;
}
