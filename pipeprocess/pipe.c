#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void){

  if (mkfifo("len",0777) == -1){
      printf("error in creating fifo file");
            return 1;
  }
  if (mkfifo("sort", 0777) == -1){
      printf("error in creating fifo file");
      return 1;
  }
  
  int n = 0;
  scanf("%d",&n);

  int arr[n];
  
  printf("Enter");
  for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
  }
  
  int l = open("len",O_WRONLY);
  if (write(l, &n, sizeof(int)) == -1){
        printf("error in writing");

  }
  int p = open("sort", O_WRONLY);
  
  for (int i=0; i<n; i++){
            if (write(p, &arr[i], sizeof(int)) == -1){
                        printf("error in writing");
            }
  }
  close(l);
  close(p);
  
  int p1 = open("sort", O_RDONLY);
  
  int SortedArr[n];
  
  for (int i=0; i<n; i++){
            if (read(p1, &SortedArr[i], sizeof(int))== -1){
                        printf("error in reading from file");
                        return 1;
            }
            printf("Sorted array : %d\n", SortedArr[i]);
  }
  
  
  
  close(p1);

  return 0;

}