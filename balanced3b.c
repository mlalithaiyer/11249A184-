#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = c;
}
char pop() {
    if (top == -1) {
        return '\0';  
    }
    return stack[top--];
}
int isMatchingPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}
int isBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i]
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                return 0;
            }
            char popped = pop();
            if (!isMatchingPair(popped, ch)) {
                return 0; 
            }
        }
    }

    return (top == -1);
}

int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression))
        printf("The expression has balanced parentheses.\n");
    else
        printf("The expression does NOT have balanced parentheses.\n");

    return 0;
}
