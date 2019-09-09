#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
#include<dos.h>
struct node
{
    int clg_id;
    char clg_name[20];
    struct node *next;
}*start;
void create_list()
{
    struct node *new_node,*node;
    int clgid;
    char a[20];
    printf("\n Enter college id = -1 to end");
    printf("\n Enter College Id ");
    scanf("%d",&clgid);
    printf("\n Enter College name ");
    scanf("%s",&a);
    while(clgid!=-1)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node->clg_id=clgid;
        strcpy(new_node->clg_name,a);
        if(start==NULL)
        {
            new_node->next=new_node;
            start=new_node;
        }
        else
        {
            node=start;
            while(node->next!=start)
                node=node->next;
            new_node->next=start;
            node->next=new_node;
        }
        printf("\n Enter College Id ");
        scanf("%d",&clgid);
        if(clgid!=-1)
        {
            printf("\n Enter College name ");
            scanf("%s",&a);
        }

    }
}
void display()
{
    struct node *node;
    if(start==NULL)
    {
        printf("\n List is empty ");
        return;
    }
    node=start;
    printf("\n List is: ");
    do
    {
        printf("\n College Id: %d",node->clg_id);
        printf("\n College Name: %s",node->clg_name);
        node=node->next;
    }
    while(node!=start);
}
void addtobeg()
{
    struct node *new_node,*node;
    int clgid;
    char a[20];
    printf("\n Enter College Id ");
    scanf("%d",&clgid);
    printf("\n Enter College name ");
    scanf("%s",&a);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->clg_id=clgid;
    strcpy(new_node->clg_name,a);
    node=start;
    while(node->next!=start)
        node=node->next;
    node->next=new_node;
    new_node->next=start;
    start=new_node;
}
void count()
{
    struct node *node=start;
    int cnt=0;
    do
    {
        node=node->next;
        cnt++;
    }
    while(node!=start);
    printf("\n No. of elements are %d ",cnt);
}
void delfromend()
{
    struct node *node=start,*preptr;
    if(node==NULL)
    {
        printf("\n Underflow error ");
        return;
    }
    while(node->next!=start)
    {
        preptr=node;
        node=node->next;
    }
    preptr->next=node->next;
    free(node);
}
int main()
{
    int ch1,ch2,ch3,ch,n,clgid,i,pos;
    char a[20];
    start=NULL;
    do
    {
        system("cls");
        printf("\n 1: Create text ");
        printf("\n 2: Insertion ");
        printf("\n 3: Display ");
        printf("\n 4: Count ");
        printf("\n 5: Deletion ");
        printf("\n 6: Quit ");
        printf("\n Enter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create_list();
            printf("\n Kushdeep Singh ");
            Sleep(2000);
            break;
        case 2:
            addtobeg();
            display();
            printf("\n Kushdeep Singh ");
            Sleep(4000);
            break;
        case 3:
            display();
            printf("\n Kushdeep Singh ");
            Sleep(4000);
            break;
        case 4:
            count();
            Sleep(4000);
            break;
        case 5:
            delfromend();
            display();
            printf("\n Kushdeep Singh ");
            Sleep(4000);
            break;
        case 6:
            break;
        default:
            printf("\n Wrong Choice ");
        }
    }
    while(ch!=6);
    return 0;
}
