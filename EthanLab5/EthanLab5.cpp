#include <iostream>
#include "BST.h"

using namespace std;

void Input(char cInput, BST& Tree);
void Add(BST& Tree);
void Del(BST& Tree);

int main()
{
	BST Tree;
	char user = -1;
	do
	{
		cout << " " << endl;
		cout << "(A) Add" << endl;
		cout << "(D) Delete" << endl;
		cout << "(P) Print Alphabetical" << endl;
		cout << "(R) Print Reverse" << endl;
		cout << "(T) Print Tree" << endl;
		cout << "(E) Exit" << endl;
		cout << "Input: ";
		cin >> user;

		Input(user, Tree);
	} while (toupper(user) != 'E');
	return 0;
}

void Input(char user, BST& Tree)
{
	switch (toupper(user))
	{
	case 'A':	Add(Tree);
		break;

	case 'D':	Del(Tree);
		break;

	case 'P':	Tree.Print();
		break;

	case 'R':	Tree.RPrint();
		break;

	case 'T':	Tree.TPrint();
		break;

	case 'E':	break;

	default:	cout << "You had six choices how..." << endl;
		break;
	}
}

void Add(BST& Tree)
{
	ItemType iNewItem;
	string sNewData = " ";
	cout << "Enter a website you wish to add: ";
	cin >> sNewData;
	iNewItem.Set(sNewData);
	Tree.Add(iNewItem);
}

void Del(BST& Tree)
{
	ItemType iDeletedItem;
	string sDeletedData = " ";
	cout << "Enter a website you wish to delete: ";
	cin >> sDeletedData;
	iDeletedItem.Set(sDeletedData);
	Tree.Remove(iDeletedItem);
}