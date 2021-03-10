#include "Itemtype.h";
class BST
{
private:

    struct node
    {
        int value;
        node* left;
        node* right;

        node()
        {
            left = nullptr;
            right = nullptr;
        }

        node(int val)
        {
            value = val;
            left = nullptr;
            right = nullptr;
        }
    };

    node* findMin(node* N)
    {
        while (N->left != nullptr)
            N = N->left;
        return N;
    }

public:

	BST();
	~BST();
	void draw(node* N, int height, int actualHeight);
	void drawTree(node* root);
	void removeNode(node*& N, int value);
	void getHeightOfTree(node* N, int& heightMax, int actualHeight);
	bool addNode(node*& N, int value);
	bool isInTree(node* N, int value);
    void menu(node*& root);
};