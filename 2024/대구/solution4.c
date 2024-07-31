/**
 * 대구4. 행렬 곱셈
 * 참고: 백준 2740번, https://www.acmicpc.net/problem/2740
 */
#include <stdio.h>

#define MAX_SIZE (100)

void handle_matrix_input(int matrix[][MAX_SIZE], int row, int col)
{
    int i, j;

    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main(void)
{
    int i, j, l;
    int n, m, k;
    int x[MAX_SIZE][MAX_SIZE];
    int y[MAX_SIZE][MAX_SIZE];

    scanf("%d %d", &n, &m);
    handle_matrix_input(x, n, m);

    scanf("%d %d", &m, &k);
    handle_matrix_input(y, m, k);

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < k; ++j)
        {
            int sum = 0;

            for (l = 0; l < m; ++l)
            {
                sum += x[i][l] * y[l][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }

    return 0;
}
