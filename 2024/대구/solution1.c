/**
 * 대구1. 1부터 n까지 중 짝수의 합 구하기
 * 참고: 코드업 1259번, https://codeup.kr/problem.php?id=1259
 */
#include <stdio.h>

int main(void)
{
    int i;
    int n;
    int sum = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; ++i)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
    }

    printf("%d\n", sum);
    return 0;
}
