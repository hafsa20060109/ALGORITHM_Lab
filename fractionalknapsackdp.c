
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, capacity;
    scanf("%d", &n);
    scanf("%d", &capacity);

    int value[n], weight[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &value[i], &weight[i]);
    }

    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (weight[i - 1] <= w)
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum Value = %d\n", dp[n][capacity]);

    return 0;
}
