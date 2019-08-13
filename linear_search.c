// Aim : To search an elemnt from a linear array using linear search

#include<stdio.h>


int main(){

int array[20], N, item, i=0, loc=0, is_item_found=0;

//Input array from user
printf("\n Enter the number of elements in the array : \t ");
scanf("%d", &N);

printf("\n Input the array elements : \t ");
while(i<N){
    scanf("%d", &array[i]);
    i++;
}

printf("\n Input the item to search : \t");
scanf("%d", &item);

for(i=0; i<N; i++){

    if(array[i] == item){
        is_item_found = 1;
        loc = i;
        break;
    }

}

if (is_item_found == 1) printf("\n Required Item %d is found at position %d in the array", item, loc+1 );
else printf("\n Required Item not found in the array");

printf("\n \n Karanveer Singh | CSE -I | 052-13202718 \n");


return 0;
}
