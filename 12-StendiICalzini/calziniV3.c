#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
// N is the number of socks, C is the number of colors
int N, C;

typedef struct Colors{
    int color;
    int arrivalPos;
} Color;
void printColorAndPos(Color color)
{
    printf("Color: %d Position: %d", color.color, color.arrivalPos);
}

int hash(int color)
{
    // The size is the smallest between N and C
    return color%(N<C?N:C);
}

// Linked list
typedef struct Nodes {
    Color data;
    struct Nodes* next;
} Node;

void printLinkedList(Node* head)
{
    Node* current = head;
    while(1)
    {
        printf("DATA: ");
        printColorAndPos(current->data);
        printf("\tNEXT: %p\n", current->next);
        if(current->next == NULL) break;
        current = current->next;
    }
}
Node* addElementToList(Node* head, Color newColor)
{
    // The default value for color is -1
    if((head->data.color) == -1)// If the list is empty
    {
        // Simply write the data in the head
        head->data = newColor;
    }
    else
    {
        // If the list is not empty, add a new node
        Node *newHead = malloc(sizeof(Node));
        newHead->next = head;
        newHead->data = newColor;
        head = newHead;
    }
    return head;
}
///////////////////////////////////
int hashTableLookup(Node**hashTable, int color)//The color number is the key, the return value is the position of arrival
{
    Node *current = hashTable[hash(color)];//This is a linked list
    while(1)
    {
        if((current->data).color == color )
            return (current->data).arrivalPos;
        // printf("\tNEXT: %p\n", current->next);
        if(current->next == NULL) break;
        current = current->next;
    }
    return -1;
}
int hashTableInsert(Node**hashTable, int color, int posArrival)
{
    // RETURNS TRUE if the element did not exist, and was added.
    // RETURNS FALSE if the element was alredy  present

    // Get the linked list that corresponds to this hash
    Node *head = hashTable[hash(color)];//This is a linked list
    Node *current = head;
    // Check if the color is already in the list
     while(1)
    {
        if((current->data).color == color )
        {
            // If the color is already here, nothing needs to be done
            return FALSE;
        }
        // printf("\tNEXT: %p\n", current->next);
        if(current->next == NULL) break;
        current = current->next;
    }
    // If we get to this point it is because the color was not found
    Color newColor;
    newColor.color = color;
    newColor.arrivalPos = posArrival;
    hashTable[hash(color)]  = addElementToList(head, newColor);// This function returns the new head
    return TRUE;
}
void printHashTable(Node** hashTable, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Bucket %d:\n", i);
        printLinkedList(hashTable[i]);
        printf("\n");
    }
}
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // N is the number of socks, C is the number of colors
    scanf("%d %d",&N, &C);

    long numExchanges = 0;
    int numColorsArrived = 0;//Number of unique colors that have arrived
    int color;

    int numBuckets = N<C?N:C;
    Node* posOfArrival[numBuckets];// N sockets. Array of linked lists, this is the place where data will be stored using the hash function
    // We need to initialize each of the list to a list with one element that has as color value -1
    Node *head;
    Color defaultColor;
    defaultColor.color = -1;
    defaultColor.arrivalPos = -1;

    for(int i = 0; i < numBuckets; i++)
    {
        head = malloc(sizeof(Node));

        head->data = defaultColor;
        head->next = NULL;

        posOfArrival[i] = head;
    }
    for (int nSock = 0; nSock < N; nSock++)
    {

        // printHashTable(posOfArrival, numBuckets);
        scanf("%d", &color);
        int posArrival = hashTableLookup(posOfArrival, color);

        if(posArrival == -1)// If the color was not there yet
        {
            hashTableInsert(posOfArrival, color, numColorsArrived);// This function inserts the color, if it was already
            // there, returns false.

            numExchanges += numColorsArrived;// The number of exchanges for each color is its position of arrival
            numColorsArrived++;
        }
        else
        {
            numExchanges += posArrival;// The number of exchanges for each color is its position of arrival
        }
        // printf("\n");
    }
    printf("%ld\n", numExchanges);
}