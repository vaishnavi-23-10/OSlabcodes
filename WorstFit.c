#include <stdio.h> #include <limits.h>

#define MAX_MEMORY_SIZE 1000


void worstFit(int memory[], int mem_size, int process_size) { int i, worst_fit = -1;
for (i = 0; i < mem_size; i++) {
if (memory[i] >= process_size) {
if (worst_fit == -1 || memory[i] > memory[worst_fit]) worst_fit = i;
}

}
if (worst_fit != -1) { memory[worst_fit] -= process_size;
printf("Process of size %d is allocated at index %d\n", process_size, worst_fit);
} else {
printf("Process of size %d cannot be allocated using Worst Fit\n", process_size);
}
}


int main() {
int memory[MAX_MEMORY_SIZE] = {100, 300, 200, 400}; // Sample memory blocks
int mem_size = 4; int process_size;

printf("Enter the size of the process: "); scanf("%d", &process_size);

worstFit(memory, mem_size, process_size);


return 0;
}
