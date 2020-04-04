#include <stdio.h>

int next(int cur, int tunnels[][3], int M)// first dimension is optional, but the second one is required
{// N is the number of tunnels
// return the number of the next node. If there isn't any connection to the current node returns the current node
    int tunnelTaken = -1;
    int smallestLum = M + 1;
    for (int i=0; i<M; i++)
    {
        if((tunnels[i][0] == cur || tunnels[i][1] == cur) && tunnels[i][2] < smallestLum)
        {
            tunnelTaken = i;
            smallestLum = tunnels[tunnelTaken][2];
        }
    }
    if(tunnelTaken == -1)// If there is not even one tunnel conected to the room where H is
        return cur;// return the current node without modification
    else
    {
        if ( tunnels[tunnelTaken][1] == cur) return tunnels[tunnelTaken][0];
        else return tunnels[tunnelTaken][1];
    }


}


int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // N is the number of rooms
    // M is the number of tunnels
    // H is the starting position of Harmony
    // S is the position of Spike
    int N, M, H, S;
    scanf("%d %d %d %d", &N, &M, &H, &S);

    int tunnels[M][3];
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &(tunnels[i][0]), &(tunnels[i][1]), &(tunnels[i][2]));
    }

    // This array stores a 1 if the node was already visited, otherwise it stores a 0
    int visited[N+1];
    for(int i = 0; i < N+1; i++)
    {
        visited[i] = 0;
    }

    int cur = H;
    int prev;
    int nSteps = 0;
    while(cur != S)
    {   prev = cur;
        cur = next(cur, tunnels, M);
        if(cur != prev)
        {
            nSteps++;
            if(visited[cur] == 1)
            {
                nSteps = -1;
                break;
            }
            visited[cur] = 1;
        }else
        {
            nSteps = -1;
            break;
        }
    }
    printf("%d", nSteps);


}