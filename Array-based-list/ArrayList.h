#pragma once
#ifndef _ARRAY_LIST
#define _ARRAY_LIST
#include "ListInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 100;
	ItemType items[5];
	int itemCount;
	int maxItems;
public:
	ArrayList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType$ newEntry);
	void clear();

	ItemType getEntry(int position) const throw(PrecondViolatedExcep);
	
	void setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep);


};
#include "Array-based-list.cpp"
#endif // !_ARRAY_LIST

