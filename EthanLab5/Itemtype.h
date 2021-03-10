#ifndef ITEMTYPE_H
#define ITEMTYPE_H

const int MAX_ITEMS = 100;
typedef int type;

enum RelationType
{
	LESS,
	GREATER,
	EQUAL
};

class ItemType
{
public:
	ItemType();
	RelationType ComparedTo(ItemType item_);
	void Set(type item_) { item = item_; };
	type Get() { return item; };
	type getValue() { return item; };

private:
	type item;
};



#endif // !ITEMTYPE_H