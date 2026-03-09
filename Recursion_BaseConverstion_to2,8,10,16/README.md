# Recursion & Base Conversion Project

## Overview
This program converts decimal (base 10) numbers to other number bases including **binary (base 2)**, **octal (base 8)**, and **hexadecimal (base 16)** using a **recursive algorithm**. It demonstrates the power of recursion for solving mathematical problems.

## Files

- **Recursion_BaseConversion.cpp** - Complete program with recursive conversion function

## Program Functionality

### Main Features

1. **Interactive User Input**
   - Prompts user to enter a decimal number
   - Asks for target base (2, 8, 10, or 16)
   - Special termination input: enter `999` to exit

2. **Recursive Conversion**
   - Uses recursive `Convert()` function
   - Converts with proper formatting for each base
   - Handles hexadecimal representation (A=10, B=11, etc.)

3. **Output Display**
   - Shows original number
   - Shows converted value in target base
   - Repeats until user enters 999

## How It Works

### Recursive Algorithm

```cpp
void Convert(int num, int base)
{
    if (num != 0)
    {
        Convert(num / base, base);           // Recursive call
        int remainder = num % base;
        
        // Handle hexadecimal letters (A-F)
        if (base == 16 && remainder >= 10) {
            // Convert 10-15 to A-F
        }
    }
}
```

### Base Conversion Logic

The algorithm works by:
1. **Divide** the number by the target base
2. **Recursively process** the quotient (major part)
3. **Print** the remainder (digit in new base)

**Example: Converting 25 to binary (base 2)**
```
Convert(25, 2)
  → Convert(12, 2)
    → Convert(6, 2)
      → Convert(3, 2)
        → Convert(1, 2)
          → Convert(0, 2) [Base case - stops]
          Print: 1
        Print: 1
      Print: 0
    Print: 1
  Print: 0
Print: 1

Result: 11001 (which is 25 in binary)
```

## How to Use

1. **Compile**
   ```bash
   g++ Recursion_BaseConversion.cpp -o base_converter
   ```

2. **Run**
   ```bash
   ./base_converter
   ```

3. **Sample Session**
   ```
   Enter a base 10 number here or enter '999' to terminate: 255
   Enter the base that you want this converted to: 16
   
   Conversion: 255 = FF in base 16
   
   Enter a base 10 number here or enter '999' to terminate: 999
   ```

## Supported Bases

| Base | Name | Digits | Example |
|------|------|--------|---------|
| 2 | Binary | 0, 1 | 1010 |
| 8 | Octal | 0-7 | 12 |
| 10 | Decimal | 0-9 | 10 |
| 16 | Hexadecimal | 0-9, A-F | A |

## Hexadecimal Representation

For base 16, remainders are converted to letters:
- 10 → A
- 11 → B
- 12 → C
- 13 → D
- 14 → E
- 15 → F

## Key Concepts Demonstrated

### Recursion
- **Base Case**: When `num == 0`, recursion stops
- **Recursive Case**: Calls `Convert(num / base, base)`
- **Call Stack**: Manages the order of digit output

### Base Conversion Mathematics
- Remainder gives the digit in new base
- Division reduces the number for next iteration
- Post-order processing (print after recursion) gives correct digit order

## Algorithm Complexity

- **Time Complexity**: O(log_base(n)) - proportional to number of digits in result
- **Space Complexity**: O(log_base(n)) - call stack depth

## Learning Outcomes

- Understand recursive function design
- Learn how recursion solves mathematical problems
- Practice call stack visualization
- Understand number base systems
- Implement character mapping for hexadecimal conversion
