# 2-D Dynamic Arrays - Matrix Addition Project

## Overview
This project demonstrates **two-dimensional (2-D) dynamic memory allocation** and **matrix operations**. It creates dynamic 2-D arrays (matrices), accepts user input, performs matrix addition, and displays the results. This is a practical exercise in managing complex dynamic memory structures.

## Files

- **Lab_2-D_dynamic_array.cpp** - Complete program for matrix addition

## Program Functionality

### Main Features

1. **Dynamic 2-D Array Allocation**
   - Allocates three matrices with user-specified dimensions
   - Uses double pointers for row pointers and single pointers for column data

2. **Matrix Input**
   - Prompts user for matrix dimensions (rows and columns)
   - Collects elements for Matrix A
   - Collects elements for Matrix B

3. **Matrix Addition**
   - Adds corresponding elements from Matrix A and Matrix B
   - Stores result in Matrix C

4. **Output Display**
   - Displays all three matrices in formatted grid layout

## Memory Allocation Strategy

### 2-D Array Allocation Pattern

```cpp
int** array1, ** array2, ** array3;  // Triple pointers!

array1 = new int*[row];              // Allocate row pointers
for (i = 0; i < row; i++) {
    array1[i] = new int[col];        // Allocate each row
}
```

**Memory Structure:**
```
array1 ──> [ptr0, ptr1, ptr2, ...]
            ↓      ↓      ↓
           [a00, a01, a02, ...]
           [a10, a11, a12, ...]
           [a20, a21, a22, ...]
```

### How It Works
- `int**` - Pointer to pointer (points to an array of pointers)
- Each `int*` in the array points to a row of integers
- Allows accessing 2-D data with `array[row][column]` syntax

## How to Use

### 1. Compile
```bash
g++ Lab_2-D_dynamic_array.cpp -o matrix_addition
```

### 2. Run
```bash
./matrix_addition
```

### 3. Sample Session

```
Enter number of rows: 2
Enter number of columns: 3

Enter 6 elements for Matrix A:
1 2 3
4 5 6

Enter 6 elements for Matrix B:
2 3 4
5 6 7

Matrix A:
1 2 3
4 5 6

Matrix B:
2 3 4
5 6 7

Matrix C (A + B):
3 5 7
9 11 13
```

## Key Concepts Demonstrated

### Dynamic 2-D Memory Allocation

#### Allocation
```cpp
int** arr = new int*[rows];           // Step 1: Allocate row pointers
for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols];           // Step 2: Allocate each row
}
```

#### Deallocation (Important!)
```cpp
for (int i = 0; i < rows; i++) {
    delete[] arr[i];                  // Delete each row
}
delete[] arr;                         // Delete row pointer array
```

**Order matters**: Always deallocate from inside out (rows first, then the array of pointers)

### Matrix Operations

#### Input (Nested Loops)
```cpp
for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        cin >> array1[i][j];         // Input elements
    }
}
```

#### Addition
```cpp
for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        array3[i][j] = array1[i][j] + array2[i][j];
    }
}
```

#### Output (With Formatting)
```cpp
for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        cout << setw(5) << array[i][j];  // Format output
    }
    cout << "\n";
}
```

### Pointer Arithmetic

**Accessing 2-D Array Elements:**
```cpp
array[i][j]           // Direct indexing
*(*(array + i) + j)   // Pointer arithmetic equivalent
```

Both expressions access the same element, but direct indexing is clearer.

## Program Flow

```
START
  ↓
Input: rows and columns
  ↓
Allocate memory for 3 matrices
  ↓
Input Matrix A elements
  ↓
Input Matrix B elements
  ↓
Calculate Matrix C = A + B
  ↓
Display all three matrices
  ↓
Deallocate memory
  ↓
END
```

## Mathematical Example

**Matrix Addition:**
```
A = [1 2]      B = [5 6]       C = [1+5 2+6]   = [6 8]
    [3 4]          [7 8]           [3+7 4+8]     [10 12]
```

## Important Notes

### Memory Management
- Allocate in order: outer loop first, then inner loops
- Deallocate in **reverse order**: inner loops first, then outer
- Missing deallocation causes memory leaks

### Common Mistakes
1. **Wrong order of deallocation** - Causes crashes
2. **Forgetting brackets in delete[]** - Undefined behavior
3. **Accessing out of bounds** - No bounds checking in C++
4. **Not checking if allocation succeeded** - May crash with large arrays

### Performance Considerations
- 2-D arrays are contiguous in memory
- Row-major storage: rows are stored consecutively
- Iterating row-by-row is more cache-efficient

## Algorithm Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Allocation | O(n×m) | O(n×m) |
| Input | O(n×m) | - |
| Addition | O(n×m) | - |
| Output | O(n×m) | - |
| Deallocation | O(n) | - |

Where n = rows, m = columns

## Visual Memory Layout

```
Stack:                        Heap:
┌──────────────┐             
│ array1 ──┐   │             ┌─── [val00, val01, val02, ...]
│ array2 ──┤───┼────────────→│ ┌─ [val10, val11, val12, ...]
│ array3 ──┘   │             │ │ [val20, val21, val22, ...]
│ row, col     │             
└──────────────┘             
```

## Learning Outcomes

- Master dynamic 2-D array allocation and deallocation
- Understand pointer-to-pointer (`int**`) concepts
- Practice nested loop operations for matrix processing
- Learn proper memory management techniques
- Implement basic linear algebra operations
- Understand 2-D indexing and memory layout
- Apply formatting for console output display

## Extension Ideas

- Implement matrix multiplication
- Add matrix transpose functionality
- Implement Gaussian elimination
- Add input validation for matrix dimensions
- Save/load matrices from files
-Handle non-square matrices for additional operations
