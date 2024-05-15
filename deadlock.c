#include <stdio.h>



#define MAX_PROCESSES 10

#define MAX_RESOURCES 10



int allocation[MAX_PROCESSES][MAX_RESOURCES];

int max_need[MAX_PROCESSES][MAX_RESOURCES]; int available_resources[MAX_RESOURCES];
int n_processes, n_resources;



int checkDeadlock() {

int work[MAX_RESOURCES]; int finish[MAX_PROCESSES];


for (int i = 0; i < n_resources; i++) work[i] = available_resources[i];


for (int i = 0; i < n_processes; i++) finish[i] = 0;


int count = 0;

while (count < n_processes) { int found = 0;
for (int i = 0; i < n_processes; i++) { if (finish[i] == 0) {
int safe = 1;

for (int j = 0; j < n_resources; j++) {

if (max_need[i][j] - allocation[i][j] > work[j]) { safe = 0;
break;

}

}

if (safe) {

for (int k = 0; k < n_resources; k++) work[k] += allocation[i][k];
finish[i] = 1;

count++; found = 1;
}

}

}

if (!found) break;
}



if (count < n_processes)

return 1; // Deadlock detected else
return 0; // No deadlock

}



int main() {

printf("Enter number of processes: "); scanf("%d", &n_processes);
printf("Enter number of resources: "); scanf("%d", &n_resources);


printf("Enter available resources:\n");

for (int i = 0; i < n_resources; i++)

scanf("%d", &available_resources[i]);



printf("Enter maximum need for each process:\n"); for (int i = 0; i < n_processes; i++) {
printf("For process P%d: ", i);

for (int j = 0; j < n_resources; j++) scanf("%d", &max_need[i][j]);
}



printf("Enter allocated resources for each process:\n"); for (int i = 0; i < n_processes; i++) {
printf("For process P%d: ", i);

for (int j = 0; j < n_resources; j++) scanf("%d", &allocation[i][j]);
}



if (checkDeadlock())

printf("Deadlock detected.\n"); else
printf("No deadlock detected.\n");



return 0;

}
