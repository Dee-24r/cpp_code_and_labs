# 10 Programmers Problem - HackerRank Competition Project

## Overview
This project implements a **programming competition simulation** inspired by HackerRank-style coding contests. It tracks multiple programmers' submissions, determines the winner (first to reach 1000 lines of code), and analyzes competition statistics. This project demonstrates **file I/O, array processing, structures, and competitive analysis**.

## Files

### Source Code
- **HackGameCompetition.cpp** - Main driver program
- **hackerRank.h** - Header file with hackerRank structure
- **hackerRankImp.cpp** - Implementation of compute functions

### Input Data
- **program11.txt** - First competition data
- **program12.txt** - Second competition data

## Program Functionality

### Core Features

1. **Competition Tracking**
   - Reads programmer submissions
   - Tracks total lines of code per programmer
   - Detects winner (first to reach 1000 LOC)

2. **Competition Analysis**
   - Displays all programmers' scores
   - Determines how many programmers needed to exceed winner's count
   - Provides detailed statistics

3. **Multiple Games**
   - Supports running two separate competitions
   - Each competition has independent tracking

## Data Structure

### `hackerRank` Structure

```cpp
struct hackerRank {
    int programmerID;      // Unique identifier (1-10)
    int totalLinesCode;    // Total lines submitted
    // Additional fields as needed
};
```

## Main Functions

### 1. `echoPrintInput(ifstream &, hackerRank [])`

**Purpose**: Read submissions and find winner
- Reads submission data from file
- Echoes input to console (for verification)
- Tracks lines of code per programmer
- Flags the winner when threshold (1000) is reached
- **Returns**: ID of winning programmer

**Algorithm**:
```
totalLines = 0
FOR each submission in file:
    Add submission lines to programmer's total
    Print submission (echo)
    IF programmer's total >= 1000:
        Flag programmer as winner
        Return programmer ID
        Break
END FOR
```

### 2. `printProgrammers(hackerRank [])`

**Purpose**: Display all programmers' final scores
- Shows each programmer's ID and total lines
- Displays in formatted table
- Useful for seeing full competition results

**Output Example**:
```
Programmer ID    Total Lines
    1                150
    2                280
    3                980          ← Runner-up
    4               1005          ← WINNER!
    5                156
    ...
```

### 3. `detNoToBeatWinner(int, const hackerRank [])`

**Purpose**: Analyze how many programmers needed to beat winner
- Takes winner's ID and score
- Calculates combined scores of other programmers
- Determines minimum programmers needed to exceed winner's total
- **Key Question**: What's the smallest group needed to outscore the winner?

**Algorithm**:
```
winnerScore = winner's total lines
checkProgrammers = 0
combinedScore = 0

FOR each programmer (in order, excluding winner):
    Add programmer's score to combinedScore
    Increment checkProgrammers
    IF combinedScore > winnerScore:
        Return checkProgrammers
        Break
END FOR
```

**Example Analysis**:
```
Winner: Programmer 4 with 1005 lines

Checking how many programmers needed to exceed 1005:
- Programmer 1 (150): Total = 150 < 1005
- Programmer 2 (280): Total = 430 < 1005
- Programmer 3 (980): Total = 1410 > 1005 ✓

Result: 3 programmers needed to beat the winner
```

## How to Use

### 1. Prepare Input Files

Create input files with submission records:
```
game1 submissions (program11.txt):
programmerID linesOfCode
1 150
2 100
4 200
3 350
2 180
4 355
3 205
2 200
1 180
4 300

(continues until someone reaches 1000)
```

### 2. Compile
```bash
g++ hackerRankImp.cpp HackGameCompetition.cpp -o hack_competition
```

### 3. Run
```bash
./hack_competition
```

### 4. Sample Output

