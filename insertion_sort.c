// 18 : To implement insertion sort using array
//25 Oct 2019


#include<stdio.h>

int main(){
    int array[20], N, i;

    //Get Number of Elements
    printf("\n Enter the no of elements in the list : \t");
    scanf("%d", &N);

    //Get List of Unsorted Elements
    printf("\n Enter the unsorted elements : \t");
    for(i=0;i<N;i++) scanf("%d", &array[i]);


    //Perform Insertion sort
    insertion_sort(array, N);

    //Print the sorted List
    printf("\n Sorted Listed is : \t");
    for(i=0; i<N; i++) printf("%d \t", array[i]);


    return 0;
}

int insertion_sort(int array[], int N){
//N : Number of Elements in unsorted array

int i, j, key;

//For each pass
for(i=1; i<N; i++){

    //Insert next element element from unsorted list.
    key = array[i];
    j = i-1;

    // Compare and swap for each element of sorted list.
    while( j>=0 && array[j]>key ){
        array[j+1] = array[j];
        j = j - 1;
    }

    array[j+1] = key;

}
return 0;
}
