# Extra Credit PayRoll - Structs with Functions Project

## Overview
This project implements an **employee payroll system** using **structs and functions**. It reads employee records from a file, calculates pay including overtime, deductions, and net salary, and displays formatted payroll information. This project demonstrates data organization with structs and practical file I/O usage.

## Files

- **PayRoll.cpp** - Main program with payroll calculations
- **employeePay.txt** - Input file with employee records
- **Extra_Credit_PayRoll_structs_with_functions.vcxproj.user** - Visual Studio project configuration

## Program Functionality

### Core Features

1. **Employee Data Management**
   - Reads employee records from file
   - Stores employee information in structs
   - Organizes multiple employees' data

2. **Salary Calculations**
   - Calculates regular and overtime hours
   - Computes overtime pay (typically 1.5× regular pay)
   - Calculates total pay before deductions
   - Calculates taxes and deductions
   - Computes net salary

3. **Output Reporting**
   - Displays formatted payroll report
   - Shows individual employee details
   - Calculated fields displayed clearly

## Data Structure

### `employeePay` Struct

```cpp
struct employeePay {
    string firstName;   // Employee first name (from file)
    string lastName;    // Employee last name (from file)
    double payPerHour;  // Hourly rate (from file)
    int hrsWorked;      // Hours worked (from file)
    int overtimeHrs;    // Calculated: hours over 40
    double pay;         // Calculated: total gross pay
    double taxesPaid;   // Calculated: tax amount
    double netSalary;   // Calculated: pay after taxes
};
```

### Global Variables

```cpp
ifstream dataIn("employeePay.txt");  // Input file stream
int regularHrs = 40;                 // Standard work hours
```

## Program Functions

### Core Operations

#### `readInput(employeePay&)`
- **Purpose**: Read employee record from file
- **Parameters**: Reference to employeePay struct
- **Operations**: Extracts firstName, lastName, payPerHour, hrsWorked from input

#### `calcAndUpdate(employeePay&)`
- **Purpose**: Calculate pay fields
- **Parameters**: Reference to employeePay struct
- **Calculations**:
  ```
  overtimeHrs = max(0, hrsWorked - regularHrs)
  regularPay = (hrsWorked - overtimeHrs) * payPerHour
  overtimePay = overtimeHrs * payPerHour * 1.5
  pay = regularPay + overtimePay
  taxesPaid = pay * taxRate (typically 20-25%)
  netSalary = pay - taxesPaid
  ```

#### `printPayRoll(const employeePay&)`
- **Purpose**: Display formatted payroll line
- **Parameters**: Const reference to employeePay struct
- **Output**: Formatted row with all employee data

## How to Use

### 1. Prepare Input File

Create `employeePay.txt` with employee records:
```
firstName lastName payPerHour hrsWorked
John Smith 15.00 45
Mary Johnson 18.50 42
Robert Brown 12.75 40
```

### 2. Compile
```bash
g++ PayRoll.cpp -o payroll_system
```

### 3. Run
```bash
./payroll_system
```

### 4. Output Display

The program produces formatted payroll output:
```
Last Name    First Name   Pay per hr  Hours  Overtime  Pay        Taxes    Net Salary

Smith        John         15.00       45     5         682.50     136.50   546.00
Johnson      Mary         18.50       42     2         419.00     83.80    335.20
Brown        Robert       12.75       40     0         510.00     102.00   408.00
```

## Calculation Examples

### Example 1: Employee with Overtime
```
Employee: John Smith
Pay/hour: $15.00
Hours: 45

Regular hours: 40 × $15.00 = $600.00
Overtime hours: 5
Overtime pay: 5 × $15.00 × 1.5 = $112.50
Gross pay: $600.00 + $112.50 = $712.50

Taxes (20%): $712.50 × 0.20 = $142.50
Net salary: $712.50 - $142.50 = $570.00
```

### Example 2: Employee without Overtime
```
Employee: Robert Brown
Pay/hour: $12.75
Hours: 40

Regular hours: 40 × $12.75 = $510.00
Overtime hours: 0
Overtime pay: $0.00
Gross pay: $510.00

Taxes (20%): $510.00 × 0.20 = $102.00
Net salary: $510.00 - $102.00 = $408.00
```

## Key Concepts Demonstrated

### Structs for Data Organization
```cpp
struct employeePay {
    // Group related data together
    // Can pass entire record as one parameter
};
```

**Advantages:**
- Logical grouping of related fields
- Easier to pass multiple related values to functions
- Represents real-world entity (employee + pay info)

### Reference Parameters

```cpp
void calcAndUpdate(employeePay& emp)  // Reference: modifies original
void printPayRoll(const employeePay& emp)  // Const reference: read-only
```

**Benefits:**
- Avoid copying large structs
- Function can modify caller's data (when appropriate)
- Const prevents accidental modification

### File Input Processing

```cpp
while (!dataIn.eof()) {
    readInput(processEmployee);      // Read one record
    calcAndUpdate(processEmployee);  // Calculate fields
    printPayRoll(processEmployee);   // Display results
}
```

### Output Formatting

```cpp
cout << left              // Left-align
     << fixed             // Fixed decimal notation
     << setprecision(2)   // 2 decimal places
     << setw(13)          // Column width
     << "Last Name";
```

## Payroll Calculation Algorithm

```
FOR each employee in file:
    1. Read: firstName, lastName, payPerHour, hrsWorked
    
    2. Calculate:
       - If hrsWorked > 40:
         - overtimeHrs = hrsWorked - 40
         - regularPay = 40 × payPerHour
       - Else:
         - overtimeHrs = 0
         - regularPay = hrsWorked × payPerHour
       
       - overtimePay = overtimeHrs × payPerHour × 1.5
       - grossPay = regularPay + overtimePay
       - taxesPaid = grossPay × 0.20 (or applicable rate)
       - netSalary = grossPay - taxesPaid
    
    3. Display all values in formatted table row
END FOR
```

## Input/Output Example

### Input (employeePay.txt)
```
Alice Garcia 20.00 50
Bob Miller 16.75 38
Carol Davis 22.50 44
```

### Output
```
Last Name    First Name   Pay per hr  Hours  Overtime  Pay        Taxes    Net Salary
Garcia       Alice        20.00       50     10        700.00     140.00   560.00
Miller       Bob          16.75       38     0         636.50     127.30   509.20
Davis        Carol        22.50       44     4         757.50     151.50   606.00
```

## Important Notes

### Tax Rate
- Current implementation uses specific tax rate (check code)
- Typical US: 20-25% federal withholding
- May need adjustment for actual use

### Overtime Calculation
- Standard assumes 40-hour work week
- Overtime multiplier: 1.5× (time and a half)
- Can be adjusted in code if needed

### Error Handling
- Checks if file opens successfully
- Handles EOF (end of file) properly
- May need additional validation

## Learning Outcomes

- Master struct usage for data organization
- Practice file input with multiple records
- Implement payroll calculations
- Use reference parameters effectively
- Apply formatting for financial data
- Organize code with functions
- Process batch data from files
- Create meaningful output reports

## Extension Ideas

- Add validation for input values
- Implement different employee types (salary vs. hourly)
- Add benefits calculations (health insurance, retirement)
- Support multiple pay periods per year
- Generate individual pay stubs
- Add year-to-date tracking
- Calculate quarterly tax payments
- Export payroll to CSV format
- Implement year-end W-2 calculations

## Typical Use Case

```
HR Department Workflow:
1. Employee hours submitted in employeePay.txt
2. Run payroll program
3. Review output for accuracy
4. Generate checks or direct deposits
5. Archive report for records
```
