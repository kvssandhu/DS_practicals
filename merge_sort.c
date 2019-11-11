// 20 : To implement merge sort using array
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
    merge_sort(array, 0, N);

    //Print the sorted List
    printf("\n Sorted Listed is (Using Merge Sort) : \t");
    for(i=0; i<N; i++) printf("%d \t", array[i]);


    return 0;
}

void merge(int array[], int l, int m, int r){
    /*
    -Merges two sub arrays of array[]
    -First sub array is array[l...m]
    -Second sub array is array[m+1...r]
    */

    int i,j,k;
    int n1 = m - l + 1; //No of elements in first sub array
    int n2 = r - m; // No of elements in second sub array


    int L[n1], R[n2]; //Initialize temp sub arrays

    //Add elements to L and R
    for(i=0;i<n1;i++) L[i] = array[l + i];
    for(j=0;j<n2;j++) R[j] = array[m + j + 1];

    //merge temp arrays back to array[]

    i = 0; j = 0; k = l;

    while( i<n1 && j<n2 ){
        if ( L[i] <= R[j] ) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}


}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */

void merge_sort(int array[], int l, int r){
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l+(r-l)/2;

		// Sort first and second halves
		merge_sort(array, l, m);
		merge_sort(array, m+1, r);

		merge(array, l, m, r);
	}

}


void insertion_sort(int array[], int N){
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
}
