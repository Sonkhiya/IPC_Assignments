#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int *arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
  
        if (swapped == false)
            break;
    }
}

void updates(int signaCode)
{
    FILE *fptr = fopen("./file.txt", "w");

    fprintf(fptr, "%d", signaCode);
    fclose(fptr);

    return;
}

int read()
{
    int signal;
    FILE *fptr = fopen("./file.txt", "r");
    fscanf(fptr, "%d", &signal);

    fclose(fptr);
    return signal;
}

void readFile(int *arr, int size)
{   
    int a = 0;
    FILE *fptr = fopen("./arr.txt", "r");

    while (!feof(fptr))
    {
        fscanf(fptr, "%d", arr + a);
        a++;
    }
    fclose(fptr);
}

void write(int size, int *arr)
{
    FILE *fptr = fopen("./arr.txt", "w");

    for (int i = 0; i < size; i++)
    {
        fprintf(fptr, "%d ", arr[i]);
    }

    fclose(fptr);
    return;
}

int main()
{
    updates(0);


    while (read() != 1)
    {
    }

    int size = 5;
    int* arr = (int*)malloc(sizeof(int) * size);
    readFile(arr, size);

    sort(arr, size);

    write(size, arr);
    
    updates(0);
}

