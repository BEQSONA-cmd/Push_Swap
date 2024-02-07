#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int different(int num, int *arr, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] == num) {
            return 0;
        }
    }
    return 1;
}

int main(void) 
{
    srand(time(NULL));

    int n[101];
    int i = 0;

    while (i < 101) 
    {
        int num = rand() % 101 - 50;
        if (different(num, n, i)) 
        {
            n[i] = num;
            i++;
        }
    }

    for (int i = 0; i < 101; ++i) 
    {
        if(i == 100)
        {
            printf("%d\n", n[i]);
            return(0);
        }
        printf("%d, ", n[i]);
    }

    printf("\n");
    return 0;
}
