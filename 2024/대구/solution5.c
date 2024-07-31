/**
 * 대구5. 너비 우선 탐색(BFS)
 * 주어진 그래프에 대해 깊이 BFS를 수행한 결과를 출력하는 프로그램을 작성하시오.
 * {
 * {0, 1, 0, 0, 1, 0, 0},
 * {1, 0, 1, 0, 1, 0, 0},
 * {0, 1, 0, 0, 0, 0, 0},
 * {0, 0, 0, 0, 0, 0, 1},
 * {1, 1, 0, 0, 0, 1, 0},
 * {0, 0, 0, 0, 1, 0, 1},
 * {0, 0, 0, 1, 0, 1, 0},
 * }
 *
 * 단, 알고리즘에서 쓰이는 큐(Queue)는 원형 큐(Circular Queue)를 사용합니다.
 *
 * 입력: 없음
 * 출력: 0 1 4 2 5 6 3
 */
#include <stdio.h>

#define NUM_VERTEX (7)

int queue[NUM_VERTEX];
int front = 0;
int rear = 0;

void enqueue(int data)
{
    queue[rear] = data;
    rear = (rear + 1) % NUM_VERTEX;
}

int dequeue(void)
{
    int data = queue[front];
    front = (front + 1) % NUM_VERTEX;
    return data;
}

int is_empty(void)
{
    return front == rear;
}

int main(void)
{
    int i;
    int graph[NUM_VERTEX][NUM_VERTEX] = {
        {0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 1, 0},
    };
    int visited[NUM_VERTEX] = { 0, };

    enqueue(0);
    visited[0] = 1;

    while (!is_empty())
    {
        int vertex = dequeue();

        printf("%d ", vertex);

        for (i = 0; i < NUM_VERTEX; ++i)
        {
            if (graph[vertex][i] && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
    return 0;
}
