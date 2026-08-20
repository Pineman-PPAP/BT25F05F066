#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack implementation
int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0, op1, op2;

    while (exp[i] != '\0') {

        // If operand, push onto stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');   // Convert character to integer
        }

        // If operator, pop two operands and apply operator
        else {
            op2 = pop();
            op1 = pop();

            switch (exp[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '%':
                    push(op1 % op2);
                    break;
                default:
                    printf("Invalid Operator\n");
            }
        }
        i++;
    }

    return pop();
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}