# Operator Overloading - Clock Type Project

## Overview
This project implements a **`ClockType` class** with **overloaded operators** for performing arithmetic and logical operations directly on time objects. It demonstrates advanced object-oriented programming by allowing intuitive time manipulation using standard C++ operators.

## Files

- **ClockType.h** - Class header with operator prototypes
- **ClockTypeImp.cpp** - Implementation of all ClockType methods and operators
- **OperatorOverload.cpp** - Driver/test program demonstrating operator usage

## Class: `ClockType`

### Constructors

- **`ClockType()`** - Default constructor; initializes time to 00:00:00
- **`ClockType(int h, int m, int s)`** - Parameterized constructor; initializes with specific values

### Operator Overloads

| Operator | Operation | Example |
|----------|-----------|---------|
| `==` | Equality comparison | `clock1 == clock2` |
| `>=` | Greater than or equal | `clock1 >= clock2` |
| `<=` | Less than or equal | `clock1 <= clock2` |
| `+` | Time addition | `result = clock1 + clock2` |
| `-` | Time subtraction | `result = clock1 - clock2` |
| `*` | Time multiplication by constant | `result = clock1 * 3` |

### Regular Member Functions

- **`setTime(int, int, int)`** - Set the time
- **`printTime() const`** - Print time in hh:mm:ss format
- **`logic()`** - Adjusts time to valid 24-hour format with carry-over

## Detailed Operator Descriptions

### Comparison Operators

#### `operator==` (Equality)
```cpp
bool operator==(const ClockType& otherClock) const;
```
- Returns `true` if both times are identical
- Compares all three components: hours, minutes, seconds

#### `operator>=` (Greater Than or Equal)
```cpp
bool operator>=(const ClockType& otherClock) const;
```
- Returns `true` if first time is >= second time
- Useful for scheduling and time comparisons

#### `operator<=` (Less Than or Equal)
```cpp
bool operator<=(const ClockType& otherClock) const;
```
- Returns `true` if first time is <= second time

### Arithmetic Operators

#### `operator+` (Addition)
```cpp
ClockType operator+(const ClockType& otherClock) const;
```
- Adds two time objects together
- Result is adjusted to valid 24-hour format
- Example: 08:30:00 + 07:15:00 = 15:45:00

#### `operator-` (Subtraction)
```cpp
ClockType operator-(const ClockType& otherClock) const;
```
- Subtracts second time from first
- **Note**: Assumes first time >= second time
- If first time < second time, results may be invalid
- Example: 15:45:00 - 07:30:00 = 08:15:00

#### `operator*` (Multiplication by Integer)
```cpp
ClockType operator*(int constant) const;
```
- Multiplies each time component by a constant
- Result is adjusted to valid 24-hour format
- Example: 02:30:15 * 2 = 05:00:30

### Helper Function

#### `logic()`
- Adjusts hours, minutes, and seconds to valid ranges
- **Minutes overflow**: Each 60 minutes = 1 hour
- **Seconds overflow**: Each 60 seconds = 1 minute
- **Hours wrap-around**: Uses modulo 24 for 24-hour format
- Example: 78 seconds → 1 minute 18 seconds; 34 hours → 10 hours

## How to Use

### Compile
```bash
g++ ClockTypeImp.cpp OperatorOverload.cpp -o clock_operators
```

### Run
```bash
./clock_operators
```

### Sample Usage in Code

```cpp
#include "ClockType.h"

int main() {
    // Create clock objects
    ClockType clock1(10, 30, 45);
    ClockType clock2(5, 15, 20);
    
    // Display
    clock1.printTime();  // Output: 10:30:45
    clock2.printTime();  // Output: 05:15:20
    
    // Comparison
    if (clock1 >= clock2)
        cout << "Clock1 is >= Clock2\n";
    
    // Addition
    ClockType sum = clock1 + clock2;
    sum.printTime();     // Output: 15:45:65 → 15:46:05
    
    // Subtraction
    ClockType diff = clock1 - clock2;
    diff.printTime();    // Output: 05:15:25
    
    // Multiplication
    ClockType mult = clock1 * 2;
    mult.printTime();    // Output: 21:01:30
    
    // Equality check
    if (clock1 == clock2)
        cout << "Times are equal\n";
    else
        cout << "Times are different\n";
    
    return 0;
}
```

## Key Concepts Demonstrated

### Operator Overloading

**Syntax:**
```cpp
ReturnType operator@(parameters) const {
    // Implementation
}
```

- `operator@` - Special keyword for defining overloaded operator
- Must return appropriate type
- Binary operators take one parameter (second operand)
- Unary operators take no parameters

### Time Arithmetic with Overflow Handling
- Addition and multiplication require automatic adjustment
- `logic()` function ensures result validity
- Maintains 24-hour format throughout

### Const Correctness
- Comparison operators are `const` (don't modify object)
- Return `const` objects from operations when appropriate
- Prevents unintended modifications

### Method Chaining Through Operators
```cpp
ClockType result = (clock1 + clock2) * 2 - clock3;
```

## Input/Output Format

### Input
Times typically entered in hh:mm:ss format or as three integers

### Output
Times displayed as `hh:mm:ss` with leading zeros:
- `08:05:03` (not `8:5:3`)

## Algorithm Examples

### Addition Example (10:30:45 + 5:15:20)
```
Hours:   10 + 5 = 15
Minutes: 30 + 15 = 45
Seconds: 45 + 20 = 65
         65 seconds = 1 min + 5 sec
Result: 15:46:05
```

### Multiplication Example (02:30:15 * 2)
```
Hours:   2 * 2 = 4
Minutes: 30 * 2 = 60 = 1 hour
Seconds: 15 * 2 = 30
Result: (4+1):00:30 = 05:00:30
```

## Limitations

- **Subtraction**: Program assumes first time >= second time
- **Operator Order**: Standard C++ operator precedence applies
- **No division operator**: Not implemented in this version

## Learning Outcomes

- Master operator overloading syntax
- Understand when and how to overload operators
- Practice creating intuitive class interfaces
- Implement complex logic for time calculations
- Handle edge cases in arithmetic operations
- Design classes that behave like built-in types

## Notes

- All operators maintain time validity through the `logic()` function
- Class provides a practical example of real-world operator usage
- Demonstrates how operator overloading improves code readability
