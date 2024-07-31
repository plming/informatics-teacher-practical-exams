/**
 * 대구6. 라운드 로빈 스케줄러
 * 참고: 백준 12016번, https://www.acmicpc.net/problem/12016
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_TASKS (100000)

struct task
{
    int id;
    long long duration;
};

/* 작업의 수행시간, 작업의 번호 순으로 정렬하기 위한 비교 함수 */
int compare_task(const void *a, const void *b)
{
    struct task *task_a = (struct task *)a;
    struct task *task_b = (struct task *)b;

    if (task_a->duration != task_b->duration)
    {
        return task_a->duration - task_b->duration;
    }
    else
    {
        return task_a->id - task_b->id;
    }
}

/* 구간 내 완료된 작업의 갯수를 저장하는 세그먼트 트리 */
int segment_tree[MAX_NUM_TASKS * 4];

int count_finished_tasks(int node, int node_left, int node_right, int query_left, int query_right)
{
    if (node_right < query_left || query_right < node_left)
    {
        return 0;
    }
    else if (query_left <= node_left && node_right <= query_right)
    {
        return segment_tree[node];
    }
    else
    {
        int mid = (node_left + node_right) / 2;
        return count_finished_tasks(node * 2, node_left, mid, query_left, query_right) +
               count_finished_tasks(node * 2 + 1, mid + 1, node_right, query_left, query_right);
    }
}

void update_segment_tree(int node, int node_left, int node_right, int index, int value)
{
    if (index < node_left || node_right < index)
    {
        return;
    }
    else if (node_left == node_right)
    {
        segment_tree[node] = value;
    }
    else
    {
        int mid = (node_left + node_right) / 2;
        update_segment_tree(node * 2, node_left, mid, index, value);
        update_segment_tree(node * 2 + 1, mid + 1, node_right, index, value);
        segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
    }
}

int main(void)
{
    int i, j;
    int num_tasks;
    struct task tasks[MAX_NUM_TASKS];
    long long end_time[MAX_NUM_TASKS];

    long long time_sum_finished_tasks = 0;

    scanf("%d", &num_tasks);

    for (i = 0; i < num_tasks; ++i)
    {
        scanf("%lld", &tasks[i].duration);
        tasks[i].id = i;
    }

    qsort(tasks, num_tasks, sizeof(struct task), compare_task);

    for (i = 0; i < num_tasks; ++i)
    {
        long long finish_time = 0;
        int num_unfinished_tasks_before = tasks[i].id - count_finished_tasks(1, 0, num_tasks - 1, 0, tasks[i].id - 1);
        int num_unfinished_tasks_after = num_tasks - tasks[i].id - 1 - count_finished_tasks(1, 0, num_tasks - 1, tasks[i].id + 1, num_tasks - 1);

        finish_time += time_sum_finished_tasks;
        finish_time += tasks[i].duration;
        finish_time += num_unfinished_tasks_before * tasks[i].duration;
        finish_time += num_unfinished_tasks_after * (tasks[i].duration - 1);

        update_segment_tree(1, 0, num_tasks - 1, tasks[i].id, 1);
        end_time[tasks[i].id] = finish_time;
        time_sum_finished_tasks += tasks[i].duration;
    }

    for (i = 0; i < num_tasks; ++i)
    {
        printf("%lld\n", end_time[i]);
    }
    return 0;
}
