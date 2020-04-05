#include <stdio.h>
#include <stdlib.h>
void quickSort(int * array, int N)
{
    for (int n = 0; n < N; n++)
    {
        printf("%d ", array[n]);
    }
    if(N>2)
    {
        if(N%2 == 0)
        {
            quickSort(array, N/2);
            quickSort((array+N/2), N/2);
        }else
        {
            quickSort(array, N/2);
            quickSort((array + N/2), N/2 + 1);
        }
    }
    else
    {
        if(N==2)
        {
            if (array[0] > array[1])
            {
                int temp = array[0];
                array[0] = array[1];
                array[1] = temp;
            }
        }
    }

}

int main(void)
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N); // Size of array
    int matrix[N];
    for (int n = 0; n < N; n++)
    {
        scanf("%d ", &matrix[n]);
    }

    quickSort(matrix, N);

    for (int n = 0; n < N; n++)
    {
        printf("%d ", matrix[n]);
    }
}