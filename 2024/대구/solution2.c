/**
 * 대구2. 구구단 출력하기
 * 참고: 코드업 1351번, https://codeup.kr/problem.php?id=1351
 */
#include <stdio.h>

int main(void)
{
    int start, end;
    int i, j;

    scanf("%d %d", &start, &end);

    for (i = start; i <= end; ++i)
    {
        for (j = 1; j < 10; ++j)
        {
            printf("%d*%d=%d\n", i, j, i * j);
        }
    }

    return 0;
}
