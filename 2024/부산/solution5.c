/**
 * 부산5. 후위 표기식(Postfix Notation) 평가
 * 참고: 코드업 3127번, https://codeup.kr/problem.php?id=3127
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN (201)

int stack[MAX_LEN];
int top = -1;

void stack_push(int item)
{
    stack[++top] = item;
}

int stack_pop()
{
    return stack[top--];
}

int main(void)
{
    const char *DELIMITERS = " \n";
    int i;
    char expression[MAX_LEN];
    char *token;

    fgets(expression, MAX_LEN, stdin);

    token = strtok(expression, DELIMITERS);

    while (token != NULL)
    {
        /* 피연산자일 경우 자연수, 연산자일 경우 0 */
        int value = atoi(token);

        if (value == 0)
        {
            int operand2 = stack_pop();
            int operand1 = stack_pop();

            switch (token[0])
            {
            case '+':
                stack_push(operand1 + operand2);
                break;
            case '-':
                stack_push(operand1 - operand2);
                break;
            case '*':
                stack_push(operand1 * operand2);
                break;
            default:
                break;
            }
        }
        else /* 피연산자일 경우 */
        {
            stack_push(value);
        }

        token = strtok(NULL, DELIMITERS);
    }

    printf("%d\n", stack_pop());
    return 0;
}
