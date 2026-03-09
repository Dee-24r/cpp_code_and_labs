# Lists Implementation Project

I am currently still working on this project, and I will soon update with the implementation of Singly and Doubly Linked Lists.

## Overview
This project implements three fundamental list data structures in C++: **Array-Based Lists**, **Dynamic Array-Based Lists**, and **Singly Linked Lists**. Each implementation provides core list operations such as insertion, deletion, retrieval, and searching.

## Files

### Header Files
- **ArrayBasedList.h** - Interface for array-based list using a fixed-size array (MAX = 100 elements)
- **DynArrayBasedList.h** - Interface for dynamic array-based list with resizable capacity
- **SinglyLinkedList.h** - Interface for singly linked list (node-based structure)

### Implementation Files
- **ArrayBasedListImp.cpp** - Implementation of ArrayBasedList methods
- **DynArrayBasedListImp.cpp** - Implementation of DynArrayBasedList methods
- **SinglyLinkedListImp.cpp** - Implementation of SinglyLinkedList methods

### Main Program
- **user_sFile.cpp** - Driver/user interface program for testing all three list implementations

## Core Functionality

Each list class provides:

| Operation | Purpose |
|-----------|---------|
| `retrieve(position, data)` | Retrieve element at a specific position |
| `search(key)` | Find position of an element by searching for its value |
| `getSize()` | Return current number of elements in the list |
| `InsertElem(k, x, success)` | Insert element x at position k |
| `deleteElem(k, x, success)` | Delete element at position k and return it in x |

## Key Differences

### Array-Based List
- **Fixed Size**: Maximum 100 elements (defined by MAX constant)
- **Memory**: Allocated on stack at compile time
- **Access Time**: O(1) - Constant time access to any element
- **Insertion/Deletion**: O(n) - May require shifting elements

### Dynamic Array-Based List
- **Resizable**: Grows dynamically as needed
- **Memory**: Allocated on heap
- **Access Time**: O(1) - Constant time access
- **Insertion/Deletion**: O(n) - May require shifting and reallocation

### Singly Linked List
- **Node-Based**: Each element is a node with data and pointer to next node
- **Memory**: Allocated on heap per node
- **Access Time**: O(n) - Must traverse from beginning
- **Insertion/Deletion**: O(1) at known position - No shifting needed

## How to Compile and Run

1. Compile all files together:
   ```bash
   g++ user_sFile.cpp ArrayBasedListImp.cpp DynArrayBasedListImp.cpp SinglyLinkedListImp.cpp -o lists_demo
   ```

2. Run the program:
   ```bash
   ./lists_demo
   ```

3. Follow on-screen prompts to test list operations

## Learning Outcomes

- Understand differences between static and dynamic memory allocation
- Learn how different list implementations affect performance
- Practice implementing abstract data types (ADTs)
- Gain experience with pointers and dynamic memory management
- Compare trade-offs between different data structure implementations
