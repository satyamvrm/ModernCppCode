#include <stdio.h>
#include <malloc.h>

void update(int **arr)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] *= 10;
        }
    }
}

void display(int **arr)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int count = 1;
    int **arr = (int **)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        arr[i] = (int *)malloc(3 * sizeof(int));
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = count++;
        }
    }
    display(arr);
    update(arr);
    display(arr);
}