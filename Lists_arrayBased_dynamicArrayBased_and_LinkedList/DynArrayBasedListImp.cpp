#include "DynArrayBasedList.h"

//Two very key things about our design, is that in the search function, we return the index
//which is 0-based, not the position which is 1-based.
//Secondly, if I say we cna only insert after the kth element, and the user is giving
//position which is 1-indexed. It means they can't enter 0, they can't insert before the
//first element!

DynArrayBasedList::DynArrayBasedList():size(0){
	array = new int[MAX];
}

DynArrayBasedList::~DynArrayBasedList() {
	delete[]array;
}

int DynArrayBasedList::getSize() const{
	return size;
}

bool DynArrayBasedList::retrieve(int position, int &data) const{
	if (position < 1 || position > size)
		return false;
	data = array[position - 1];
	return true;
}

int DynArrayBasedList::search(int key) const {
	for (int i = 0; i < size; i++) {
		if (array[i] == key)
			return i;//this returns 0-based, not 1-based like the user may expect
	}
	return -1;
}

//Insert after kth element, position is index-1
void DynArrayBasedList::insertItem(int position, int data, bool& success) {
	//size can't be greater than MAX actually, but yh
	success = (size < MAX && position <= size && position >= 1);
	if (success) {
		for (int i = size; i > position; i--)
			array[i] = array[i - 1];
		array[position] = data;
		size++;
	}
}

//delete the kth element
void DynArrayBasedList::deleteItem(int position, int& data, bool& success) {
	success = (position>=1 && position <= size);
	if (success) {
		data = array[position - 1];
		for (int i = position - 1; i < size-1; i++)
			array[i] = array[i + 1];
		size--;
	}
}