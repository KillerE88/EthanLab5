#include "BST.h"
using namespace std;

BST::BST()
{
	pRoot = NULL;
}

void BST::Add(ItemType iNewItem)
{
	if (IsFull() == false)
		Insert(pRoot, iNewItem);
}

//Helper function to BiTree::Add()
void BST::Insert(TreeNode*& pRoot, ItemType iNewItem)
{
	if (pRoot == NULL)
		CreateNode(pRoot, iNewItem);
	else if (iNewItem.ComparedTo(pRoot->iData) == LESS)
		Insert(pRoot->pLeft, iNewItem);
	else if (iNewItem.ComparedTo(pRoot->iData) == GREATER)
		Insert(pRoot->pRight, iNewItem);
}

//Helper function to 
void BST::CreateNode(TreeNode*& pRoot, ItemType iNewItem)
{
	pRoot = new TreeNode;
	pRoot->iData = iNewItem;
	pRoot->pLeft = pRoot->pRight = NULL;
}

void BST::Remove(ItemType iDeletedItem)
{
	if (IsEmpty() == false)
		dPoint(pRoot, iDeletedItem);
}

void BST::dPoint(TreeNode*& pRoot, ItemType iDeletedItem)
{
	if (iDeletedItem.ComparedTo(pRoot->iData) == EQUAL)
		Delete(pRoot, iDeletedItem);
	else if (iDeletedItem.ComparedTo(pRoot->iData) == LESS)
		Delete(pRoot->pLeft, iDeletedItem);
	else if (iDeletedItem.ComparedTo(pRoot->iData) == GREATER)
		Delete(pRoot->pRight, iDeletedItem);
}

void BST::Delete(TreeNode*& pRoot, ItemType iDeletedItem)
{
	TreeNode* pTemp = pRoot;

	if (pRoot->pLeft == NULL)
	{
		pRoot = pRoot->pRight; 
		delete pTemp;
	}
	else if (pRoot->pRight == NULL) {
		pRoot = pRoot->pLeft;
		delete pTemp;
	}
	else {
		inOrder(pRoot->pLeft, iDeletedItem);
		pRoot->iData = iDeletedItem;
		dPoint(pRoot->pLeft, iDeletedItem);
	}
}

void BST::inOrder(TreeNode* pRoot, ItemType& iDeleteItem)
{
	while (pRoot->pRight != NULL)
		pRoot = pRoot->pRight;

	iDeleteItem = pRoot->iData;
}

bool BST::IsEmpty()
{
	return (pRoot == NULL);
}

bool BST::IsFull()
{
	try
	{
		TreeNode* pTest = new TreeNode;
		delete pTest;
		return false;
	}
	catch (std::bad_alloc exception) {
		return true;
	}
}

void BST::Print()
{
	inOrderReading(pRoot);
}

//Helper function to BiTree::Print()
void BST::inOrderReading(TreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		inOrderReading(pRoot->pLeft);
		cout << pRoot->iData.Get() << " ";
		inOrderReading(pRoot->pRight);
	}
}

void BST::TPrint()
{
	PrintGraph(pRoot, 0, 1);
}

void BST::PrintGraph(TreeNode* pRoot, int nSpacingValue, int nLevelValue)
{
	//Base case and end of recursive calls to PrintGraph()
	if (pRoot == NULL)
		return;
	nSpacingValue += nLevelValue;
	PrintGraph(pRoot->pRight, nSpacingValue, nLevelValue);

	cout << std::endl;
	for (int i = nLevelValue; i < nSpacingValue; i++)
	cout << '\t';
	cout << pRoot->iData.Get() << "\n";
	PrintGraph(pRoot->pLeft, nSpacingValue, nLevelValue);
}

void BST::RPrint()
{
	rOrder(pRoot);
}
void BST::rOrder(TreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		rOrder(pRoot->pRight);
		cout << pRoot->iData.Get() << " ";
		rOrder(pRoot->pLeft);
	}
}

BST::~BST()
{
	Destroy(pRoot);
}
void BST::Destroy(TreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		Destroy(pRoot->pLeft);
		Destroy(pRoot->pRight);
		delete pRoot;
	}
}