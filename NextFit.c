#include <stdio.h>


#define MAX_MEMORY_SIZE 1000


void nextFit(int memory[], int mem_size, int process_size, int
*last_allocated) { int i;
for (i = *last_allocated; i < mem_size; i++) { if (memory[i] >= process_size) {
memory[i] -= process_size;
*last_allocated = i;
printf("Process of size %d is allocated at index %d\n", process_size,

i);




}



return;
}












i);

for (i = 0; i < *last_allocated; i++) { if (memory[i] >= process_size) {
memory[i] -= process_size;
*last_allocated = i;
printf("Process of size %d is allocated at index %d\n", process_size,

return;
}
}
printf("Process of size %d cannot be allocated using Next Fit\n", process_size);
}


int main() {
int memory[MAX_MEMORY_SIZE] = {100, 300, 200, 400}; // Sample memory blocks
int mem_size = 4; int process_size;
int last_allocated = 0; // For Next Fit


printf("Enter the size of the process: "); scanf("%d", &process_size);

nextFit(memory, mem_size, process_size, &last_allocated);


return 0;
}
