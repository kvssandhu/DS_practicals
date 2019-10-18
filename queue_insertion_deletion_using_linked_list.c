// 15 : To create a linear queue using linked list
// 18th Oct 2019


#include<stdio.h>

struct node{
    int info;
    struct node *next;

} *FRONT=NULL, *REAR=NULL;

int main(){

   int ch, item;


   while(1){
        printf("\n Karanveer Singh | CSE - I | 05213202718 \n");
        printf("\n Choose one of the following options : \n");
        printf("\n 1. Insertion \n 2. Deletion \n 3. Display \n 4. Exit \n \n ");
        scanf("%d", &ch);


       switch(ch){

        case 1 :printf("\n Enter the item you want to insert : \t");
                scanf("%d", &item);
                insertion(item);
                break;

        case 2 : deletion(); break;

        case 3 : display(); break;

        case 4 : exit(0);

       }

   }

return 0;
}

int insertion(item){
    struct node *queue, *new_queue;

    if(FRONT==NULL){ // Queue is empty

        queue = (struct node *) malloc(sizeof(struct node));
        queue -> info = item;
        queue -> next = FRONT;
        FRONT = queue;
        REAR = FRONT;

    }
    else
    { // Queue is not empty initially
        queue = FRONT;
        while(queue != REAR )
            queue=queue->next;

        new_queue = (struct node *) malloc(sizeof(struct node));
        new_queue -> info = item;
        new_queue -> next = queue -> next;
        queue -> next = new_queue;
        REAR = new_queue;

    }

    printf("\n %d inserted successfully \n", item);
    return 0;
}

int deletion(){
    struct node *queue;

    if(FRONT==NULL){
        printf("\n Underflow \n");
        return 0;
    }
    else if( FRONT == REAR ) {// Only One element exists
            FRONT = NULL;
            REAR = NULL;
    }
    else {
        queue = FRONT;
        printf("\n Deleting %d from the queue \n", queue -> info);
        FRONT = queue->next;
    }


return 0;
}

int display(){
    struct node *queue;
    if(FRONT == NULL)
    {
        printf("\n Queue is Empty \n");
        return;
    }
    queue=FRONT;
    while(queue!=NULL)
    {
        printf(" \t %d",queue->info);
        queue=queue->next;
    }
    printf("\n");
    return 0;
}
