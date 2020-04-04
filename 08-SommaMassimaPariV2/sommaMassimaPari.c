#include <stdio.h>

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N); // Number of numbers

    // Keep track of the largest and the second largest.
    int maxPar = -1;
    int maxImpar = -1;
    int secPar = -1;
    int secImpar = -1;
    int nums[N];
    int sommaPari, sommaDispari;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
        if(nums[i] % 2 == 0)
        {
            if(nums[i] > maxPar)
            {
                secPar = maxPar;
                maxPar = nums[i];
            }else if( nums[i] > secPar)
            {
                secPar = nums[i];
            }
        }
        else
        {
            if(nums[i] > maxImpar)
            {
                secImpar = maxImpar;
                maxImpar = nums[i];
            }else if( nums[i] > secImpar)
            {
                secImpar = nums[i];
            }
        }
    }
    if(maxPar != -1 && secPar != -1)
        sommaPari = maxPar + secPar;
    else
        sommaPari = -1;

    if(maxImpar != -1 && secImpar != -1)
        sommaDispari = maxImpar + secImpar;
    else
        sommaDispari = -1;

    if(sommaPari >= sommaDispari)
    {
        printf("%d", sommaPari);
    }else
    {
        printf("%d", sommaDispari);
    }
}