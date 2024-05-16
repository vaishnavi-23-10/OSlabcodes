#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to initialize the stack
void initStack(int* top) {
    *top = -1;
}

// Function to check if the stack is full
int isFull(int top) {
    return top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
int isEmpty(int top) {
    return top == -1;
}

// Function to push an element onto the stack
void push(int* stack, int* top, int value) {
    if (!isFull(*top)) {
        stack[++(*top)] = value;
    } else {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
}

// Function to pop an element from the stack
int pop(int* stack, int* top) {
    if (!isEmpty(*top)) {
        return stack[(*top)--];
    } else {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
}

// Function to generate the Fibonacci series using stack
void fibonacci(int n) {
    int stack[MAX_SIZE];
    int top;
    initStack(&top);
    int a = 0, b = 1;
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        push(stack, &top, a);
        int temp = a;
        a = b;
        b = temp + b;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
