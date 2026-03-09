# Juice Machine Project

## Overview
This project implements a **juice machine simulation** (vending machine). It demonstrates class design, state management, and object-oriented programming principles. The program models the behavior of a juice dispensing machine that manages inventory and cash.

## Files

- **juiceMachine.cpp** - Main program with juice machine implementation

## Program Functionality

### Core Components

The program implements a `cashRegister` class (and likely related classes) that simulates a juice vending machine with:

1. **Cash Management**
   - Tracks cash on hand
   - Accepts payment from customers
   - Calculates change

2. **Juice Selection**
   - Multiple juice options available
   - Different prices per juice type

3. **Inventory Management**
   - Tracks quantity of each juice type
   - Prevents dispensing when out of stock

4. **Transaction Processing**
   - Accepts user payment
   - Validates sufficient funds
   - Dispenses juice
   - Returns change

## Class Structure

### `cashRegister` Class

```cpp
class cashRegister {
public:
    // Constructor - initializes cash on hand (default 500)
    cashRegister(int cashIn = 500);
    
    // Get current balance of cash in register
    int getCurrentBalance() const;
    
    // Accept payment from customer
    void acceptAmount(double amountIn);
    
private:
    int cashOnHand;  // Current cash available
};
```

## Key Concepts Demonstrated

### Class Design
- **Constructor** with default parameters
- **Member functions** for operations
- **Data encapsulation** with private members
- **Const correctness** for read-only operations

### State Management
- Tracking machine state (inventory, cash, items sold)
- Updating state with each transaction
- Maintaining accurate records

### Object-Oriented Programming
- Modeling real-world entity (vending machine) as a class
- Encapsulating related data and operations
- Providing user interface through member functions

## How to Use

### 1. Compile
```bash
g++ juiceMachine.cpp -o juice_machine
```

### 2. Run
```bash
./juice_machine
```

### 3. Program Flow
```
START
  ↓
Initialize juice machine with starting cash
  ↓
Display menu with juice options and prices
  ↓
LOOP:
  ├─ Accept user selection
  │ (juice type or exit)
  ├─ Check if juice available
  ├─ Get payment from customer
  ├─ Verify sufficient funds
  ├─ Dispense juice
  ├─ Calculate and return change
  ├─ Update inventory and cash
  └─ Continue? (Yes → repeat loop, No → proceed)
  ↓
Display final statistics
  ↓
END
```

## Typical Interaction Example

```
=== Juice Machine Menu ===
1. Orange Juice ($3.00)
2. Apple Juice ($2.50)
3. Grape Juice ($2.75)
4. Exit

Select juice (1-4): 1
Please insert $3.00
Amount inserted: $5.00

Dispensing Orange Juice...
Your change: $2.00

Current cash in register: $505.00
```

## Important Notes

### Implementation Details
- The program appears to be a skeleton/partial implementation
- Core functionality needs completion
- Constructor initializes with default cash value of 500 units

### Features to Implement
Based on the class definition:
1. Complete constructor implementation
2. Implement `getCurrentBalance()` method
3. Implement `acceptAmount()` method
4. Create main menu/loop system
5. Handle juice selection
6. Process transactions
7. Calculate change
8. Update inventory

### Data Tracking
```cpp
int cashOnHand;     // Current cash in register
// Additional needed:
int juiceCount[];   // Inventory for each juice type
double juicePrice[]; // Price for each juice type
int totalSold;      // Statistics
```

## Algorithm for Transaction

```
IF juice is available THEN
    Display price
    Accept customer payment
    IF payment >= price THEN
        Calculate change = payment - price
        Dispense juice
        Add payment to cashOnHand
        Decrement juice inventory
        Return change to customer
        Display "Thank you!"
    ELSE
        Display "Insufficient funds"
        Return payment
    END IF
ELSE
    Display "Out of stock"
END IF
```

## Learning Outcomes

- Practice class design with state management
- Understand encapsulation and data hiding
- Implement constructors with default parameters
- Use const correctness in member functions
- Model real-world scenarios in code
- Handle transactions and state updates
- Practice control flow and loops
- Implement menu-driven programs

## Extension Ideas

- Add multiple juice types and inventory tracking
- Implement discount for bulk purchases
- Add inventory restocking function
- Create transaction history log
- Add bill/coin handling with denominations
- Implement "juice of the day" specials
- Add admin functions to check sales statistics
- Implement error handling for invalid input

## Notes

- Program demonstrates practical use of classes for system simulation
- Vending machine is a good example of state machine design
- Consider using arrays or vectors for multiple juice types in real implementation
- File I/O could be added to persist state between runs
