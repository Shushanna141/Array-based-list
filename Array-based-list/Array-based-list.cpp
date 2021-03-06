// Array-based-list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include "ArrayList.h"*/
using namespace std;
 template<class ItemType>
 ArrayList<ItemType>::ArrayList() :itemCount(0), maxItems(DEFAULT_CAPACITY)
 {

 }
 template<class ItemType>
 bool ArrayList<ItemType>::isEmpty() const
 {
	 return itemCount == 0;
 }
 template<class ItemType>
 int ArrayList<ItemType>::getLength() const
 {
	 return itemCount;
 }
 template<class ItemType>
 bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry)
 {
	 bool ableToInsert = (newPosition >= 1) &&
		 (newPosition <= itemCount + 1) &&
		 (itemCount < maxItems);
	 if (ableToInsert)
	 {
		 for (int pos = itemCount; pos >= newPosition; pos--)
			 items[pos] = items[pos - 1];

		 items[newPosition - 1] = newEntry;
		 itemCount++;
	 }
	 return ableToInsert;
 }

 template<class ItemType>
 ItemType ArrayList<ItemType>::getEntry(int position) const throw (PrecondViolatedExcep)
 {
	 bool ableToGet = (position >= 1) && (position <= itemCount);
	 if (ableToGet)
		 return items[position - 1];
	 else
	 {
		 string message = "getEntry() called with and empty list or";
		 throw(PrecondViolatedExcep(message));
	 }
 }	
 template<class ItemType>
 void ArrayList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
 {
	 bool ableToSet = (position >= 1) && (position <= itemCount);
	 if (ableToSet)
		 items[position - 1] = newEntry;
	 else
	 {
		 string[message] = "setEntry() ccalled with an empty list or";
		 message = message + "Invalid position";
		 throw(PrecondViolatedExcep(message));
	 }
 }
 template<class ItemType>
 bool ArrayList<ItemType>::remove(int position)
 {
	 bool ableToRemove = (position >= 1) && (position <= itemCount);
	 if (ableToRemove)
	 {
		 for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex < itemCount; fromIndex++, toIndex++)
			 items[toIndex] = items[fromIndex];
		 itemCount--;
	 }
	 return ableToRemove;
 }
 template<class ItemType>
 void ArrayList<ItemType>::clear()
 {
	 itemCount = 0;
 }
int main()
{
	ListInterface<string>* listPtr = new ArrayList<string>();
	string data[] = { "one", "two", "three", "four", "five", "six" };
	cout << "isEmpty: returns" << listPtr->isEmpty() << "; should be  (true)" << endl;
	for (int i = 0; i < 6; i++)
	{
		if (listPtr->insert(i + 1, data[i]))
			cout << "Inserted" << (i + 1) << endl;
		else
			cout << "Cannot insert" << data[i] << "at position" << (i + 1) << endl;
	}

    return 0;
}

