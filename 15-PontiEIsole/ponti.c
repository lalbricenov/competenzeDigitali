#include <stdio.h>
#include <assert.h>

#define MAXM 100000

int costruisci(int N, int M, int da[], int a[]) {
    // Mettete qui il codice della soluzione
    int grupo[N]; // Group where each island belongs
    int nGrupos = N; // Without any bridges, the number of groups is equal to the number of islands
    for (int i = 0; i < N; i++)
    {
        grupo[i] = i;
    }
    for (int nPuente = 0; nPuente < M; nPuente++)
    {
        // Check if this bridge connects two islands in the same group
        // If it does, then there is nothing to be done
        int grupoA = grupo[a[nPuente]];
        int grupoDA = grupo[da[nPuente]];
        if( !(grupoDA == grupoA) )
        {
            // If it doesn't, find all the elements on both groups, and set their group number to
            // the smallest of the two groups of the two islands connected with the bridge
            int smallest = grupoDA < grupoA? grupoDA:grupoA;
            for (int nIsland = 0; nIsland < N; nIsland++)
            {
                if(grupo[nIsland] == grupoDA || grupo[nIsland] == grupoA)
                {
                    // If the island belongs to one of the two groups
                    grupo[nIsland] = smallest; // set its group number to the smallest of the two
                }
            }
            // Decrease the number of groups by one
            nGrupos--;
        }

    }

    return nGrupos - 1;
}


int da[MAXM], a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &da[i], &a[i]));

    fprintf(fw, "%d\n", costruisci(N, M, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
