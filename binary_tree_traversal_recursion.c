// 16: To create a binary tree and perform tree traversal with recursion -- Inorder, Preorder, Post order
// 18th Oct 2019


#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *insert_into_tree(int item, struct node *selected_node);

int main()
{
    int ch;
    int item;
    struct node *root=NULL;

    while(1){
        printf("\n Karanveer Singh | CSE-I | 05213202718 \n");
        printf("\n Choose an option : \n");

        printf("\n 1. Insert into Tree \n 2. Traverse \n 3. Exit \n");
        scanf("%d", &ch);

        switch(ch)
            {
            case 1 :    printf("\n Enter the item you want to insert : \n ");
                        scanf("%d", &item);
                        root = insert_into_tree(item, root);
                        printf("\n \n Entered value in root is %d", root->info);
                        break;

            case 2 : traversal(root); break;

            case 3 : exit(0);
            }

        }



    return 0;

}

struct node *insert_into_tree(int item, struct node *selected_node)
{


if (selected_node==NULL) printf("\n Select node is null"); else printf("\n selected_node is not null");

    if(selected_node == NULL)
    {
        //if tree is empty
        struct node *node = (struct node *) malloc(sizeof(struct node));
        node -> info = item;
        node -> left = NULL;
        node -> right = NULL;

        printf("\n Data inserted in new node is %d", node->info);
        return node;
    }
    else {
                    printf("\n Selected node Info is %d and item is %d", selected_node->info, item);

        if ( selected_node->info >= item ) {

                selected_node->left = insert_into_tree(item, selected_node -> left);

                }
        else selected_node->right = insert_into_tree(item, selected_node -> right);

    }

}

void traversal(struct node *node)
{

    int ch;

    printf("\n Choose the type of traversal : \n");
    printf("\n 1. Preorder Traversal \n 2. Inorder Traversal \n 3. Postorder Traversal \n");
    scanf("%d", &ch);

    switch(ch)
    {

    case 1 :
        preorder_traversal(node);
        break;

    case 2 :
        inorder_traversal(node);
        break;

    case 3 :
        postorder_traversal(node);
        break;

    }

}

int preorder_traversal(struct node *node)
{
    //Process the Root Node
    if (node!=NULL) printf("%d", node->info);
    else {
        printf("\n the tree is empty");
        return 0;
    }

    // Left Node
    if (node->left != NULL) preorder_traversal(node->left);

    // Right Node
    if (node->right != NULL) preorder_traversal(node->right);

    return 0;
}

int inorder_traversal(struct node *node)
{
    if(node==NULL) {
        printf("\n The tree is empty \n");
        return 0;
    }

    //Process the left node
    if(node->left != NULL) inorder_traversal(node->left);

    //Process the root node
    printf("%d", node->info);

    //Process the right node
    if(node->right != NULL) inorder_traversal(node->right);

    return 0;
}

int postorder_traversal(struct node *node)
{
    if(node==NULL) {
        printf("\n The tree is empty \n");
        return 0;
    }

    //Process the left node
    if (node->left != NULL) postorder_traversal(node->left);

    //Process the right node
    if (node->right != NULL) postorder_traversal(node->right);

    //Process the root node
    printf("%d", node->info );


    return 0;
}
