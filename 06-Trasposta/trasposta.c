#include <stdio.h>

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N, M;
    scanf("%d %d", &N, &M); // Size of matrix
    int matrix[N][M];
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            scanf("%d ", &matrix[n][m]);
        }
    }
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            printf("%d ", matrix[n][m]);
        }
        printf("\n");
    }
}