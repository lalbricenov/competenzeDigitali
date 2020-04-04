#include <stdio.h>
#include <stdlib.h>

// linked lists datatype
struct Node {
    int val;
    struct Node *next;
};
// This gives another name to  struct Node. Its new name is just Node
typedef struct Node Node;

void printLList(Node * numbers)
{
    Node * cur = numbers;
    while(cur != NULL)
    {
        printf("%d ", (*cur).val );
        cur = (*cur).next;
    }
    printf("\n");
}

void insertionSort( Node * numbers )
{
    // Keep part of the data sorted
    // Insert each element where it belongs in this sorted part of the data
    // Node * prev = NULL;
    Node * cur = numbers->next;
    Node * currentMax = numbers;
    Node * compareAgainst;
    while (cur != NULL)
    {
        // printf("Inserting %d: ", cur->val);
        // printLList(numbers);

        // cur is the element that will be inserted into its correct position
        
        // Comparing first against the smallest element
        compareAgainst = numbers;
        while(1)
        {
            // printf("Comparando %d con %d\n", cur->val, compareAgainst->val);
            if ( compareAgainst == numbers )
            {
                // Comparing against the first element, that is, the smallest one
                if (cur->val < compareAgainst->val)
                {
                    
                    int temp = numbers->val;
                    numbers->val = cur->val;
                    cur->val = temp;

                    if (numbers == currentMax)
                    {
                        currentMax = cur;
                        cur = cur->next;
                        break;
                    }
                    else
                    {
                        Node * tempNext = cur->next;
                        cur->next = numbers->next;
                        numbers->next = cur;
                        currentMax->next = tempNext;
                        cur = currentMax->next;
                        break;
                    }
                }

                else
                {
                    if (cur->val >= compareAgainst->val && cur->val <= (compareAgainst->next)->val)
                    {
                        currentMax->next = cur->next;
                        cur->next = compareAgainst->next;
                        compareAgainst->next = cur;
                        cur = currentMax->next;
                        break;
                    }
                    else
                    {
                        compareAgainst = compareAgainst->next;
                    }
                    
                }
            }
            else
            {
                if (compareAgainst == currentMax)
                { 
                    // This point will be reached if cur.val is larger than all the other elements that
                    // are already sorted
                    // In this case no action needs to be taken, just advance
                    currentMax = cur;
                    // compareAgainst->next = cur;
                    cur = cur->next;
                    break;
                }
                else
                {
                    // If the element we are comparing against is not the maximum
                    
                    // Compare the value of cur with the value of compareAgainst and with the value of next

                    // If it belongs in this position then put it there and finish the loop
                    if (cur->val >= compareAgainst->val && cur->val <= (compareAgainst->next)->val)
                    {
                        currentMax->next = cur->next;
                        cur->next = compareAgainst->next;
                        compareAgainst->next = cur;
                        cur = currentMax->next;
                        break;
                    }

                    // If it doesn't belong in this position, move to the next one
                    else
                    {
                        compareAgainst = compareAgainst->next;
                    }
                }
            }
            
        }
    }
    // printLList(numbers);
}



int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N;
    scanf("%d", &N); // Size of array
    
    Node * numsHead;
    Node * cur;
    for ( int n = 0; n < N; n++)
    {
        if ( n == 0 )
        {
            numsHead = malloc(sizeof(Node));
            scanf("%d ", &((*numsHead).val) );
            (*numsHead).next = NULL;
            cur = numsHead;
        }
        else
        {
            // Reserve space in memory for the new element
            // and assign its address to the current.next
            (*cur).next = malloc(sizeof(Node));

            // Make the next one become the current one
            cur = (*cur).next;
            // Store the value in the current one (new one)
            scanf("%d ", &((*cur).val) );
            // Make sure this last element doesn't point to anything
            (*cur).next = NULL;
        }
    }
    insertionSort(numsHead);
    printLList(numsHead);
}

// 7
// 50 4 10 -2 0 8 -1