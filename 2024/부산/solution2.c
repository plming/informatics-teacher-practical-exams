/**
 * 부산2. 이등변 삼각형 별찍기
 * 참조: 백준 2442번, https://www.acmicpc.net/problem/2442
 */
#include <stdio.h>

int main(void)
{
    int n;
    int i, j;

    scanf("%d", &n);

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n - i; ++j)
        {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}
