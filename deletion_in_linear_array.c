// Aim : To delete an element from user-defined position in a linear array

#include<stdio.h>

int main(){

        int array[10], N, i=0, delete_position;

        printf("Enter the number of elements in the array : \t ");
        scanf("%d", &N);

        while(i<N){
            scanf("%d", &array[i]);
            i++;
        }

        printf("Enter the position from which value has to be deleted : \t");
        scanf("%d", &delete_position);

        i=delete_position;

        while(i <= N -1 ){
            array[i-1] = array[i];
            i++;
        }

        N = N - 1;

        printf("\n Array is : \t ");

        i=0;

        while(i<N){

            printf("%d \t", array[i]);
            i++;

        }

return 0;
}

