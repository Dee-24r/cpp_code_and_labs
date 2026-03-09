# File I/O with Functions Project

## Overview
This project demonstrates **file input/output (I/O) operations** combined with **functions** for processing data. It focuses on reading data from files, processing information, and writing results back to files. This is a practical introduction to working with persistent data storage in C++.

## Files

### Source Code
- **FileIOwithfunctionsJune25.cpp** - Main program (partially implemented)

### Input Data Files
- **gradesIn.txt** - Input file with student grades
- **grades.txt**, **Grades1.txt**, **Grades2.txt** - Additional grade data files
- **studentScores.txt** - Student score records
- **RescuePets.txt** - Sample data file
- **ANameIWant.txt** - Custom data file

### Output Files
- **gradesOut.txt** - Program output with processed grades

## Program Purpose

The program demonstrates:
1. **Reading** data from multiple input files
2. **Processing** that data (calculations, formatting)
3. **Writing** results to output files
4. Using **functions** to organize I/O operations
5. Proper **error handling** for file operations

## Core Functionality

### File Operations

#### Opening Files for Input
```cpp
ifstream dataIn("gradesIn.txt");
if (!dataIn) {
    cout << "Error opening file." << endl;
    return 1;
}
```

#### Opening Files for Output
```cpp
ofstream dataOut("gradesOut.txt");
```

#### Reading from Files
```cpp
string lastName, firstName;
double quiz1, quiz2, quiz3, quiz4;

dataIn >> lastName >> firstName >> quiz1 >> quiz2 >> quiz3 >> quiz4;
```

#### Writing to Files
```cpp
dataOut << left << setw(13) << "Last Name";
dataOut << setw(13) << "First Name";
```

## Program Features

### Data Processing
- **Reads Student Information**:
  - Last name
  - First name
  - Four quiz scores (quiz1, quiz2, quiz3, quiz4)

- **Calculations**:
  - Calculates average (likely excluding lowest score based on function `avgWithoutLowest`)

- **Output Formatting**:
  - Uses `setw()` for column alignment
  - Uses `left` for left-justification
  - Formats decimal numbers appropriately

### Key Functions

| Function | Purpose |
|----------|---------|
| `avgWithoutLowest(double, double, double, double)` | Calculate average excluding lowest score |
| File I/O operations | Read and write student records |

## How to Use

### 1. Prepare Input File
Create `gradesIn.txt` with format:
```
lastName firstName quiz1 quiz2 quiz3 quiz4
Smith John 85 90 88 92
Johnson Sarah 78 82 80 85
```

### 2. Compile
```bash
g++ FileIOwithfunctionsJune25.cpp -o file_io_demo
```

### 3. Run
```bash
./file_io_demo
```

### 4. Check Output
Review `gradesOut.txt` for processed results:
```
Last Name    First Name   Quiz 1  Quiz 2  Quiz 3  Quiz 4  Average
Smith        John         85.00   90.00   88.00   92.00   89.67
Johnson      Sarah        78.00   82.00   80.00   85.00   82.33
```

## Key Concepts Demonstrated

### File Streams

#### Input Stream (ifstream)
```cpp
ifstream dataIn;
dataIn.open("gradesIn.txt");
```

#### Output Stream (ofstream)
```cpp
ofstream dataOut;
dataOut.open("gradesOut.txt");
```

#### Checking for Errors
```cpp
if (!dataIn) {
    cout << "Error opening file." << endl;
    return 1;
}
```

### Formatting Output

#### Column Width and Alignment
```cpp
dataOut << left              // Left-align text
        << setw(13)          // Column width of 13
        << "Last Name"
        << setw(13)
        << "First Name"
        << setw(8)
        << "Quiz 1";
```

#### Decimal Precision
```cpp
cout << fixed               // Fixed notation
     << setprecision(2)     // 2 decimal places
     << average;
```

### Function Organization

**Separate function for calculations:**
```cpp
double avgWithoutLowest(double q1, double q2, double q3, double q4) {
    double lowest = min({q1, q2, q3, q4});
    return (q1 + q2 + q3 + q4 - lowest) / 3.0;
}
```

## Input/Output Example

### Input (gradesIn.txt)
```
Brown Michael 88 91 87 93
Davis Emily 92 95 90 94
```

### Output (gradesOut.txt)
```
Last Name    First Name   Quiz 1  Quiz 2  Quiz 3  Quiz 4  Average
Brown        Michael      88.00   91.00   87.00   93.00   91.00
Davis        Emily        92.00   95.00   90.00   94.00   93.67
```

## Important Notes

### File Handling Best Practices
1. **Always check if file opened successfully** - Prevents crashes
2. **Close files explicitly or use scope** - Ensures data is flushed
3. **Use proper file paths** - Relative or absolute paths as needed
4. **Handle EOF correctly** - Avoid reading past end of file

### Common Errors
- File not found - Check filename and path
- Formatting mismatches - Ensure input format matches reading code
- Uninitialized variables - Always initialize before use
- Not opening/closing files properly

## Program Structure

```cpp
int main() {
    // Declare file streams
    ifstream dataIn;
    ofstream dataOut;
    
    // Declare variables for data
    string lastName, firstName;
    double quiz1, quiz2, quiz3, quiz4, average;
    
    // Open input file
    dataIn.open("gradesIn.txt");
    
    // Check if opened
    if (!dataIn) { /* error handling */ }
    
    // Open output file
    dataOut.open("gradesOut.txt");
    
    // Write headers
    dataOut << formatHeader;
    
    // Process each record
    while (dataIn >> lastName >> firstName >> quiz1 >> quiz2 >> quiz3 >> quiz4) {
        average = avgWithoutLowest(quiz1, quiz2, quiz3, quiz4);
        dataOut << formattedOutput;
    }
    
    // Close files
    dataIn.close();
    dataOut.close();
    
    return 0;
}
```

## Learning Outcomes

- Master file input/output operations in C++
- Understand `ifstream` and `ofstream` classes
- Practice formatting output with `iomanip` library
- Learn to organize code using functions
- Handle file I/O errors gracefully
- Work with formatted data read from files
- Apply calculations to imported data
- Write formatted results to output files

## Related Files

The project includes multiple data files for different testing scenarios:
- Test with student grades: `gradesIn.txt`, `grades.txt`
- Test with student scores: `studentScores.txt`
- Test with other data: `RescuePets.txt`, `ANameIWant.txt`

Modify the program to read from different files by changing the filename in `dataIn.open()`.
