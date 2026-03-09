#include "ArrayBasedList.h"

ArrayBasedList::ArrayBasedList() :size(0) {}
//Don't initialise the mebers, remember

int ArrayBasedList::getSize() const {	
	return size;
}

//Finds the position'th element, and takes
//Function genuinely should be called retrieve
bool ArrayBasedList::retrieve(int position, int& data) const {
	if (position >= 1 && position <= size) {
		data = array[position - 1];
		return true;
	}
	return false;
}

//See if you find this key and return the index, return -1 otherwise
int ArrayBasedList::search(int key) const {
	for (int i = 0; i < size; i++)
		if (array[i] == key)
			return i;
	return -1;
}

//Insert after the kth element!
void ArrayBasedList::InsertElem(int position, int data, bool& success) {
	//position is index-1, even if actual code is index-0, and we're inserting after 
	// posiitionth element, so we're inserting at position
	// Condition 1 - gats be greater or equal to 1 cuz position is user-friendly, (i.e index-1).
	// Condition 2 - We can either insert at a position less than or just equal to size
	//Condition 3 - If you tell me to indert in maximum capacity of 100, 
	// and we already have 100 elements, can't do!
	success = (position >= 1 && position <= size && size < MAX);
	if (success) {
		for (int i = size - 1; i >= position; i--) {
			array[i+1] = array[i];
		}
		array[position] = data;
		size++;
	}
}


void ArrayBasedList::deleteElem(int position, int& data, bool& success) {
	success = (position <= size && position >= 1);
	if (success) {
		data = array[position - 1];
		for (int i = position - 1; i < size - 2; i++)
			array[i] = array[i+1];
		size--;
	}
}
//check that we actually have data at that position, and then