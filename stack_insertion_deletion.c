// to perform insertion and deletion operation on stack using linked list

// Date 11th October

#include<stdio.h>

struct node{
    int info;
    struct node *next;

} *top=NULL;


int main(){

int item, ch, i;

while (ch!=4){
        printf("\n Karanveer Singh | CSE - I | 05213202718 \n");
        printf("\n \n Select the operation you want to perform on Stack : \n");
        printf("\n 1. Insertion \n 2. Deletion \n 3.Display \n 4. Exit \n \n");
        scanf("%d", &ch);


        switch(ch){

            case 1 : printf("\n Enter the item you want to push: \t ");
                     scanf("%d", &item);
                     stack_insertion(item);
                     break;

            case 2 :stack_deletion();
                    break;

            case 3 : display_stack();
                     break;

            case 4 : exit(0);

        };

}

return 0;
}

int stack_insertion(int item){

    struct node *node,*new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> info = item;
    new_node -> next = top;

    top = new_node;

    printf("\n Item inserted successfully in the Stack \n");


return 0;
}

int stack_deletion(){
                    struct node *node;
                    if(top == NULL)
                    {
                        printf("\n Underflow");
                        return;
                    }
                    node = top;
                    printf("\n Deleting Item %d from the stack", node->info);
                    top = node->next;
                    printf("\n Item Deleted Succesfully from the stack \n");


return 0;
}

int display_stack(){
                    struct node *node;
                    if(top == NULL)
                    {
                        printf("\n Stack is Empty");
                        return;
                    }
                    node=top;
                    printf("\n Stack is :  ");
                    while(node!=NULL)
                    {
                        printf("  \t %d ",node->info);
                        node=node->next;
                    }
                    printf("\n");
                    return 0;
}
