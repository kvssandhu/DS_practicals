// Aim : To traverse the elements of a linear array

#include<stdio.h>

int get_no_of_elements_in_array(){

        int N;
        printf("Enter the number of elements in the array : \t");
        scanf("%d", &N);
        return N;

}


int get_array_from_user(number_of_elements){

int array[20],i=0;

printf("Input the array elements one by one : \t ");

while(i<number_of_elements){
    scanf("%d", &array[i]);
    i++;
}

return array[20];
}
int main(){

int array[20], i=0, N;

N = get_no_of_elements_in_array();

array[20] = get_array_from_user(N);

i=0;

printf("Array is : \t ");

while(i<N){

    printf("%d \t", array[i]);
    i++;

}

return 0;
}
