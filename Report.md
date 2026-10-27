# Smart Memory Allocation Simulator — Mini Project Report

## 1. Abstract
The Smart Memory Allocation Simulator is a menu-driven C++ application designed to demonstrate memory allocation strategies used in Operating Systems. It implements First Fit, Best Fit, and Worst Fit and allows users to compare allocation results for a given set of memory blocks and processes.

## 2. Introduction
Memory management is an important responsibility of an Operating System. The OS tracks available memory and assigns memory to processes when required. Different allocation strategies select available memory blocks in different ways, which can affect allocation success and the distribution of free memory.

## 3. Objectives
- Understand contiguous memory allocation.
- Implement First Fit, Best Fit, and Worst Fit algorithms.
- Simulate allocation of processes into memory blocks.
- Identify processes that cannot be allocated.
- Compare the results of the three algorithms.

## 4. Software and Hardware Requirements
**Software**
- C++17-compatible compiler such as GCC or MinGW
- Visual Studio Code or another code editor
- Windows, Linux, or macOS

**Hardware**
- A standard computer capable of running a C++ compiler

## 5. Algorithms
### First Fit
Scans memory blocks from the beginning and chooses the first block with enough remaining space.

### Best Fit
Chooses the smallest remaining block that can accommodate the process.

### Worst Fit
Chooses the largest remaining block that can accommodate the process.

In each case, the allocated process size is subtracted from the selected block's remaining capacity.

## 6. System Workflow
1. Read the number and sizes of memory blocks.
2. Read the number and sizes of processes.
3. Ask the user to select an allocation algorithm or compare all algorithms.
4. Process each request in input order.
5. Allocate a process if a suitable block is available.
6. Display each process's allocation status and summary statistics.

## 7. Implementation
The project is written in C++ and uses vectors to store memory blocks, process sizes, and allocation results. A separate allocation function runs the selected algorithm. The result display function prints process-wise allocation information and summary counts.

## 8. Testing
Suggested test case:
- Memory blocks: `100, 500, 200, 300, 600`
- Process sizes: `212, 417, 112, 426`
- Menu choice: Compare All

The program should display separate allocation tables for First Fit, Best Fit, and Worst Fit. Additional tests should include a process larger than every block, a process that fits exactly, and invalid or non-positive input.

## 9. Results
The simulator reports:
- Which block each process was allocated to, if any
- Number of successful allocations
- Number of failed allocations
- Total remaining free memory

Results vary depending on the allocation algorithm and the input sequence.

## 10. Advantages
- Simple menu-driven interface
- No external libraries required
- Clear demonstration of core memory allocation concepts
- Supports side-by-side comparison of algorithms

## 11. Limitations
- Simulates memory allocation rather than controlling real system memory.
- Processes are considered in the order entered.
- Interactive process termination and deallocation are not implemented.
- Total free memory alone does not quantify external fragmentation.

## 12. Future Scope
- Add process deallocation and memory reuse.
- Display a visual memory map in the terminal.
- Calculate additional fragmentation statistics.
- Export results to a text or CSV report.

## 13. Conclusion
The Smart Memory Allocation Simulator demonstrates three classical memory allocation strategies. It helps students understand how First Fit, Best Fit, and Worst Fit select memory blocks and how allocation results depend on process sizes and the available memory.

## 14. References
1. Operating Systems course notes on memory management.
2. Standard Operating Systems textbooks covering contiguous memory allocation.
