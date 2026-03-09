#pragma once
const int MAX = 100;
class ArrayBasedList
{
public:
	ArrayBasedList();
	//retrieve also known as find.
	bool retrieve(int position, int& data) const;//Retrieve! Find stands for fins the kth element, not find a key.
	int search(int key) const;
	int getSize() const;
	void InsertElem(int k, int x, bool& success);
	void deleteElem(int k, int& x, bool& success);
private:
	int array[MAX];
	int size;
};