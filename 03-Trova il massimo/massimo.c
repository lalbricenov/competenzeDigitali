#include <stdio.h>

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    // It is known that the numbers are between -999 and 999
    int max = -1000;
    int n;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n);
        if( n > max) max = n;
    }
    printf("%d\n", max);
}