#include <stdio.h>

int main() {
    int n = 5, m = 3; // Number of processes and resources
    int alloc[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    // The allocation matrix where alloc[i][j] is the amount of resource j allocated to process i.

    int max[5][3] = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3} };
    // The maximum demand matrix where max[i][j] is the maximum demand of resource j by process i.

    int avail[3] = {3, 3, 2};
    // The available resources vector where avail[j] is the amount of resource j available.

    int f[5] = {0}; // Flag array to track allocation status, initialized to 0 (false) for all processes.
    int ans[5], ind = 0; // Array to store safe sequence, and index for safe sequence.

    // Calculate need matrix
    int need[5][3];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    // The need matrix where need[i][j] is the remaining resource j needed by process i.

    // Check for safe sequence
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (!f[i]) {  // This condition checks if the process i has not been allocated resources yet.
                int flag = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) { // If need is greater than available, set flag to 0 (false).
                        flag = 0;
                        break; // Exit the inner loop.
                    }
                }
                if (flag) { // If flag is still 1 (true), it means all needed resources are available.
                    ans[ind++] = i; // Add process i to the safe sequence.
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y]; // Release resources allocated to process i.
                    f[i] = 1; // Mark process i as completed.
                }
            }
        }
    }

    // Check if the system is safe
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (!f[i]) { // If any process is not completed, the system is not in a safe state.
            flag = 0;
            printf("The system is not safe\n");
            break; // Exit the loop.
        }
    }

    // Display safe sequence
    if (flag) { // If flag is still 1 (true), the system is in a safe state.
        printf("Safe Sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d", ans[i]); // Print each process in the safe sequence.
            if (i != n - 1)
                printf(" -> ");
        }
        printf("\n");
    }

    return 0;
}
