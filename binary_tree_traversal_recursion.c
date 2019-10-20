// 16: To create a binary tree and perform tree traversal with recursion -- Inorder, Preorder, Post order
// 18th Oct 2019


#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct node
{
    struct node *left;
    int info;
    struct node *right;
};

struct node *insert_into_tree(int item, struct node *selected_node);

int main()
{
    int ch;
    int item=0;
    struct node *root=NULL;

    while(1){
        printf("\n Karanveer Singh | CSE-I | 05213202718 \n");
        printf("\n Choose an option : \n");

        printf("\n 1. Insert into Tree \n 2. Traverse \n 3. Exit \n");
        scanf("%d", &ch);

        switch(ch)
            {
            case 1 :    printf("\n Enter the item you want to insert : (press -1 to finish) \n ");
                        while(item!=-1){


                        printf("\n \n Enter Item : \t");
                        scanf("%d", &item);
                        if (item!= -1) root = insert_into_tree(item, root);
                        }
                        break;

            case 2 : traversal(root); break;

            case 3 : exit(0);
            }

        }



    return 0;

}

struct node *insert_into_tree(int item, struct node *selected_node)
{

    if(selected_node == NULL)
    {
        //if tree is empty
        struct node *node = (struct node *) malloc(sizeof(struct node));
        node -> info = item;
        node -> left = NULL;
        node -> right = NULL;

        return node;
    }
    else if ( selected_node->info >= item ) {
        selected_node->left = insert_into_tree(item, selected_node -> left);
    }
    else {
        selected_node->right = insert_into_tree(item, selected_node -> right);
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
    if (node==NULL)
    {
        printf("\n the tree is empty");
        return 0;
    }
    else printf(" %d ", node->info);

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
    printf(" %d ", node->info);

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
    printf(" %d ", node->info );


    return 0;
}
