// Exp 8 : To create a circular linked list of college records and perform insertion in beginning and deletion from end location.

// College : College ID, College Name

// Atleast 5 records


#include<stdio.h>
#include<malloc.h>

struct node{
    int college_id;
    char college_name[100];
    struct node *next;

} *start;

int main(){
    int ch,n,m,pos,i, college_id;
    char college_name[100];
    start=NULL;
    printf("\n Karanveer Singh | CSE - I | 05213202718 \n");
    while(1)
    {
        printf("\n 1. Create list");
        printf("\n 2. Display link list");
        printf("\n 3. Count number of elements in link list");
        printf("\n 4. Insertion at Beginning");
        printf("\n 5. Deletion from End");
        printf("\n 6. Quit");
        printf("\n\n ==================== Enter Choice : \t");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter no. of nodes ");
            scanf("%d",&n);
            printf("\n Enter College ID and name \t");
            for(i=0; i<n; i++)
            {

                scanf("%d%s",&college_id,college_name);
                create_list( college_id, college_name);
            }
            break;
        case 2: display(); break;
        case 3: count(); break;
        case 4: printf("\n Enter College ID and name \t");
                scanf("%d%s",&college_id,college_name);
                insert_at_beginning(college_id,college_name); break;
        case 5: delete_from_end(); break;
        case 6: exit(0);
        default: printf("\n Wrong Choice");
        }
    }


    return 0;
}

int create_list(int college_id, char college_name[]){
    struct node *node,*new_node;
    new_node = (struct node *) malloc (sizeof(struct node));
    new_node -> college_id = college_id;
    strcpy(new_node -> college_name,college_name);
    new_node->next = start;

    if(start==NULL)
        start=new_node;
    else
    {
        node = start;
        while(node->next!=start) node=node->next;
        node->next=new_node;
    }
    return 0;
}

int display(){
    struct node *node;
    if(start == NULL)
    {
        printf("\n Link list is Empty");
        return;
    }
    node=start;
    printf("\n \t College ID \t | \t College Name ");
    while( node -> next != start)
    {
        printf(" \n \t %d \t \t \t %s ",node->college_id, node->college_name);
        node = node -> next;
    }
    printf("\n");
    return 0;
}

int count(){

    struct node *node=start;
    int count=0;
    while(node -> next !=start){
        node = node -> next;
        count++;
    }

    printf("\n The number of College records in the list are %d \n", count);
    return 0;
}

int insert_at_beginning( int college_id, char college_name[100] ){
    struct node *new_node;
    new_node = (struct node *) malloc (sizeof(struct node));
    new_node -> college_id = college_id;
    strcpy(new_node -> college_name,college_name);
    new_node -> next = start;
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
        while( node -> next -> next != start ) node = node -> next;
        node -> next = NULL;
    }
    display();

    return 0;
}
