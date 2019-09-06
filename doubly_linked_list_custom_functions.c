// Exp 7 : To create a doubly linked list with nodes having information about employees and perform insertion at front and deletion from end location.

#include<stdio.h>
#include<malloc.h>

struct node{

    struct node *previous;
    int employee_id;
    char employee_name[100];
    struct node *next;

} *start;

int main(){
    int ch,n,m,pos,i, employee_id;
    char employee_name[100];
    start=NULL;
    while(1)
    {
        printf("\n Karanveer Singh | CSE - I | 05213202718 \n");
        printf("\n 1. Create list");
        printf("\n 2. Display link list");
        printf("\n 3. Count number of elements in link list");
        printf("\n 4. Insert at beginning in the list");
        printf("\n 5. Delete from end of the list");
        printf("\n 6. Quit");
        printf("\n\n ==================== Enter Choice : \t");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter no. of nodes ");
            scanf("%d",&n);
            printf("\n Enter Employee ID and name \t");
            for(i=0; i<n; i++)
            {

                scanf("%d%s",&employee_id,employee_name);
                create_list( employee_id, employee_name);
            }
            break;
        case 2: display(); break;
        case 3: count(); break;
        case 4: printf("\n Enter Employee ID and name \t");
                scanf("%d%s",&employee_id,employee_name);
                insert_at_beginning(employee_id, employee_name);
                break;
        case 5: delete_from_end(); break;
        case 6: exit(0);
        default: printf("\n Wrong Choice");
        }
    }


    return 0;
}

int create_list(int employee_id, char employee_name[]){
    struct node *node,*new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> employee_id = employee_id;
    strcpy(new_node -> employee_name,employee_name);
    new_node->next=NULL;
    new_node->previous=NULL;
    if(start==NULL){
        start=new_node;
    }
    else
    {
        node = start;
        while(node->next!=NULL)
            node=node->next;
        node->next=new_node;
        new_node->previous = node;

    }
    return 0;
}

int display(){

    int ch;

    printf("\n Choose the type of traversal : \n");
    printf("\n 1. Traversal in Forward Direction \n 2. Traversal in Backward Direction \n");
    scanf("%d", &ch);

    switch(ch){

        case 1 : display_in_forward_direction(); break;
        case 2 : display_in_reverse_direction(); break;
        default : printf("\n Wrong Choice Entered \n");

    }
    return 0;
}

int display_in_forward_direction() {

    struct node *node;
    if(start == NULL)
    {
        printf("\n Link list is Empty");
        return;
    }
    node=start;
    printf("\n \t Employee ID \t | \t Employee Name ");
    while(node!=NULL)
    {
        printf(" \n \t %d \t \t \t %s ",node->employee_id, node->employee_name);
        node=node->next;
    }
    printf("\n");
    return 0;

}

int display_in_reverse_direction(){

    struct node *node;
    if(start == NULL)
    {
        printf("\n Link list is Empty");
        return;
    }
    node=start;
    while(node -> next !=NULL) node = node->next;

    printf("\n \t Employee ID \t | \t Employee Name ");
    while(node!=NULL)
    {
        printf(" \n \t %d \t \t \t %s ",node->employee_id, node->employee_name);
        node=node->previous;
    }
    printf("\n");
    return 0;
}

int count(){

    struct node *node=start;
    int count=0;
    while(node!=NULL){
        node = node -> next;
        count++;
    }

    printf("\n The number of Employee records in the list are %d \n", count);
    return 0;
}


int insert_at_beginning( int employee_id, char employee_name[100] ){
    struct node *node=start , *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> employee_id = employee_id;
    strcpy(new_node -> employee_name,employee_name);
    new_node -> next = start;
    node -> previous = new_node;
    new_node -> previous = NULL;
    start = new_node;
    printf("\n Element succesfully inserted at the beginning. \n");
    display();
    return 0;
}

int delete_from_end(){
    struct node *node=start;
    if( node == NULL ){
        printf("\n Underflow \n"); return 0;
    }
    else {
        while( node -> next -> next != NULL ) node = node -> next;
        node -> next = NULL;
    }
    display();

    return 0;
}



