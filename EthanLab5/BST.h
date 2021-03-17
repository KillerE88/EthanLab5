#ifndef BITREE_H
#define BITREE_H
#include "ItemType.h"
#include <cstdlib>
#include <iostream>

struct TreeNode
{
	ItemType iData;
	TreeNode* pLeft;
	TreeNode* pRight;
};

class BST
{
private:
	TreeNode* pRoot;
	//Helpers
	void Insert(TreeNode*& pRoot, ItemType iNewItem);
	void CreateNode(TreeNode*& pRoot, ItemType iNewItem);
	void dPoint(TreeNode*& pRoot, ItemType iDeletedItem);
	void Delete(TreeNode*& pRoot, ItemType iDeletedItem);
	void inOrder(TreeNode* pRoot, ItemType& iDeletedItem);
	void inOrderReading(TreeNode* pRoot);
	void PrintGraph(TreeNode* pRoot, int nSpacingValue, int nLevelValue);
	void rOrder(TreeNode* pRoot);
	void Destroy(TreeNode* pRoot);

public:
	BST();
	~BST();
	void Add(ItemType iNewItem);
	void Remove(ItemType iDeletedItem);
	bool IsEmpty();
	bool IsFull();
	void Print();//Alphabet order
	void TPrint(); //Tree
	void RPrint();//Reverse order
};

#endif BITREE_H