#include <stdio.h>

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    // printf("Enter the number to factor: ");
    // N is the number of socks, C is the number of colors
    int N, C;
    scanf("%d %d",&N, &C);
    int posOfArrival[C];// The position in which a color arrives, if it is the first one to arrive, then its position is zero
    // if a sock of the same color has already arrived, it is ignored.
    for (int nColor = 0; nColor < C; nColor++)
    {
        posOfArrival[nColor] = -1;// -1 means that it has not arrived yet
    }
    int numExchanges = 0;
    int numColorsArrived = 0;//Number of unique colors that have arrived
    int color;
    for (int nSock = 0; nSock < N; nSock++)
    {
        scanf("%d", &color);
        if(posOfArrival[color] == -1) // If this color has not been seen
        {
            posOfArrival[color] = numColorsArrived;
            numColorsArrived++;
        }
        numExchanges += posOfArrival[color];// The number of exchanges for each color is its position of arrival
    }
    printf("%d\n", numExchanges);
}