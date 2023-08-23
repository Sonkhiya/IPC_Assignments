#include <stdio.h>
#include <stdlib.h>

void input(int *a, int *b)
{
    scanf("%d", a);

    for (int i = 0; i < *a; i++)
    {
        scanf("%d", b + i);
    }
    return;
}


void updates(int a)
{
    FILE *fptr = fopen("./file.txt", "w");

    fprintf(fptr, "%d", a);
    fclose(fptr);

    return;
}

void write(int a, int *arr)
{
    FILE *fptr = fopen("./arr.txt", "w");

    // writing in file.....
    for (int i = 0; i < a; i++)
    {
        fprintf(fptr, "%d ", arr[i]);
    }

    fclose(fptr);
    return;
}

int read()
{
    int a;
    FILE *fptr = fopen("./file.txt", "r");
    fscanf(fptr, "%d", &a);

    fclose(fptr);
    return a;
}




void printarr()
{   
    int a;
    FILE *fptr = fopen("./arr.txt", "r");

    while (!feof(fptr))
    {
        fscanf(fptr, "%d ", &a);
        printf("%d ", a);
    }
    fclose(fptr);
    return;
}



int main()
{
    updates(0);

    int a;
    int *ar = (int *)malloc(sizeof(int) * a);

    input(&a, ar);

    write(a, ar);
    updates(1);

    while (read() != 0)
    {
        
    }

    printf("Output : ");
    printarr();
    printf("\n");
}
