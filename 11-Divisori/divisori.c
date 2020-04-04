#include <stdio.h>
// #include <limits.h>
// #include <math.h>

#define N_PRIMOS 168

const int primos[N_PRIMOS] = {2,      3  ,    5   ,   7 ,    11  ,   13  ,   17 ,    19  ,   23  ,   29 ,
     31  ,   37  ,   41  ,   43   ,  47  ,   53  ,   59  ,   61 ,    67  ,   71,
     73  ,   79   ,  83  ,   89  ,   97  ,  101  ,  103  ,  107 ,   109  ,  113,
    127   , 131   , 137 ,   139 ,   149  ,  151  ,  157  ,  163 ,   167  ,  173,
    179  ,  181   , 191 ,   193  ,  197  ,  199  ,  211  ,  223 ,   227  ,  229,
    233  ,  239  ,  241 ,   251 ,   257  ,  263  ,  269  ,  271 ,   277  ,  281,
    283 ,   293  ,  307  ,  311  ,  313  ,  317  ,  331  ,  337 ,   347  ,  349,
    353  ,  359  ,  367  ,  373  ,  379  ,  383  ,  389  ,  397 ,   401  ,  409,
    419  ,  421  ,  431 ,   433  ,  439  ,  443  ,  449  ,  457 ,   461  ,  463 ,
    467  ,  479  ,  487  ,  491  ,  499  ,  503  ,  509  ,  521 ,   523  ,  541 ,
    547 ,   557  ,  563 ,   569  ,  571  ,  577  ,  587  ,  593 ,   599  ,  601 ,
    607 ,   613  ,  617  ,  619  ,  631  ,  641  ,  643  ,  647 ,   653  ,  659 ,
    661  ,  673  ,  677  ,  683  ,  691  ,  701  ,  709  ,  719 ,   727  ,  733 ,
    739  ,  743 ,   751  ,  757  ,  761  ,  769  ,  773  ,  787 ,   797  ,  809 ,
    811  ,  821 ,   823 ,   827  ,  829  ,  839  ,  853  ,  857 ,   859  ,  863 ,
    877 ,   881  ,  883 ,   887  ,  907  ,  911  ,  919  ,  929 ,   937  ,  941 ,
    947  ,  953 ,   967 ,   971  ,  977  ,  983  ,  991  ,  997};

// void primeFactorization(long n, int *primeExponents){
//     // Does not work for the number 1
//     int exponent, divisor;
//     for(int nPrimo = 0; nPrimo < N_PRIMOS; nPrimo++)
//     {
//         exponent = 0;
//         divisor = 1;
//         int primo = primos[nPrimo];
//         while(1)
//         {
//             divisor *= primo;
//             if(!(n%divisor))
//             {
//                 exponent++;
//                 continue;
//             }
//             break;
//         }
//         primeExponents[nPrimo] = exponent;
//     }
// }
// void printArray(int* array, int size)
// {
//     for(int i = 0; i < size; i++)
//     {
//         printf("%d ", array[i]);
//     }
//     printf("\n");
// }
// void printFactorization(int *exponents)
// {
//     // Does not work for the number 1
//     for(int i = 0;  i < N_PRIMOS; i++)
//     {
//         if(exponents[i]>0)
//         {
//             printf("%d^%d ", primos[i], exponents[i]);
//         }
//     }
//     printf("\n");
// }
int countDivisors(long n)
{
    int primeExponents[N_PRIMOS];
    int exponent, divisor;
    for(int nPrimo = 0; nPrimo < N_PRIMOS; nPrimo++)
    {
        exponent = 0;
        divisor = 1;
        // int primo = primos[nPrimo];
        while(1)
        {
            divisor *= primos[nPrimo];
            if(!(n%divisor))
            {
                exponent++;
                continue;
            }
            break;
        }
        primeExponents[nPrimo] = exponent;
    }
    // Does not work for the number 1
    int count = 1;
    for (int nPrime = 0; nPrime < N_PRIMOS; nPrime++)
    {
        if(primeExponents[nPrime] > 0)
        {
            count *= (primeExponents[nPrime] + 1);
        }
    }
    return count;
}

int main(void)
{
    // Para contar el número de divisores primero encuentro la factorización prima y luego multiplico los exponentes
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    // printf("Enter the number to factor: ");
    long n;
    scanf("%ld",&n);
    if(n == 1)
    {
        printf("1\n");
        return 0;
    }
    // n is not 1
    // int primeExponents[N_PRIMOS];
    // for(int i = 0; i < N_PRIMOS; i++)
    // {
    //     primeExponents[i] = 0;
    // }
    // primeFactorization(n, primeExponents);

    // printArray(primeExponents, N_PRIMOS);
    // printFactorization(primeExponents);
    printf("%d\n", countDivisors(n) );
}