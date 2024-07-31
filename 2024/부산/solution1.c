/**
 * 부산1. 괄호 그릇
 * 참고: 백준 7567번, https://www.acmicpc.net/problem/7567
 */
#include <stdio.h>

#define MAX_LEN (64)

int main(void)
{
    int i;
    char buf[MAX_LEN];
    int length = 0;

    scanf("%s", buf);

    for (i = 0; buf[i] != '\0'; ++i)
    {
        if (i > 0 && buf[i - 1] == buf[i])
        {
            length += 5;
        }
        else
        {
            length += 10;
        }
    }

    printf("%d\n", length);
    return 0;
}
