//Aim : To search an element from a linear using binary search.

#include<stdio.h>

int main(){

int array[20], N, item, i=0, beg, end, mid, loc, is_item_found = 0;

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

beg=0; end=N;
mid=(beg+end)/2;

while( beg <= end && array[mid] != item ){

    if( item<array[mid] ) end= mid -1;
    else beg= mid + 1;

    mid=(beg+end)/2;

}

if(array[mid]==item) {is_item_found = 1;loc=mid;}

if(is_item_found = 0) printf("\n Requested item not found in the given array ");
else printf("\n Requested item %d found at position %d in the array", item, loc+1);

printf("\n \n Karanveer Singh | CSE -I | 052-13202718 \n");

return 0;
}
