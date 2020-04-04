#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int * array, int N)
{
    // Compare the first two items, move the largest one to the right
    // Compare the next two, until the end
    // Go back to step one, but repeat only until the size - numberOfTimesRepeated

    int temp;
    for (int nReps = 0; nReps < N; nReps++)
    {
        for (int n = 0; n < N - 1 - nReps; n++)
        {
            if ( array[n] > array[n + 1])
            {
                temp = array[n];
                array[n] = array[n + 1];
                array[n + 1] = temp;
            }
        }
    }
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N); // Size of array
    int matrix[N];
    for (int n = 0; n < N; n++)
    {
        scanf("%d ", &matrix[n]);
    }

    bubbleSort(matrix, N);

    for (int n = 0; n < N; n++)
    {
        printf("%d ", matrix[n]);
    }
}