// Aim : To sort a linear array using Bubble Sort

#include<stdio.h>

int main(){

int array[20], N, i=0, ptr, temp=0;

//Input array from user
printf("\n Enter the number of elements in the array : \t ");
scanf("%d", &N);

printf("\n Input the array elements : \t ");
while(i<N){
    scanf("%d", &array[i]);
    i++;
}

for(i=0;i<N; i++){

    ptr =0;
    while( ptr <= N-i ){
        if(array[ptr] > array[ptr+1] ){
            temp = array[ptr+1];
            array[ptr+1] = array[ptr];
            array[ptr] = temp;
        }
        ptr=ptr+1;
    }

}

printf("\n Sorted array is  : \t ");

for(i=0; i<N; i++) printf("%d \t", array[i]);

printf("\n \n Karanveer Singh | CSE -I | 052-13202718 \n");

return 0;
}
