#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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

void updates(int a)
{
    FILE *fptr = fopen("./file.txt", "w");

    fprintf(fptr, "%d", a);
    fclose(fptr);

    return;
}

int read()
{
    int s;
    FILE *fptr = fopen("./file.txt", "r");
    fscanf(fptr, "%d", &s);

    fclose(fptr);
    return s;
}

void readFile(int *arr, int l)
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

void write(int l, int *arr)
{
    FILE *fptr = fopen("./arr.txt", "w");

    for (int i = 0; i < l; i++)
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

    int l = 5;
    int* arr = (int*)malloc(sizeof(int) * l);
    readFile(arr, l);

    sort(arr, l);

    write(l, arr);
    
    updates(0);
}

