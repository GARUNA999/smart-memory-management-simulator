# Smart Memory Allocation Simulator

A C++ command-line Operating Systems mini project that simulates **First Fit**, **Best Fit**, and **Worst Fit** memory allocation strategies.

## Features
- Enter memory block sizes and process memory requirements.
- Run First Fit, Best Fit, or Worst Fit.
- Compare all three algorithms using the same input.
- Display allocated and unallocated processes.
- Show successful allocations, failed allocations, and total remaining free memory.

## OS Concepts
- Contiguous memory allocation
- First Fit, Best Fit, and Worst Fit
- Allocation failure
- Memory utilization and fragmentation concepts

> This is an educational simulation; it does not allocate actual system RAM. Total free memory is the sum of remaining space across blocks and is not, by itself, a measurement of external fragmentation.

## Requirements
- C++17 compiler (GCC / MinGW)
- VS Code or another text editor (optional)

## Compile and Run

### Windows
```bash
g++ -std=c++17 main.cpp -o memory_allocator.exe
.\memory_allocator.exe
```

### Linux / macOS
```bash
g++ -std=c++17 main.cpp -o memory_allocator
./memory_allocator
```

## Sample Input
Use these values when prompted:
- Number of memory blocks: `5`
- Block sizes: `100 500 200 300 600`
- Number of processes: `4`
- Process sizes: `212 417 112 426`
- Choose option: `4` to compare all algorithms

## Files
- `main.cpp` — source code
- `README.md` — project overview and run instructions
- `Report.md` — mini project report

## Future Enhancements
- Add interactive memory deallocation.
- Draw memory blocks using an ASCII diagram.
- Add additional fragmentation metrics.
- Save comparison results to a report file.
