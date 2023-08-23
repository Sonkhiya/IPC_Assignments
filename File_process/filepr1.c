#include <stdio.h>
#include <stdlib.h>

void input(int *s, int *a)
{
    scanf("%d", s);

    for (int i = 0; i < *s; i++)
    {
        scanf("%d", a + i);
    }
    return;
}

void write(int s, int *arr)
{
    FILE *fptr = fopen("./arr.txt", "w");

    // writing in file.....
    for (int i = 0; i < s; i++)
    {
        fprintf(fptr, "%d ", arr[i]);
    }

    fclose(fptr);
    return;
}

void update1(int signaCode)
{
    FILE *fptr = fopen("./file.txt", "w");

    fprintf(fptr, "%d", signaCode);
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
    update1(0);

    int a;
    int *ar = (int *)malloc(sizeof(int) * a);

    input(&a, ar); // takes input in inpSize and inpArr.....

    write(a, ar);
    update1(1);

    while (read() != 0)
    {
        
    }

    printf("Output : ");
    printarr();
    printf("\n");
}