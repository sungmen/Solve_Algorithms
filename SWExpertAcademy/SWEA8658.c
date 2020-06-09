#include <stdio.h>

int sum_int(int n) 
{
    int temp = n % 10;
    int sum = temp;
    n /= 10;
    while (n != 0)
    {
        temp = n % 10;
        sum += temp;
        n /= 10;
    }

    return sum;
}

int main() 
{
    int test_case;
    scanf("%d", &test_case);

    for (int t = 1; t <= test_case; t++) 
    {
        int temp;
        scanf("%d", &temp);
        temp = sum_int(temp);
        int max = temp, min = temp;
        for (int i = 0; i < 9; i++) {
            scanf("%d", &temp);
            temp = sum_int(temp);
            max = max < temp ? temp : max;
            min = min > temp ? temp : min;
        }
        printf("#%d %d %d\n", t, max, min);
    }

    return 0;
}