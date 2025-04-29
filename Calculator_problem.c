#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100

int Evaluation(const char *equation_given, int *error_flag);
int calculate(int a, int b, char op, int *error_flag);
int isOperator(int c);

int main() {
    char equation_given[MAX_EXPRESSION_LENGTH];
    printf("Enter a mathematical expression: ");
    if (fgets(equation_given, MAX_EXPRESSION_LENGTH, stdin) == NULL) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    size_t equation_length = strlen(equation_given);
    if (equation_given[equation_length - 1] == '\n') {
        equation_given[equation_length - 1] = '\0';
    }

    int error_flag = 0;
    int equation_solution = Evaluation(equation_given, &error_flag);

    if (error_flag == 1) {
        printf("Error: Invalid expression.\n");
    } else if (error_flag == 2) {
        printf("Error: Division by zero.\n");
    } else {
        printf("Result: %d\n", equation_solution);
    }

    return 0;
}


int Evaluation(const char *equation_given, int *error_flag) {
    int number_stack[MAX_EXPRESSION_LENGTH];
    char sign_stack[MAX_EXPRESSION_LENGTH];
    int top_number = -1, top_sign = -1;

    for (size_t i = 0; equation_given[i] != '\0'; ) {
        if (isspace(equation_given[i])) {
            i++; 
            continue;
        }
        if (isdigit(equation_given[i])) {
            int number = 0;
            while (isdigit(equation_given[i])) {
                number = number * 10 + (equation_given[i] - '0');
                i++;
            }
            number_stack[++top_number] = number;
        } else if (isOperator(equation_given[i])) {
            while (top_sign >= 0 &&
                   ((sign_stack[top_sign] == '*' || sign_stack[top_sign] == '/') ||
                    ((sign_stack[top_sign] == '+' || sign_stack[top_sign] == '-') &&
                     (equation_given[i] == '+' || equation_given[i] == '-')))) {
                int b = number_stack[top_number--];
                int a = number_stack[top_number--];
                char op = sign_stack[top_sign--];
                int result = calculate(a, b, op, error_flag);
                if (*error_flag != 0) return 0;
                number_stack[++top_number] = result;
            }
            sign_stack[++top_sign] = equation_given[i];
            i++;
        } else {
            *error_flag = 1;
            return 0;
        }
    }

    while (top_sign >= 0) {
        int b = number_stack[top_number--];
        int a = number_stack[top_number--];
        char op = sign_stack[top_sign--];
        int result = calculate(a, b, op, error_flag);
        if (*error_flag != 0) return 0;
        number_stack[++top_number] = result;
    }

    return number_stack[top_number];
}


int calculate(int a, int b, char op, int *error_flag) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a * b;
    } else if (op == '/') {
        if (b == 0) {
            *error_flag = 2;
            return 0;
        }
        return a / b;
    }
    *error_flag = 1;
    return 0;
}

int isOperator(int c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
