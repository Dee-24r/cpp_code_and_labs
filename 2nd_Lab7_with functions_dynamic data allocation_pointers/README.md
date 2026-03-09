# Dynamic Data Allocation - Student Records Project

## Overview
This program demonstrates **dynamic memory allocation** and **pointer manipulation** by managing student records. It reads student data from a file, dynamically allocates memory for an array of students, calculates statistics, and displays results in multiple formats.

## Files

- **Lab7withfunctions.cpp** - Main program with all functionality
- **studentRecords.txt** - Input data file containing student information

## Program Features

### Key Operations

1. **Dynamic Memory Allocation**
   - Allocates array of `studentType` objects based on user input or data file
   - Creates backup copy of data for comparison

2. **Student Data Management**
   - Stores student information: name, ID, average score, and grade
   - Implements a `studentType` class with encapsulation

3. **Calculations**
   - Calculates average score from multiple test scores
   - Determines letter grade based on average (using `calcGrade()` function)

4. **Output Display**
   - Prints original order of students
   - Prints students in reverse order
   - Displays average score for all students

### Student Class Structure

```cpp
class studentType {
    char name[26];      // Student's name
    float avg;          // Average score
    int sID;            // Student ID
    char grade;         // Letter grade (A-F)
};
```

## How to Use

1. **Prepare Input File**
   - Ensure `studentRecords.txt` exists in the same directory
   - Format: Student data lines (program reads specific fields)

2. **Compile**
   ```bash
   g++ Lab7withfunctions.cpp -o student_records
   ```

3. **Run**
   ```bash
   ./student_records
   ```

4. **Program Flow**
   - Opens `studentRecords.txt`
   - Prompts for number of student records
   - Dynamically allocates memory for arrays
   - Reads and processes student data
   - Calculates averages and grades
   - Displays results in original and reverse order

## Key Concepts Demonstrated

### Dynamic Memory Allocation
```cpp
studentType* studentAddy = new studentType[noOfStudents];
studentType* backUpAddy = new studentType[noOfStudents];
```

### Pointer Usage
- Array pointers for dynamic allocation
- Passing pointers to functions for data manipulation
- Manual memory management (allocation and deallocation)

### Functions Used
- `calcGrade(double avg)` - Converts numerical average to letter grade
- Input/output operations for file handling (`ifstream`)

## Sample Input Format

The `studentRecords.txt` file should contain student information that can be parsed by the program to extract:
- Student name
- Student ID  
- Test scores (to calculate average)

## Important Notes

- **Memory Management**: Program allocates memory that should be deallocated after use
- **File Error Handling**: Checks if file opens successfully before processing
- **Array Bounds**: Validates number of students before allocation

## Learning Outcomes

- Practice dynamic memory allocation with `new` operator
- Understand pointer arithmetic and array of objects
- Learn file input operations with `ifstream`
- Apply class design for data organization
- Implement separate forward and reverse iteration
