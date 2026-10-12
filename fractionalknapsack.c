
#include <stdio.h>

int main()
{
    int n;
    float capacity, totalValue = 0;

    scanf("%d", &n);
    scanf("%f", &capacity);

    float value[n], weight[n], ratio[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &value[i], &weight[i]);
        ratio[i] = value[i] / weight[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = value[i];
                value[i] = value[j];
                value[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (capacity >= weight[i])
        {
            totalValue += value[i];
            capacity -= weight[i];
        }
        else
        {
            totalValue += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum Value = %.2f\n", totalValue);

    return 0;
}
