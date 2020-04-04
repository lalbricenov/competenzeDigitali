#include <stdio.h>

int cache[46];// results of the fibonacci sequence from 0 to 45

int fib(int n)
{
    // If the value was already calculated return it inmediately
    if ( cache[n] != -1) return cache[n];
    else
    {
        // If it has not been already calculated, calculate it and save it in cache before returning it
        if (n == 0) 
        {
            cache[n] = 0;
            return 0;
        }
        if (n == 1) 
        {
            cache[n] = 1;
            return 1;
        }
        else
        {
            cache[n] = fib(n-1) + fib(n-2);
            return cache[n];            
        }
    }
    
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    // Initialization of cache to -1
    for (int i = 0; i < 46; i++) cache[i] = -1;
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
}