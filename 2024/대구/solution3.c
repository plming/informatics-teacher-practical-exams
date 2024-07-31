/**
 * 대구3. 각 자리수의 합 구하기
 * 사용자로부터 자연수를 입력 받아, 각 자리수의 합을 출력하는 프로그램을 작성하시오.
 * 단, 변수는 tmp와 sum 2개만 사용할 수 있다.
 *
 * 입력: 12345
 * 출력: 15
 */
#include <stdio.h>

int main(void)
{
    int tmp;
    int sum = 0;

    scanf("%d", &tmp);

    while (tmp != 0)
    {
        sum += tmp % 10;
        tmp /= 10;
    }
    printf("%d\n", sum);

    return 0;
}
