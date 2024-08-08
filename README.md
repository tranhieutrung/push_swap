# Push Swap Project

## Overview
This repository contains the implementation of the Push Swap project from 42 School. The goal of the project is to sort a stack of integers using a minimal set of operations. The operations allowed are sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, and rrr.

## Algorithm
### 1. Parse Input
- Split and Validate: The input args is validated and  splitted into individual integer strings. During parsing, each number is checked for validity (i.e., it must be an integer and unique).

- Initialize Stack: If all numbers are valid, a stack a is created with these numbers. Simultaneously, an index for each number is created based on their sorted order (smallest number gets index 0).

### 2. Main Program
The main program determines the number of integers and calls corresponding functions:

- 0 or 1 number: The function returns without doing anything.
- 2 numbers: If not sorted, perform a swap.
- 3 numbers: Handle the 6 possible permutations with specific sorting logic.
- 4 or 5 numbers: 4 numbers: Move the smallest number to stack b, sort the 3 remaining numbers, then push the smallest number back to stack a. 5 numbers: Move the two smallest numbers to stack b, sort the 3 remaining numbers, then push the two smallest numbers back to stack a in order.
- More than 5 numbers: Sort using the chunk method.

### 3. Chunk Method for Larger Numbers

#### Push numbers from stack a to b:
- Determine Chunk Size and Median: Calculate the size of each chunk and the median index value.
- Chunk Splitting: Rotate stack a to find numbers belonging to each chunk and push them to stack b. For numbers in the lower chunk, rotate to place them below the median value. Adjust chunk sizes and boundaries dynamically.
- Continue this process until only 3 numbers remain in stack a.

#### Call sort 3 numbers
- Sort the 3 Remaining Numbers in Stack a.

#### Push numbers from stack b back to a:
- Maintain a highest variable to track the current highest index to push from b to a.
- Rotate or reverse rotate stack b to position the number with the current highest index at the top, then push it to stack a.
- If the number at the top is not the highest, push it and remember the steps taken to rotate or reverse rotate. Adjust the position of a accordingly when the highest number is found.

## Performance
- Program Completion: The program passes the requirements with 125%.
- Average Instructions:
 + For 500 numbers, the average number of instructions ranges from 41xx to 43xx.
 + For 100 numbers, the average number of instructions is around 52x.

## Usage
To compile and run the program:

make
./push_swap <list_of_numbers>

For example:

make
./push_swap 3 2 5 1 4

## Result
Actual Status : finished.

![Push_swap Result](https://github.com/tranhieutrung/images/blob/830492ba71274c5695c8f6cec8e80ff7f3ec39ba/push_swap_result.png)

## Contribution
If you'd like to contribute to the project, please create a pull request on GitHub. Please adhere to the contribution guidelines outlined in the CONTRIBUTING.md file.

## License
This project is distributed under the MIT License.