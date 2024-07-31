/**
 * 부산6. 바이러스
 * 참고: 코드업 4503번, https://codeup.kr/problem.php?id=4503
 */
#include <stdio.h>

#define MAX_VERTEX (101)

/* 정점 i와 j가 연결되어 있을 경우, graph[i][j] = 1 */
int graph[MAX_VERTEX][MAX_VERTEX];

/* 정점 i를 방문했을 경우, visited[i] = 1 */
int visited[MAX_VERTEX];

/* 방문한 정점의 수. 문제에서 1번 정점은 세지 않으므로, -1로 초기값을 설정 */
int visited_count = -1;

/* 정점의 수 */
int num_vertex;

void traverse_depth_first(int vertex)
{
    int i;

    visited[vertex] = 1;
    ++visited_count;

    for (i = 1; i <= num_vertex; ++i)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            traverse_depth_first(i);
        }
    }
}

int main(void)
{
    int i;
    int num_edges;

    scanf("%d", &num_vertex);
    scanf("%d", &num_edges);

    for (i = 0; i < num_edges; ++i)
    {
        int v1, v2;

        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    traverse_depth_first(1);

    printf("%d\n", visited_count);
    return 0;
}
