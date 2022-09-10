/* 递归 - 计算 n! */

#include <stdio.h>

int Factorial(int n);

int main(int argc, char const *argv[])
{
    int n = 3;
    printf("%d! = %d\n", n, Factorial(n));
    return 0;
}


int Factorial(int n)
{
    if (0 == n)
    {
        return 1;
    }
    else
    {
        return n * Factorial(n - 1);
    }
}
