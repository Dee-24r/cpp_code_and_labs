# Swap with Pointers Project

## Overview
This program demonstrates **pointer manipulation** and **dynamic memory allocation** by creating two dynamic arrays, populating them with user input, and then swapping their contents using a helper function that accepts pointers.

## Files

- **swap_with_pointers.cpp** - Complete program demonstrating pointer-based array swapping

## Program Functionality

### Key Features

1. **Dynamic Array Creation**
   - Allocates two arrays with user-specified size
   - Stores them in pointer variables (`amysScores`, `jennysScores`)

2. **User Input**
   - Prompts for array size (same for both arrays)
   - Collects scores for Amy
   - Collects scores for Jenny

3. **Swap Operation**
   - Calls `swapArrays()` function with both pointers
   - Exchanges the contents of both arrays

4. **Display Results**
   - Shows arrays before swap
   - Shows arrays after swap
   - Uses `printMembers()` function to display array contents

## Program Structure

### Main Functions

#### `main()`
```cpp
int main() {
    // Allocate two dynamic integer arrays
    amysScores = new int[size];
    jennysScores = new int[size];
    
    // Get user input
    // Display before swap
    // Call swap
    // Display after swap
}
```

#### `swapArrays(int* arr1, int* arr2, int size)`
- **Purpose**: Swap contents of two arrays by exchanging pointer values
- **Parameters**:
  - `arr1` - Pointer to first array
  - `arr2` - Pointer to second array
  - `size` - Number of elements to swap
- **Operation**: Swaps the pointers themselves (not individual elements)

#### `printMembers(int* arr, int size)`
- **Purpose**: Display all elements in an array
- **Parameters**:
  - `arr` - Pointer to array to print
  - `size` - Number of elements to display
- **Operation**: Iterates through array using pointer arithmetic

## How to Use

1. **Compile**
   ```bash
   g++ swap_with_pointers.cpp -o swap_demo
   ```

2. **Run**
   ```bash
   ./swap_demo
   ```

3. **Sample Session**
   ```
   Enter the size of the arrays (one size for both): 3
   Enter 3 scores for Amy: 85 90 92
   Enter 3 scores for Jenny: 78 88 95
   
   --------Before the swap--------
   These are Amy's Scores
   85 90 92
   
   These are Jenny's Scores
   78 88 95
   
   --------After the swap--------
   These are Amy's Scores
   78 88 95
   
   These are Jenny's Scores
   85 90 92
   ```

## Key Concepts Demonstrated

### Dynamic Memory Allocation
```cpp
int* amysScores = new int[size];      // Allocate on heap
int* jennysScores = new int[size];    // Allocate on heap

// ... use arrays ...

delete[] amysScores;   // Free memory
delete[] jennysScores; // Free memory
```

### Pointer Manipulation

**Swapping Array Pointers:**
- Instead of copying array contents, swap the pointers themselves
- More efficient than element-by-element swap
- After swap, `amysScores` points to what was `jennysScores` and vice versa

**Example:**
```
Before:  amysScores → [85, 90, 92]    jennysScores → [78, 88, 95]
After:   amysScores → [78, 88, 95]    jennysScores → [85, 90, 92]
```

### Pointer Arithmetic
```cpp
for (i = 0; i < size; i++)
    cout << *(arr + i) << " ";  // Access array element using pointer arithmetic
```

## Important Notes

- **Shallow Swap**: This swaps pointers, not array contents
- **Memory Management**: Remember to deallocate with `delete[]` (bracket for arrays)
- **Pointer as Parameter**: Functions receive pointer addresses, allowing modification

## Learning Outcomes

- Understand dynamic memory allocation with `new` and `delete`
- Practice passing pointers to functions
- Learn pointer arithmetic and dereferencing (`*` operator)
- Understand efficiency of pointer swaps vs. element swaps
- Apply these concepts to solve real problems

## Visual Representation

```
Memory Layout (Simplified):

Before Swap:
┌─────────────────────────────────────┐
│ amysScores (address: 0x1000)        │
│ ├─ [85, 90, 92]                     │
│                                     │
│ jennysScores (address: 0x2000)      │
│ ├─ [78, 88, 95]                     │
└─────────────────────────────────────┘

After Swap:
┌─────────────────────────────────────┐
│ amysScores now points to 0x2000     │
│ ├─ [78, 88, 95]                     │
│                                     │
│ jennysScores now points to 0x1000   │
│ ├─ [85, 90, 92]                     │
└─────────────────────────────────────┘
```
