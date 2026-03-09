#pragma once
const int MAX = 100;
class DynArrayBasedList
{
public:
	DynArrayBasedList();
	~DynArrayBasedList();
	int getSize() const;
	bool retrieve(int k, int& x) const;
	int search(int key) const;
	void insertItem(int position, int data, bool& success);
	void deleteItem(int position, int& data, bool& success);
private:
	int *array;
	int size;
};

