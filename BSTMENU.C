/*
  i made this code without refering anything
  uploading this to your github to make a check that is it correct or not acc to its aim.
  AIM: IMPLEMENT INSERTION, DELETION AND DISPLAY IN BST(BINARY SEARCH TREE).
*/
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<windows.h>
#include<conio.h>
struct node
{
    int info;
    struct node *left;
    struct node *right;
}*root=NULL;
struct node *insert_into_tree(int item, struct node *node)
{
    if(node==NULL)
    {
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        new_node->info=item;
        new_node->left =NULL;
        new_node->right=NULL;
        printf("\n ");
        return new_node;
    }
    else if(node->info>=item)
    {
        printf("->Left");
        node->left=insert_into_tree(item,node->left);
    }
    else
    {
        printf("->Right");
        node->right=insert_into_tree(item,node->right);
    }
}
int preorder_traversal(struct node *node)
{
    int c;
    if(node==NULL)
    {
        printf("\n The tree is empty ");
        return 0;
    }
    else
        c=node->info;
    if (node->left!=NULL)
        c=preorder_traversal(node->left);
    if (node->right!=NULL)
        c=preorder_traversal(node->right);
    return c;
}
int display_tree(struct node *node,int l)
{
    int i;
    if(node==NULL)
    {
        return 0;
    }
    l+=10;
    display_tree(node->right,l);
    for(i=10; i<l; i++)
        printf(" ");
    printf("%d \n",node->info);
    display_tree(node->left,l);
    return 0;
}
int main()
{
    int ch,b=0,i=0,pos=-1,item[20],num,n;
    do
    {
        system("cls");
        printf("\n 1: Insertion in Tree ");
        printf("\n 2: Deletion in Tree ");
        printf("\n 3: Display Tree ");
        printf("\n 4: Exit ");
        printf("\n Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter total number of items : ");
            scanf("%d",&n);
            printf("\n Enter %d Items : ",n);
            for(i=0; i<n; i++)
                scanf("%d",&item[i]);
            for(i=0; i<n ; i++)
            {
                printf("\n Position of %d : Root",item[i]);
                root = insert_into_tree(item[i], root);
            }
            printf("\n Kushdeep Singh \n ");
            system("pause");
            break;
        case 2:
            printf("\n Enter item to be deleted ");
            scanf("%d",&num);
            for(i=0; i<n; i++)
            {
                if(item[i]==num)
                {
                    pos=i;
                    break;
                }
            }
            for(i=pos; i<n; i++)
                item[i]=item[i+1];
            n--;
            root=NULL;
            for(i=0; i<n; i++)
            {
                printf("\n Position of %d : Root",item[i]);
                root = insert_into_tree(item[i], root);
            }
            printf("\n Kushdeep Singh \n ");
            system("pause");
            break;
        case 3:
            printf("\n");
            if(root==NULL)
                printf(" Tree is empty");
            else
                display_tree(root,0);
            printf("\n Kushdeep Singh \n ");
            system("pause");
            break;
        case 4:
            exit(0);
        }
    }
    while(ch!=4);
    return 0;
}
