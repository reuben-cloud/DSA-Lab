#include <stdio.h>
#include <ctype.h>
#include <math.h>

char stack[50];
int top = -1;

int priority(char x) {
    return (x == '+' || x == '-') ? 1 : (x == '*' || x == '/') ? 2 : (x == '^') ? 3 : 0;
}

void convertToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    top = -1;
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) postfix[j++] = ch;
        else if (ch == '(') stack[++top] = ch;
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') postfix[j++] = stack[top--];
            top--;
        } else {
            while (top != -1 && priority(stack[top]) >= priority(ch)) postfix[j++] = stack[top--];
            stack[++top] = ch;
        }
    }
    while (top != -1) postfix[j++] = stack[top--];
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int evalStack[50], evalTop = -1, vals[256] = {0};
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalpha(postfix[i]) && vals[(unsigned char)postfix[i]] == 0) {
            printf("Enter value for %c: ", postfix[i]);
            scanf("%d", &vals[(unsigned char)postfix[i]]);
        }
    }

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) evalStack[++evalTop] = ch - '0';
        else if (isalpha(ch)) evalStack[++evalTop] = vals[(unsigned char)ch];
        else {
            int op2 = evalStack[evalTop--], op1 = evalStack[evalTop--];
            switch (ch) {
                case '+': evalStack[++evalTop] = op1 + op2; break;
                case '-': evalStack[++evalTop] = op1 - op2; break;
                case '*': evalStack[++evalTop] = op1 * op2; break;
                case '/': evalStack[++evalTop] = op1 / op2; break;
                case '^': evalStack[++evalTop] = pow(op1, op2); break;
            }
        }
    }
    return evalStack[evalTop];
}

int main() {
    char infix[50], postfix[50];
    int choice, converted = 0;
    do {
        printf("\n1. Convert Infix to Postfix\n2. Evaluate Postfix Expression\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter infix expression: ");
            scanf("%s", infix);
            convertToPostfix(infix, postfix);
            printf("Postfix: %s\n", postfix);
            converted = 1;
        } else if (choice == 2) {
            if (!converted) printf("Run Opt 1 first to get a postfix expression\n");
            else printf("Evaluating postfix (%s)...\nResult: %d\n", postfix, evaluatePostfix(postfix));
        } else if (choice == 3) printf("Exiting program\n");
        else printf("Invalid option!\n");
    } while (choice != 3);
    return 0;
}
