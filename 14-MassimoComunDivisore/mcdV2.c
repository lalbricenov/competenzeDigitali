#include <stdio.h>
#include <stdlib.h>

// gcd using euclidean algorithm


int gcd(int a, int b)
{
    if(a == b) return a;
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }

    int r0 = a % b;
    if (r0 == 0) return b;

    // int q0 = a / b;
    // int q1 = b / r0;
    int r1 = b % r0;

    if(r1 == 0) return r0;

    int rNm2 = r0;// r sub k-2
    int rNm1 = r1;// r sub k - 1
    int rN;
    while(1)
    {
        rN = rNm2 % rNm1;
        if(rN == 0)
        {
            return rNm1;
        }
        else
        {
            rNm2 = rNm1;
            rNm1 = rN;
        }
    }
    // return -1; // If there
}
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    // // printf("Enter the number to factor: ");
    int n, m;
    scanf("%d %d",&n, &m);
    printf("%d\n", gcd(n, m));
}