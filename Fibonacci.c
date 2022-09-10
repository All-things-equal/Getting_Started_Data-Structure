/* 斐波那契数列 */
/* Fibonacci.c - 打印兔子数列的前40项 */

#include <stdio.h>

int Fibonacci(int num);

int main(int argc, char const *argv[])
{
    int fbi[41];
    int i = 0;

    printf("迭代:\n");
    fbi[0] = 0;
    fbi[1] = 1;
    printf("fbi[1] = %d\t", fbi[1]);

    for (i = 2; i < 41; i++)
    {
        fbi[i] = fbi[i - 1] + fbi[i - 2];
        printf("fbi[%d] = %d\t", i, fbi[i]);
        if (i % 3 == 0)
        {
            printf("\n");
        }
    }
    printf("\n\n");

    printf("递归:\n");
    for (i = 1; i < 41; i++)
    {
        printf("fbi[%d] = %d\t", i, Fibonacci(i));
        if (i % 3 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}

int Fibonacci(int num)
{
    if (num < 2)
    {
        return num == 0 ? 0 : 1;
    }
    return Fibonacci(num - 1) + Fibonacci(num - 2);
}
