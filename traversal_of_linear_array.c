// Aim : To traverse the elements of a linear array

#include<stdio.h>

int main(){

int array[10], i=0, N;

printf("Enter the number of elements in the array : \t");
scanf("%d", &N);

printf("Input the array elements one by one : \t ");

while(i<N){
    scanf("%d", &array[i]);
    i++;
}

i=0;

printf("Array is : \t ");

while(i<N){

    printf("%d \t", array[i]);
    i++;

}

return 0;
}
