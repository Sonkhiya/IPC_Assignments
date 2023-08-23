#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void swap(int *x, int *y)
  {
    int temp = *x;
    *x = *y;
    *y = temp;
  }
 
void sort(int arr[], int n)
{
    int i, j, min_idx;
 
    
    for (i = 0; i < n-1; i++)
    {
        
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int main(void){
  int n;

  int l = open("len",O_RDONLY);
  if (read(l, &n, sizeof(int))== -1){
                return 1;
            }
  int arr[n];
  
  int p = open("sort", O_RDONLY);
  
  for (int i=0; i<n; i++){
            if (read(p, &arr[i], sizeof(int))== -1){
                        return 1;
            }
            
  }
  
  close(p);
  
  

  sort(arr,n);
  
  
  int p1 = open("sort", O_WRONLY);
  
  for (int i=0; i<n; i++){
            if (write(p1, &arr[i], sizeof(int)) == -1){
            }
            
  }
  
  close(p1);
  
  
  return 0;
}