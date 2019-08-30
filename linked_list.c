//Exp 6 : To create a single linked list with nodes having information about students i.e. Name, Roll No. and perform creation, insertion, deletion, count, reversal and display operations.

#include<stdio.h>
#include<malloc.h>

struct node{
    int stu_roll_no;
    char stu_name[100];
    struct node *next;

} *start;

int main(){
    int ch,n,m,pos,i, stu_roll_no;
    char stu_name[100];
    start=NULL;
    while(1)
    {
        printf("\n 1. Create list");
        printf("\n 2. Add at Beginning");
        printf("\n 3. Display link list");
        printf("\n 4. Count number of elements in link list");
        printf("\n 5. Reverse the order of link list");
        printf("\n 6. Insert an element in the list");
        printf("\n 7. Delete an element from the list");
        printf("\n 8. Quit");
        printf("\n\n ==================== Enter Choice : \t");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter no. of nodes ");
            scanf("%d",&n);
            printf("\n Enter Student Roll no and name \t");
            for(i=0; i<n; i++)
            {

                scanf("%d%s",&stu_roll_no,stu_name);
                create_list( stu_roll_no, stu_name);
            }
            break;
        case 2: add_at_beg(); break;
        case 3: display(); break;
        case 4: count(); break;
        case 5: rev(); break;
        case 6: select_insert_choice(); break;
        case 7: select_delete_choice(); break;
        case 8: exit(0);
        default: printf("Wrong Choice");
        }
    }


    return 0;
}

int create_list(int stu_roll_no, char stu_name[]){
    struct node *node,*new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> stu_roll_no = stu_roll_no;
    strcpy(new_node -> stu_name,stu_name);
    new_node->next=NULL;
    if(start==NULL)
        start=new_node;
    else
    {
        node = start;
        while(node->next!=NULL)
            node=node->next;
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
    printf("\n \t Roll No \t | \t Student Name ");
    while(node!=NULL)
    {
        printf(" \n \t %d \t \t \t %s ",node->stu_roll_no, node->stu_name);
        node=node->next;
    }
    printf("\n");
    return 0;
}

int add_at_beg(int data){

printf("Add at beg func called.");

return 0;
}

int count(){

struct node *node=start;
int count=0;
while(node!=NULL){
    node = node -> next;
    count++;
}

printf("\n The number of student records in the list are %d \n", count);
return 0;
}

int rev(){


struct node *p1, *p2, *p3;

if( start->next == NULL) return 0;

p1 = start; p2 = p1 -> next; p3 = p2 -> next;

p1 -> next = NULL;
p2 -> next = p1;

while (p3 != NULL){
                p1 = p2;
                p2 = p3;
                p3 = p3 -> next;
                p2 -> next = p1;
}

start = p2;

printf("\n Reversing of the linked list is succesfull. \t");

return 0;
}

int select_insert_choice(){
    int ch, stu_roll_no, insert_position;
    char stu_name[100];
    printf("\n Enter Student Roll no and name \t");
    scanf("%d%s",&stu_roll_no,stu_name);

    printf("\n Select the type of insertion : ");
    printf("\n 1. Insertion at the beginning \n 2. Insertion at the End \n 3. Insertion at specified location. \n");
    scanf("%d", &ch);
    switch(ch){
        case 1 : insert_at_beginning(stu_roll_no,stu_name); break;
        case 2 : insert_at_end(stu_roll_no,stu_name); break;
        case 3 : printf("\n Enter the position where you want to insert : \t");
                 scanf("%d", &insert_position);
                 insert_at_specified_location( insert_position, stu_roll_no,stu_name);
                 break;

        default : printf("\n Wrong Choice Entered \n");
    }
return 0;
}

int insert_at_beginning( int stu_roll_no, char stu_name[100] ){
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> stu_roll_no = stu_roll_no;
    strcpy(new_node -> stu_name,stu_name);
    new_node -> next = start;
    start = new_node;
    printf("\n Element succesfully inserted at the beginning. \n");
    display();
    return 0;
}

int insert_at_end( int stu_roll_no, char stu_name[100] ){
    struct node *node = start, *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> stu_roll_no = stu_roll_no;
    strcpy(new_node -> stu_name,stu_name);
    new_node -> next = NULL;
    while(node->next != NULL){
        node = node->next;
    }
    node -> next = new_node;

    printf("\n Element succesfully inserted at the end. \n");
    display();
    return 0;
}

int insert_at_specified_location( int insert_position, int stu_roll_no, char stu_name[100] ){
    struct node *node=start,*new_node;
    int count=1;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> stu_roll_no = stu_roll_no;
    strcpy(new_node -> stu_name,stu_name);
    while( count < insert_position - 1){
            node = node -> next;
            count ++;
    }
    new_node -> next = node -> next;
    node -> next = new_node;
    display();
    return 0;
}

int select_delete_choice(){
    int ch, delete_position;
    printf("\n Select the type of Deletion : ");
    printf("\n 1. Delete from the beginning \n 2. Delete from the End \n 3. Delete from specified location. \n");
    scanf("%d", &ch);
    switch(ch){
        case 1 : delete_from_beginning(); break;
        case 2 : delete_from_end(); break;
        case 3 : printf("\n Enter the position of the item you wish to delete : \t");
                 scanf("%d", &delete_position);
                 delete_from_specified_location(delete_position);
                 break;
        default : printf("\n Wrong Choice Entered \n");
    }
    return 0;
}

int delete_from_beginning(){
    struct node *node=start;
    if( node == NULL ){
        printf("\n Underflow \n"); return 0;
    }
    else {
        start = node -> next;
    }
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

int delete_from_specified_location(int delete_position){
    struct node *node=start;
    int count=1;
    if( node == NULL ){
        printf("\n Underflow \n"); return 0;
    }
    else {
        while( count < delete_position - 1 ) { node = node -> next; count++; };
        node -> next = node -> next -> next;
    }
    display();
return 0;
}

