// Aim : To insert an element at user defined position in a linear array.

#include<stdio.h>

int main(){

        int array[10], N, i=0, item, insert_position;

        printf("Enter the number of elements in the array : \t ");
        scanf("%d", &N);

        while(i<N){
            scanf("%d", &array[i]);
            i++;
        }

        printf("Enter the position at which value has to be inserted : \t");
        scanf("%d", &insert_position);

        printf("Enter the value to be inserted : \t");
        scanf("%d", &item);



        i=N;
        while(i>=insert_position - 1 ){

            array[i+1] = array[i];

            i--;
        }

        array[insert_position - 1] = item;

        N = N + 1;
        printf("\n Array is : \t ");

        i=0;
        while(i<N){

            printf("%d \t", array[i]);
            i++;

        }
        printf("\n \n Karanveer Singh | CSE -I | 052-13202718 \n");
        return 0;
}
