#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>


struct Stack {
    int top;
    char items[100];
};

void push(struct Stack *s, char item) {
    if (s->top == 99) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++s->top] = item;
}

char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    stack.top = -1;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(&stack, infix[i]);
        else if (infix[i] == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(')
                postfix[j++] = pop(&stack);
            if (stack.top == -1) {
                printf("Invalid expression\n");
                exit(1);
            }
            pop(&stack); // Pop '('
        } else {
            while (stack.top != -1 && precedence(infix[i]) <= precedence(stack.items[stack.top]))
                postfix[j++] = pop(&stack);
            push(&stack, infix[i]);
        }
    }

    while (stack.top != -1) {
        if (stack.items[stack.top] == '(') {
            printf("Invalid expression\n");
            exit(1);
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    stack.top = -1;
    int i, t1, t2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i]))
            push(&stack, postfix[i] - '0');
        else {
            t2 = pop(&stack);
            t1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, t1 + t2);
                    break;
                case '-':
                    push(&stack, t1 - t2);
                    break;
                case '*':
                    push(&stack, t1 * t2);
                    break;
                case '/':
                    if (t2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(&stack, t1 / t2);
                    break;
            }
        }
    }
    result = pop(&stack);
    return result;
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of evaluation: %d\n", result);

    return 0;
}
    
