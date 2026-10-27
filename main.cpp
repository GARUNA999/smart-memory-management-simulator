#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Result {
    vector<int> allocation;
    int allocatedCount = 0;
    int failedCount = 0;
    int unusedMemory = 0;
};

Result allocateMemory(const vector<int>& originalBlocks,
                      const vector<int>& processes,
                      int choice) {
    vector<int> blocks = originalBlocks;
    Result result;
    result.allocation.assign(processes.size(), -1);

    for (int i = 0; i < static_cast<int>(processes.size()); ++i) {
        int selected = -1;

        for (int j = 0; j < static_cast<int>(blocks.size()); ++j) {
            if (blocks[j] < processes[i]) continue;

            if (choice == 1) { // First Fit
                selected = j;
                break;
            }

            if (selected == -1 ||
                (choice == 2 && blocks[j] < blocks[selected]) ||
                (choice == 3 && blocks[j] > blocks[selected])) {
                selected = j;
            }
        }

        if (selected != -1) {
            result.allocation[i] = selected;
            blocks[selected] -= processes[i];
            ++result.allocatedCount;
        } else {
            ++result.failedCount;
        }
    }

    for (int remaining : blocks) result.unusedMemory += remaining;
    return result;
}

void displayResult(const vector<int>& processes,
                   const Result& result,
                   const string& algorithmName) {
    cout << "\n===== " << algorithmName << " =====\n";
    cout << left << setw(12) << "Process"
         << setw(20) << "Memory Required"
         << "Allocated Block\n";
    cout << string(48, '-') << '\n';

    for (int i = 0; i < static_cast<int>(processes.size()); ++i) {
        cout << left << setw(12) << ("P" + to_string(i + 1))
             << setw(20) << processes[i];

        if (result.allocation[i] == -1)
            cout << "Not allocated\n";
        else
            cout << "B" << result.allocation[i] + 1 << '\n';
    }

    cout << "\nSuccessfully allocated: " << result.allocatedCount << '\n';
    cout << "Failed allocations:     " << result.failedCount << '\n';
    cout << "Total free memory:      " << result.unusedMemory << '\n';
}

int main() {
    int n, m;

    cout << "=====================================\n";
    cout << " SMART MEMORY ALLOCATION SIMULATOR\n";
    cout << "=====================================\n";

    cout << "Enter number of memory blocks (1-100): ";
    if (!(cin >> n) || n < 1 || n > 100) {
        cout << "Invalid number of memory blocks.\n";
        return 1;
    }

    vector<int> blocks(n);
    cout << "Enter sizes of memory blocks:\n";
    for (int i = 0; i < n; ++i) {
        if (!(cin >> blocks[i]) || blocks[i] <= 0) {
            cout << "Block sizes must be positive integers.\n";
            return 1;
        }
    }

    cout << "Enter number of processes (1-100): ";
    if (!(cin >> m) || m < 1 || m > 100) {
        cout << "Invalid number of processes.\n";
        return 1;
    }

    vector<int> processes(m);
    cout << "Enter memory requirements of processes:\n";
    for (int i = 0; i < m; ++i) {
        if (!(cin >> processes[i]) || processes[i] <= 0) {
            cout << "Process sizes must be positive integers.\n";
            return 1;
        }
    }

    cout << "\n1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Compare All Algorithms\n";
    cout << "Choose an option: ";

    int choice;
    if (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid choice.\n";
        return 1;
    }

    const vector<string> names = {"", "First Fit", "Best Fit", "Worst Fit"};

    if (choice == 4) {
        for (int algorithm = 1; algorithm <= 3; ++algorithm) {
            Result result = allocateMemory(blocks, processes, algorithm);
            displayResult(processes, result, names[algorithm]);
        }
        cout << "\nComparison complete.\n";
        cout << "Note: Total free memory is not by itself a measure of external fragmentation.\n";
    } else {
        Result result = allocateMemory(blocks, processes, choice);
        displayResult(processes, result, names[choice]);
    }

    return 0;
}
