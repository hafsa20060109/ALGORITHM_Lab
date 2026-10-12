
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    int s[n], f[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &s[i], &f[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (f[i] > f[j])
            {
                int temp = f[i];
                f[i] = f[j];
                f[j] = temp;

                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    int last = 0;

    printf("Selected activities: ");
    printf("(%d,%d) ", s[last], f[last]);

    for (int i = 1; i < n; i++)
    {
        if (s[i] >= f[last])
        {
            printf("(%d,%d) ", s[i], f[i]);
            last = i;
        }
    }

    return 0;
}
