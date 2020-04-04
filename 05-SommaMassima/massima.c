#include <stdio.h>

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N;
    scanf("%d", &N); // Number of couples
    // a e b tra 0 e 999
    int max = -1;
    int a, b, sum;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        sum = a + b;
        if ( sum%2 == 0 && sum > max)
        {
            max = sum;
        }
    }
    
    printf("%d\n", max);
}