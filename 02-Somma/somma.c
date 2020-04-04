#include <stdio.h>

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unsigned long a, b;
    scanf("%lu", &a);
    scanf("%lu", &b);
    printf("%lu\n", a + b);
}