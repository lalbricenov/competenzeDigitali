#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
// #include <time.h>


void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int* array1, int* array2, int size1, int size2, int *mergedArray)
{
    int leftPos = 0;
    int rightPos = 0;
    int newPos = 0;
    while(1)
    {
        if(leftPos == size1)// If we reached the end of the array on the left
        {
            // Copy the remaining elements in the array on the right
            for(int j = rightPos; j < size2; j++)
            {
                mergedArray[newPos] = array2[rightPos];
                newPos++;
                rightPos++;
            }
            break;
        }
        if(rightPos == size2)// If we reached the end of the array on the right
        {
            // Copy the remaining elements in the array on the left
            for(int j = leftPos; j < size1; j++)
            {
                mergedArray[newPos] = array1[leftPos];
                newPos++;
                leftPos++;
            }
            break;
        }

        if(array1[leftPos] < array2[rightPos])
        {
            mergedArray[newPos] = array1[leftPos];
            leftPos++;
        }else
        {
            mergedArray[newPos] = array2[rightPos];
            rightPos++;
        }
        newPos++;
    }
}
int * mergeSort(int *array, int N)
{

    int *sorted = malloc(N*sizeof(int));
    int sizeL = N/2;
    int sizeR = N - sizeL;
    if(N >= 2)
    {
        int *leftArray;
        int *rightArray;
    // Order each part using mergeSort
        leftArray = mergeSort(array, sizeL);
        rightArray = mergeSort((array+sizeL), sizeR);

        // printf("Size N: %d\n", N);
        // printf("Left Ordered: ");
        // printArray(leftArray, sizeL);
        // printf("Right Ordered: ");
        // printArray(rightArray, sizeR);

    // Merge the two parts
        merge(leftArray, rightArray, sizeL, sizeR, sorted);

        free(leftArray);
        free(rightArray);
        // printf("Merged: ");

        // array = sorted;
        // printArray(sorted, N);
    }
    else
    {
    // If the array only has one element, nothing needs to be done
        sorted[0] = array[0];
    }
    return sorted;


}
int main(void)
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // time_t t;


    // /* Intializes random number generator */
    // srand((unsigned) time(&t));
    // int N;
    // scanf("%d", &N); // Size of array
    // for (int n = 0; n < N; n++)
    // {
    //     matrix[n] = rand()%100;
    // }
    // int matrix1[N];
    // int matrix2[N+2];
    // int newValue1 = rand()%10 * pow(-1,rand()%2);
    // int newValue2 = rand()%10 * pow(-1,rand()%2);
    // for (int n = 0; n < N; n++)
    // {
    //     matrix1[n] = newValue1;
    //     newValue1 += rand()%10;
    //     matrix2[n] = newValue2;
    //     newValue2 += rand()%10;
    // }
    // matrix2[N] = newValue2;
    // matrix2[N + 1] = newValue2;
    // int merged[N + N + 2];
    // merge(matrix2, matrix1, N+2, N, merged);
    // printArray(matrix1, N);
    // printArray(matrix2, N + 2);
    // printArray(merged, 2 * N + 2);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N); // Size of array
    int matrix[N];
    for (int n = 0; n < N; n++)
    {
        scanf("%d ", &matrix[n]);
    }

    int *ordered = mergeSort(matrix, N);
    printArray(ordered, N);
    free(ordered);
}