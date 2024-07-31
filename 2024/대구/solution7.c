/**
 * 대구7. 문자열 해싱
 * 참조: 백준 15829번, https://www.acmicpc.net/problem/15829
 */
#include <stdio.h>

int main(void)
{
    const int M = 1234567891;

    int length;
    long long hash = 0;
    long long r = 1;
    char buf;

    scanf("%d ", &length);

    for (int i = 0; i < length; ++i)
    {
        scanf("%c", &buf);
        hash = (hash + (buf - 'a' + 1) * r) % M;
        r = r * 31 % M;
    }

    printf("%d", hash);
    return 0;
}
