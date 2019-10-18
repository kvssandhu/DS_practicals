// 16: To create a binary tree and perform tree traversal with recursion -- Inorder, Preorder, Post order
// 18th Oct 2019


#include<stdio.h>

struct node
{
    struct node *left;
    char info;
    struct node *right;
} *root=NULL;


int main()
{
    int ch;
    char item;


    while(1){
        printf("\n Karanveer Singh | CSE-I | 05213202718 \n");
        printf("\n Choose an option : \n");
        printf("\n 1. Insert into Tree \n 2. Traverse \n 3. Exit \n");
        scanf("%d", &ch);

        switch(ch)
            {
            case 1 :    printf("\n Enter the item you want to insert : \n ");
                        scanf("%c", &item);
                        //insert_into_tree(item, root);
                        break;

            case 2 : traversal(); break;

            case 3 : exit(0);
            }

        }



    return 0;

}

void insert_into_tree(char item, struct node *selected_node)
{

    if(selected_node == NULL)
    {
        // if tree is empty
        selected_node = (struct node *) malloc(sizeof(struct node));
        selected_node->left = NULL;
        selected_node->right = NULL;
        selected_node->info = item;
    }

    if ( selected_node->info >= item )
    {
        insert_into_tree(item, selected_node -> left);
    }
    else
    {
        insert_into_tree(item, selected_node -> right);
    }


}

void traversal()
{

    int ch;

    printf("\n Choose the type of traversal : \n");
    printf("\n 1. Preorder Traversal \n 2. Inorder Traversal \n 3. Postorder Traversal \n");
    scanf("%d", &ch);

    switch(ch)
    {

    case 1 :
        preorder_traversal();
        break;

    case 2 :
        inorder_traversal();
        break;

    case 3 :
        postorder_traversal();
        break;

    }

}

int preorder_traversal()
{

    return 0;
}

int inorder_traversal()
{

    return 0;
}

int postorder_traversal()
{

    return 0;
}
