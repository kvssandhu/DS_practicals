#include<stdio.h>
#include<malloc.h>

struct student_details {
    int roll_no;
    char name[100];
};

struct node
{
    struct student_details *stu_details;
    struct node *next;

} *start;

int main()
{
    int ch,n,m,pos,i;
    start=NULL;
    while(1)
    {
        printf("\n 1. Create list");
        printf("\n 2. Add at Beginning");
        printf("\n 3. Display link list");
        printf("\n 4. Count number of elements in link list");
        printf("\n 5. Reverse the order of link list");
        printf("\n 6. Quit");
        printf("\n\n Enter Choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter no. of nodes ");
            scanf("%d",&n);

            for(i=0; i<n; i++)
            {
                printf("Enter element");
                scanf("%d",&m);
                create_list(m, "name");
            }
            break;
        case 2: add_at_beg(); break;
        case 3: display(); break;
        case 4: count(); break;
        case 5: rev(); break;
        case 6: exit(0);
        default: printf("Wrong Choice");
        }
    }


    return 0;
}

int create_list(int stu_roll_no, char stu_name[100])
{
    struct node *node,*new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> stu_details -> roll_no = stu_roll_no;
   // new_node -> stu_details -> name = stu_name ;
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

int display()
{
    struct node *node;
    if(start == NULL)
    {
        printf("\n Link list is Empty");
        return;
    }
    node=start;
    printf("\n List is ");
    while(node!=NULL)
    {
        printf("%d \t", node -> stu_details -> roll_no);
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

printf("\n The number of elements in the list are %d", count);
return 0;
}

int rev(){

printf("Reverse list func called");

struct node *p1, *p2, *p3;

if( start -> next == NULL ) return 0;

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

return 0;
}



