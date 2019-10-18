// 14 : To create a linear queue using array
// 18th Oct 2019

#include<stdio.h>

int queue[10], N=5, FRONT = -1, REAR = -1;

int main(){

   int ch, item;


   while(1){
        printf("\n Karanveer Singh | CSE - I | 05213202718 \n");
        printf("\n Choose one of the following options : \n");
        printf("\n 1. Insertion \n 2. Deletion \n 3. Display \n 4. Exit \n \n ");
        scanf("%d", &ch);


       switch(ch){

        case 1 : printf("\n Enter the item you want to insert : \t");
                 scanf("%d", &item);
                 insertion(item);
                 break;

        case 2 : deletion();
                 break;

        case 3 : display(); break;

        case 4 : exit(0);

       }

   }

return 0;
}

int insertion(int item){

    if ( REAR == N-1 ) {
            printf("\n Overflow ");
            return 0;
    }

    if ( FRONT == -1 ) {    //initially the queue is empty
        FRONT = 0; REAR = 0;
    }
    else REAR = REAR + 1;

    queue[REAR] = item;
    printf("\n %d inserted successfully \n", item);

    return 0;
}

int deletion(){
    int item;

    if (FRONT == -1) {
        printf("\n Underflow \n");
        return 0;
    }

    item = queue[FRONT];

    if ( FRONT == REAR ){ // Only one element is in queue
        FRONT = -1;
        REAR = -1;
    }

    else FRONT = FRONT + 1;

    return 0;
}

int display(){

    int i;

    for(i=FRONT; i<=REAR; i++){
        printf("\t %d", queue[i]);
    }

    return 0;
}
