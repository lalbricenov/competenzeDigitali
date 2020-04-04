#include <stdio.h>

int positionOfArrivalOfColor(int color, int * colorOfPositionN, int n)
{
    for(int pos = 0; pos < n; pos++ )
    {
        if(colorOfPositionN[pos] == color)
        {
            return pos;//If the color is found
        }
    }
    return -1;// If it is not in the list yet
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    // printf("Enter the number to factor: ");
    // N is the number of socks, C is the number of colors
    int N, C;
    scanf("%d %d",&N, &C);
    int colorOfPositionN[N];

    // if a sock of the same color has already arrived, it is ignored.
    for (int pos = 0; pos < N; pos++)
    {
        colorOfPositionN[pos] = -1;// -1 means that there isn't any color in that position yet
    }
    int numExchanges = 0;
    int numColorsArrived = 0;//Number of unique colors that have arrived
    int color, positionOfColor;
    for (int nSock = 0; nSock < N; nSock++)
    {
        scanf("%d", &color);
        positionOfColor = positionOfArrivalOfColor(color, colorOfPositionN, numColorsArrived);
        if(positionOfColor != -1) // If the color has already been seen
        {
            numExchanges += positionOfColor;// The number of exchanges for each color is its position of arrival
            continue;
        }
        colorOfPositionN[numColorsArrived] = color;
        numExchanges += numColorsArrived;
        numColorsArrived++;
    }
    printf("%d\n", numExchanges);
}