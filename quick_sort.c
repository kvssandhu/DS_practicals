// 22 : To implement quick sort using array
// 8th November 2019



#include<stdio.h>

int main(){
    int array[20], N, i;

    printf("\n Karanveer Singh | CSE-I | 05213202718 \n");
    //Get Number of Elements
    printf("\n Enter the no of elements in the list : \t");
    scanf("%d", &N);

    //Get List of Unsorted Elements
    printf("\n Enter the unsorted elements : \t");
    for(i=0;i<N;i++) scanf("%d", &array[i]);


    //Perform Insertion sort
    quick_sort(array, 0, N-1);

    //Print the sorted List
    printf("\n Sorted Listed is (Using Quick Sort) : \t");
    for(i=0; i<N; i++) printf("%d \t", array[i]);


    return 0;
}

void quick_sort(int array[], int first, int last){

    int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
        //places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
         while(array[i]<=array[pivot]&&i<last) i++;
         while(array[j]>array[pivot]) j--;
         if(i<j) swap(&array[i], &array[j]);
      }

      swap(&array[pivot],&array[j]);

      quick_sort(array,first,j-1);
      quick_sort(array,j+1,last);

   }

}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


