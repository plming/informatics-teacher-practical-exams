/**
 * 부산3. 0/1 배낭 문제
 * 참고: 백준 12865번, https://www.acmicpc.net/problem/12865
 */
#include <stdio.h>
#include <math.h>

#define MAX_NUM_ITEMS (100)
#define MAX_WEIGHT (100001)

/* 크기가 커서 전역변수로 선언 */
int price[MAX_NUM_ITEMS][MAX_WEIGHT];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int current_item, weight;
    int num_items;
    int max_weight;

    /* items[i][0]은 무게, items[i][1]은 가격 */
    int items[MAX_NUM_ITEMS][2];

    scanf("%d %d", &num_items, &max_weight);

    for (current_item = 0; current_item < num_items; ++current_item)
    {
        scanf("%d %d", &items[current_item][0], &items[current_item][1]);
    }

    for (current_item = 0; current_item < num_items; ++current_item)
    {
        for (weight = 0; weight <= max_weight; ++weight)
        {
            /* 현재 무게가 물건을 넣을 수 있는 무게면 1, 아니면 0 */
            int can_contain_item = weight >= items[current_item][0];

            if (current_item == 0)
            {
                price[current_item][weight] = can_contain_item ? items[current_item][1] : 0;
            }
            else if (can_contain_item)
            {
                int price_without_item = price[current_item - 1][weight];
                int price_with_item = price[current_item - 1][weight - items[current_item][0]] + items[current_item][1];

                price[current_item][weight] = max(price_without_item, price_with_item);
            }
            else
            {
                price[current_item][weight] = price[current_item - 1][weight];
            }
        }
    }

    printf("%d\n", price[num_items - 1][max_weight]);
    return 0;
}
