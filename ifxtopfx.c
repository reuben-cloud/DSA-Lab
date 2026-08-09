#include <stdio.h>
#include <ctype.h>
#include <math.h>

char stack[50];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

int priority(char x) 
{
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

void convertToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;
    top = -1; 

    while (infix[i] != '\0'){
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } 
        else if (ch == '(') {
            push(ch);
        } 
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } 
        else {
            while (top != -1 && priority(stack[top]) >= priority(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int evalStack[50];
    int evalTop = -1;
    int i = 0;
    char ch;

    while (postfix[i] != '\0') {
        ch = postfix[i];

        if (isdigit(ch)) {
            evalStack[++evalTop] = ch - '0';
        } 
        else {
            int op2 = evalStack[evalTop--];
            int op1 = evalStack[evalTop--];

            switch (ch) {
                case '+': evalStack[++evalTop] = op1 + op2; break;
                case '-': evalStack[++evalTop] = op1 - op2; break;
                case '*': evalStack[++evalTop] = op1 * op2; break;
                case '/': evalStack[++evalTop] = op1 / op2; break;
                case '^': evalStack[++evalTop] = pow(op1, op2); break;
            }
        }
        i++;
    }

    return evalStack[evalTop];
}

int main() {
    char infix[50], postfix[50];
    int choice;
    int converted = 0; 

    do {
        printf("1. Convert Infix to Postfix\n");
        printf("2. Evaluate Postfix Expression\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                convertToPostfix(infix, postfix);
                printf("Postfix: %s\n", postfix);
                converted = 1;
                break;

            case 2:
                if (!converted) {
                    printf("Run Opt 1 first to get a postfix expression\n");
                } else {
                    printf("Evaluating postfix (%s)...\n", postfix);
                    printf("Result: %d\n", evaluatePostfix(postfix));
                }
                break;

            case 3:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid option!\n");
        }
    } while (choice != 3);

    return 0;
}
