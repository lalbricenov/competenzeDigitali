#include <stdio.h>
#include <stdlib.h>

typedef struct Cars{
    int price;
    int capacity;
} Car;
// void printCar(Car car)
// {
//     printf("Unit cost: %d Capacity: %d", car.price,car.capacity);
// }
// void printArrayOfCars(Car * cars, int size)
// {
//     for(int i = 0; i < size; i++)
//     {
//         printCar(cars[i]);
//         printf("\n");
//     }
// }
int comp (const void * elem1, const void * elem2)
{
    Car f = *((Car*)elem1); // The void pointer has to be casted to a real datatype
    Car s = *((Car*)elem2);// In this case it is dereferenced as well
    if (f.price > s.price) return  1;
    if (f.price < s.price) return -1;
    return 0;
}
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    // printf("Enter the number to factor: ");
    // N is the number of animals, M is the number of cars
    int N, M;
    scanf("%d %d",&N, &M);

    Car newCar;
    Car cars[M];
    for(int nCar = 0; nCar < M; nCar++)
    {
        scanf("%d", &newCar.price);
        scanf("%d", &newCar.capacity);
        cars[nCar] = newCar;
    }
    // printArrayOfCars(cars, M);
    qsort(cars, M, sizeof(Car), comp);
    // printArrayOfCars(cars, M);

    int remainingPassengers = N;
    int nCar = 0;
    int amountSpent = 0;
    while(remainingPassengers > 0)
    {
        if(remainingPassengers > cars[nCar].capacity)// Take the whole car
        {
            amountSpent += (cars[nCar].capacity*cars[nCar].price);
            remainingPassengers -= cars[nCar].capacity;
            nCar++;
        }else{//Take as much as needed
            amountSpent += (remainingPassengers*cars[nCar].price);
            remainingPassengers = 0;
            nCar++;
        }
    }
    printf("%d\n", amountSpent);

}