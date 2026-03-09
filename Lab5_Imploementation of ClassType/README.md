# Class Type Implementation - Clock Project

## Overview
This project implements a **`clockType` class** that provides comprehensive functionality for working with time values. The class allows setting, displaying, and manipulating time in 24-hour format (hours, minutes, and seconds). It demonstrates **object-oriented programming fundamentals** including encapsulation, data members, and member functions.

## Files

- **Lab5A.cpp** - Main program demonstrating clockType usage
- **times.txt** - Input file containing time data for testing

## Class: `clockType`

### Public Member Functions

#### Time Setting
- **`setTime(int hr, int min, int sec)`** - Sets the time with hour, minute, and second values

#### Time Retrieval & Display
- **`getTime(int& hr, int& min, int& sec) const`** - Extracts time values into reference parameters
- **`printTime() const`** - Prints time in `hh:mm:ss` format with leading zeros

#### Time Increment Operations
- **`incrementSeconds()`** - Adds 1 second, rolls over minutes when needed
- **`incrementMinutes()`** - Adds 1 minute, rolls over hours when needed
- **`incrementHours()`** - Adds 1 hour, wraps around at 24 hours

#### Time Comparison
- **`isEqualto(const clockType& otherClock) const`** - Compares if two times are identical

### Private Data Members
```cpp
private:
    int hr;   // Hours (0-23)
    int min;  // Minutes (0-59)
    int sec;  // Seconds (0-59)
```

## Program Workflow

### Typical Usage Pattern

```cpp
int main() {
    clockType clock1, clock2;
    int hour, minute, second;
    
    // Set time
    clock1.setTime(14, 30, 45);
    
    // Display time
    clock1.printTime();  // Output: 14:30:45
    
    // Get time values
    clock1.getTime(hour, minute, second);
    
    // Increment time
    clock1.incrementSeconds();
    clock1.printTime();  // Output: 14:30:46
    
    // Compare times
    if (clock1.isEqualto(clock2))
        cout << "Times are equal";
}
```

## How to Use

1. **Prepare Input File**
   - Create or update `times.txt` with time data in `hh:mm:ss` format

2. **Compile**
   ```bash
   g++ Lab5A.cpp -o clock_demo
   ```

3. **Run**
   ```bash
   ./clock_demo
   ```

4. **Program will:**
   - Read times from `times.txt` file
   - Create clock objects and set their times
   - Display times in hh:mm:ss format
   - Perform various time operations
   - Compare multiple clock times

## Key Features

### Time Validation & Adjustment
- If invalid time values are set (e.g., 78 seconds), the class adjusts them:
  - 78 seconds becomes 1 minute 18 seconds
  - 34 hours becomes 10 hours (24-hour wrap)
  - Performs automatic carry-over between time units

### 24-Hour Format
- Hours range from 0-23 (military time)
- Automatically wraps from 23:59:59 to 00:00:00

### Increment Logic
```
incrementSeconds():
  if (sec < 59) sec++
  else {sec = 0; incrementMinutes()}

incrementMinutes():
  if (min < 59) min++
  else {min = 0; incrementHours()}

incrementHours():
  if (hr < 23) hr++
  else hr = 0
```

## Input/Output Example

### Input (times.txt)
```
14 30 45
23 59 59
00 00 00
```

### Sample Output
```
Current time: 14:30:45
After increment: 14:30:46

Current time: 23:59:59
After increment: 00:00:00

Current time: 00:00:00
```

## Important Concepts

### Encapsulation
- Private data members (`hr`, `min`, `sec`) 
- Public interface restricts access and ensures data validity

### Reference Parameters
- `getTime()` uses reference parameters for output:
  ```cpp
  clock1.getTime(hour, minute, second);  // Values returned by reference
  ```

### Const Correctness
- Constants after function declaration indicate read-only operations
- `printTime() const` - Cannot modify object state

### Member Function Chaining
- Increment functions call each other when needed
- `incrementSeconds()` may trigger `incrementMinutes()`, which may trigger `incrementHours()`

## Learning Outcomes

- Understand class design and structure
- Practice encapsulation and data hiding
- Implement member functions with proper const correctness
- Work with file input for object initialization
- Design interconnected functions with proper logic flow
- Handle edge cases and data validation in classes

## Notes

- The program assumes valid input file format
- Class automatically handles time overflow scenarios
- Comparison checks all three time components for equality
