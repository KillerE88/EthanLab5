#include "ItemType.h"

ItemType::ItemType()
{
	item = 0;
}

RelationType ItemType::ComparedTo(ItemType item_)
{
	if (item > item_.Get())
		return GREATER;
	else if (item < item_.Get())
		return LESS;
	else
		return EQUAL;
}