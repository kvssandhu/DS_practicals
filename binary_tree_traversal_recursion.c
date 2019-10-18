// 16: To create a binary tree and perform tree traversal with recursion -- Inorder, Preorder, Post order
// 18th Oct 2019


#include<stdio.h>
#include<string.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
} *root=NULL;


int main()
{
    int ch;
    int item;


    while(1){
        printf("\n Karanveer Singh | CSE-I | 05213202718 \n");
        printf("\n Choose an option : \n");
        printf("\n 1. Insert into Tree \n 2. Traverse \n 3. Exit \n");
        scanf("%d", &ch);

        switch(ch)
            {
            case 1 :    printf("\n Enter the item you want to insert : \n ");
                        scanf("%d", &item);
                        printf("%d", item);
                        insert_into_tree(item, root);
                        break;

            case 2 : traversal(); break;

            case 3 : exit(0);
            }

        }



    return 0;

}

void insert_into_tree(int item, struct node *selected_node)
{
    if(selected_node == NULL)
    {
        // if tree is empty
        printf("\n I am here \n");
        selected_node -> info = item;
        selected_node -> left = NULL;
        selected_node -> right = NULL;

    }
    else {

       if ( selected_node->info >= item )
        {
            insert_into_tree(item, selected_node -> left);
        }
        else
        {
            insert_into_tree(item, selected_node -> right);
        }
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
        preorder_traversal(root);
        break;

    case 2 :
        inorder_traversal(root);
        break;

    case 3 :
        postorder_traversal(root);
        break;

    }

}

int preorder_traversal(struct node *node)
{
    //Process the Root Node
    printf("%d", node->info);

    // Left Node
    preorder_traversal(node->left);

    // Right Node
    preorder_traversal(node->right);

    return 0;
}

int inorder_traversal(struct node *node)
{
    //Process the left node
    inorder_traversal(node->left);

    //Process the root node
    printf("%d", node->info);

    //Process the right node
    inorder_traversal(node->right);

    return 0;
}

int postorder_traversal(struct node *node)
{

    //Process the left node
    postorder_traversal(node->left);

    //Process the right node
    postorder_traversal(node->right);

    //Process the root node
    printf("%d", node->info );


    return 0;
}
