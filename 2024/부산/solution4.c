/**
 * 부산4. 자리 올림수 경우의 수 구하기
 * 두 숫자를 입력받아 두 숫자 사이에 자리 올림수가 발생하는 경우의 수를 구하는 프로그램을 작성하시오.
 *
 * 입력:
 * 25 27
 *
 * 출력:
 * (25,26)
 * (25,27)
 * (26,27)
 * 경우의 수: 3
 */
#include <stdio.h>

/// @brief 두 수를 더하여 자리올림(carry)이 발생하는지 확인한다.
/// @param n1 덧셈의 첫번째 피연산자
/// @param n2 덧셈의 두번째 피연산자
/// @return 자리올림이 있으면 1, 없으면 0
int has_carry(int n1, int n2)
{
    while (n1 != 0 && n2 != 0)
    {
        int digit1 = n1 % 10;
        int digit2 = n2 % 10;

        if (digit1 + digit2 >= 10)
        {
            return 1;
        }

        n1 /= 10;
        n2 /= 10;
    }

    return 0;
}

int main(void)
{
    int i, j;
    int start;
    int end;
    int count = 0;

    scanf("%d %d", &start, &end);
    for (i = start; i <= end; ++i)
    {
        for (j = i + 1; j <= end; ++j)
        {
            if (has_carry(i, j))
            {
                printf("(%d,%d)\n", i, j);
                ++count;
            }
        }
    }

    printf("경우의 수: %d\n", count);
    return 0;
}
