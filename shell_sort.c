// 21 : To implement shell sort using array
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
    shell_sort(array, N);

    //Print the sorted List
    printf("\n Sorted Listed is (Using Shell Sort) : \t");
    for(i=0; i<N; i++) printf("%d \t", array[i]);


    return 0;
}

void shell_sort(int array[], int N){

    int i, j, gap, temp;

    for(gap = N/2; gap > 0; gap /= 2){
        // Gap keeps reducing by half after every iteration

        for( i = gap; i<N; i++ ){
            //for a particular gap value iteration this loop will run. -- Sublist
            temp = array[i];
            for(j = i; j>=gap && array[j-1] > temp ; j-=gap ){
                    array[j] = array[j - gap];
            }
            array[j] = temp;

        }
    }
}
