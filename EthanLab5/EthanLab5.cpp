#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "BST.h"
#include "BST.cpp"

using namespace std;

int main(int argc, const char** argv)
{
    node* root = NULL;
    addNode(root, 15);
    addNode(root, 20);
    addNode(root, 18);
    addNode(root, 22);
    addNode(root, 6);
    addNode(root, 5);
    addNode(root, 8);
    while (true)
    {
        menu(root);
        system("PAUSE");
        system("CLS");
    }
    return 0;
}