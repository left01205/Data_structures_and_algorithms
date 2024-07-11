#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

// Function prototypes
void push(Stack *s, char c);
char pop(Stack *s);
int isOperator(char c);
int precedence(char c);
void infixToPostfix(char infix[], char postfix[]);
int evaluatePostfix(char postfix[]);

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

// Push operation
void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = c;
}

// Pop operation
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Get precedence of operator
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

// Convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    char c, x;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while ((x = pop(&s)) != '(') {
                postfix[j++] = x;
            }
        } else {
            while (precedence(s.items[s.top]) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0;
    char c;
    int operand1, operand2;

    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            push(&s, c - '0');
        } else {
            operand2 = pop(&s);
            operand1 = pop(&s);

            switch (c) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&s);
}