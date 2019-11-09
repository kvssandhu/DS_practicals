// 19 : To implement selection sort using array
// 25 Oct 2019

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
    selection_sort(array, N);

    //Print the sorted List
    printf("\n Sorted Listed is (Using Selection Sort) : \t");
    for(i=0; i<N; i++) printf("%d \t", array[i]);


    return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(int array[], int N){

    int i,j;

    for(i=0;i<N-1;i++){
        for(j=i; j<N;j++){
            if (array[i] > array[j]) swap(&array[i], &array[j]);
        }
    }
}