```
Game 1

=== Submissions ===
Programmer 1: 150 lines (Total: 150)
Programmer 2: 100 lines (Total: 100)
Programmer 4: 200 lines (Total: 200)
Programmer 3: 350 lines (Total: 350)
...
Programmer 4: 205 lines (Total: 1005)  ← WINNER!

=== Final Scores ===
Programmer 1: 476 lines
Programmer 2: 512 lines
Programmer 3: 845 lines
Programmer 4: 1005 lines ← WINNER
...

=== To Beat the Winner ===
Programmers 1, 2, and 3 combined: 1833 lines
This exceeds winner's 1005 lines
Therefore, 3 programmers needed to beat the winner.

(Repeat for second competition - Game 2)
```

## Competition Structure

### Multiple Competitions

Program runs **two separate games**:

1. **Game 1** (program11.txt)
   - Independent competition
   - Separate winner
   - Separate analysis

2. **Game 2** (program12.txt)
   - Fresh start with new data
   - Different programmers/scores
   - Independent statistics

Between games, data is reset to track new competition.

## Key Concepts Demonstrated

### File Input Processing
```cpp
ifstream dataIn;
dataIn.open("program11.txt");

if (!dataIn) {
    cout << "File error";
    return 1;
}

while (!dataIn.eof()) {
    dataIn >> programmerID >> linesOfCode;
    // Process data
}

dataIn.close();
```

### Array of Structs
```cpp
hackerRank programmers[10];  // Array for 10 programmers

for (int i = 0; i < 10; i++) {
    programmers[i].totalLinesCode = 0;
    programmers[i].programmerID = i + 1;
}
```

### Competitive Analysis
- Track running totals
- Detect threshold achievement
- Analyze cumulative statistics
- Compare multiple entries

### Function Organization
- Separation of concerns (input, analysis, output)
- Reusable functions for both games
- Clear data flow between functions

## Competition Rules

1. **Win Condition**: First to 1000 lines of code
2. **Input Order**: Programmers' submissions come in sequence
3. **Accumulation**: Each submission adds to programmer's total
4. **Tracking**: All programmers tracked throughout competition
5. **Analysis**: Combined scores analyzed to find how many beat winner

## Algorithm Summary

```
Game Loop (repeat for 2 games):
  1. Open competition data file
  
  2. Read all submissions:
     - Track programmer totals
     - Print submission progress
     - Stop when winner reaches 1000
  
  3. Display all programmers' final scores
  
  4. Analyze beat-the-winner question:
     - Sort or iterate through programmers
     - Accumulate scores until exceeding winner
     - Report minimum programmers needed
  
  5. Close file and repeat for next game
```

## Important Data Points

| Aspect | Value |
|--------|-------|
| Winning threshold | 1000 lines |
| Max programmers | 10 (adjustable) |
| Number of games | 2 |
| Input source | External files |
| Output format | Formatted console |

## Learning Outcomes

- Practice file I/O with multiple records
- Work with arrays of structures
- Implement competitive game logic
- Process real-time data accumulation
- Analyze statistical information
- Track multiple entities simultaneously
- Handle multiple independent competitions
- Design functions for analysis tasks

## Analysis Questions Answered

1. **Who won?** First programmer to 1000 lines
2. **What were the final scores?** All programmers' totals
3. **How many needed to beat the winner?** Cumulative threshold analysis

## Extension Ideas

- Add more metrics (quality score, compile time)
- Implement different win conditions
- Track historical competition data
- Generate leaderboards
- Analyze submission patterns
- Implement ranking system
- Add difficulty levels
- Track programmer statistics across games

## Sample Competition Timeline

```
Submission Order:
1. P1 submits → Total: 150
2. P2 submits → Total: 100
3. P1 submits → Total: 300
4. P3 submits → Total: 200
5. P2 submits → Total: 350
6. P1 submits → Total: 600  (leading)
7. P3 submits → Total: 800  (gaining)
8. P2 submits → Total: 700  (catching up)
9. P3 submits → Total: 1000 ← WINNER! (Game ends)

Final Scores: P3: 1000, P1: 600, P2: 700
```
