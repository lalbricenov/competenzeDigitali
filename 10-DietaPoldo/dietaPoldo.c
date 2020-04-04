#include <stdio.h>

// typedef struct ItemValuePair{
//     int itemNumber;
//     int value;
// } ItemValuePair;

int value(int itemNumber, int weights[], int m, int *values)// m is the size of the array weights. values is the array with the values already calculated
{
    // Function that determines the maximum number of menu items that can be eaten after taking this one + 1 for taking this one
    if (itemNumber == m - 1)
    {// If this is the last item in the list
        return 1;
    }
    else
    {
        if(values[itemNumber] != -1)//If the value of this item was already calculated
        {
            return values[itemNumber];
        }
        else
        {
            int maxValue = 1;
            for(int i = itemNumber + 1; i < m; i++)
            {
                if (weights[i] < weights[itemNumber])
                {
                    int valueNext = value(i, weights, m, values);
                    // printf("Current: %d, next: %d valueNext: %d\n", itemNumber, i, valueNext);
                    if (valueNext + 1 > maxValue)
                    {
                        maxValue = 1 + valueNext;
                    }
                }
            }
            values[itemNumber] = maxValue;
            return maxValue;
        }
    }

}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m;//number of items in the menu

    scanf("%d", &m);
    int weights[m];
    int values[m];// The value of taking an item on the menu. This will be used to store the values calculated in order to reduce recalculations

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &(weights[i]));
        values[i] = -1;
        // printf("%d", weights[i]);
    }
    int maxValue = 1;
    for(int i=0; i < m; i++)
    {
        int val = value(i, weights, m, values);
        if (val > maxValue)
        {
            maxValue = val;
        }
        // printf("Value of taking %d: %d\n", i, value(i, weights, m));// value of taking the first item
    }
    printf("%d", maxValue);
}