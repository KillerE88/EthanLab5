#include "BST.h"
#include <iostream>

using namespace std;

void BST::draw(node* N, int height, int actualHeight)
{
    if (N != nullptr)
    {
        draw(N->right, height, actualHeight + 1);
        cout << setw(actualHeight * 4) << N->value << endl;
        draw(N->left, height, actualHeight + 1);
    }
    else if (actualHeight <= height)
    {
        for (size_t i = 0; i < height - actualHeight + 1; i++)
        {
            cout << endl;
        }
    }
}

void BST::drawTree(node* root)
{
    int height = 0;
    if (root != nullptr)
    {
        getHeightOfTree(root, height, 1);
        draw(root, height, 1);
    }
    else
        cout << "Tree is empty!" << endl;
}

void BST::removeNode(node*& N, int value)
{
    if (N == nullptr)  //nothing to do, return
        return;
    if (value < N->value) //found value bigger than wanted, go left
        removeNode(N->left, value);
    else if (value > N->value)
        removeNode(N->right, value); //found value smaller than wanted, go right
    else //found the right value, delete
    {
        if (N->left == nullptr && N->right == nullptr) //no chlidren case
        {
            N = nullptr;
        }
        else if (N->left == nullptr) //right child case
        {
            N = N->right;
        }
        else if (N->right == nullptr) //left child case
        {
            N = N->left;
        }
        else  //both child case
        {
            node* temp = findMin(N->right);
            N->value = temp->value;
            removeNode(N->right, temp->value);
        }
    }
}

void BST::getHeightOfTree(node* N, int& heightMax, int actualHeight)
{
    if (actualHeight > heightMax)
        heightMax = actualHeight;
    if (N->right != nullptr)
        getHeightOfTree(N->right, heightMax, actualHeight + 1);
    if (N->left != nullptr)
        getHeightOfTree(N->left, heightMax, actualHeight + 1);
}

bool BST::addNode(node*& N, int value)
{
    static bool added = false; //returns don't work well with recurrence...
    if (N == nullptr)
    {
        node* newNode = new node(value);
        N = newNode;
        added = true;
    }
    else if (isInTree(N, value) == false)
    {
        if (value >= N->value)
            addNode(N->right, value);
        else
            addNode(N->left, value);
    }
    else
        added = false;
    return added;
}

bool BST::isInTree(node* N, int value)
{
    while (N != nullptr)
    {
        if (N->value == value)
            return true;
        N = (N->value < value) ? N->right : N->left;
    }
    return false;
}

void BST::menu(node*& root)
{
    int choice, value;
    cout << "1> Add new node" << endl;
    cout << "2> Remove a node" << endl;
    cout << "3> Draw whole tree" << endl;
    cout << "4> Show height" << endl;
    cout << "0> Quit" << endl;
    cout << "> ";
    cin >> choice;
    switch (choice)
    {
    case 0: // end app
        delete root;
        exit(0);
        break;
    case 1: // add element
        cout << "Value of node to be added > ";
        cin >> value;
        if (addNode(root, value) == true)
            cout << "Node has been added successfully!" << endl;
        else
            cout << "Such node already exists!" << endl;
        break;
    case 2: // remove element
        cout << "Value of node to be deleted > ";
        cin >> value;
        if (isInTree(root, value) == true)
        {
            removeNode(root, value);
            cout << "Node has been deleted successfully!" << endl;
        }
        else
            cout << "Such node doesn't exist!" << endl;
        break;
    case 3: // draw tree
        drawTree(root);
        break;
    case 4: // get height
        int height = 0;
        if (root != nullptr)
            getHeightOfTree(root, height, 1);
        cout << "Height: " << height << endl;
        break;
    }
}