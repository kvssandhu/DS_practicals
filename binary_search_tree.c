// 17 : Implement insertion, deletion and display in binary search tree.
// Do three cases of deletion
// 25 Oct 2019

/*
 Test Case :
    1. Input the tree : 50 30 20 40 70 60 80
    2. Input the tree : 25 15 10 4 12 22 18 24 50 35 31 44 70 66 90

Input the tree in preorder traversal ( Root, Left, Right)
*/

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
struct node *delete_a_node(int item, struct node *node);

int main()
{
    int ch;
    int item=0;
    struct node *root=NULL;

    while(1){
        printf("\n Karanveer Singh | CSE-I | 05213202718 \n");
        printf("\n BST : Choose an option : \n");

        printf("\n 1. Insert into Tree \n 2. Delete  \n 3. Display \n 4. Exit \n");
        scanf("%d", &ch);

        switch(ch)
            {
            case 1 :    printf("\n Enter the item you want to insert : (press -1 to finish) \n ");

                        while(item!=-1){

                        printf("\n Enter Item : \t");
                        scanf("%d", &item);
                        if (item!= -1) root = insert_into_tree(item, root);
                        }
                        break;

            case 2 :    printf("\n Enter the value you want to delete : \t");
                        scanf("%d", &item);
                        delete_a_node(item, root);
                        break;

            case 3 : display_tree_in_2D(root, 0); break;

            case 4 : exit(0);
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

void display_tree_in_2D(struct node *node, int space)
{

    int COUNT=10, i;
    // Base case
    if (node == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    display_tree_in_2D(node->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d \n", node->info);

    // Process left child
    display_tree_in_2D(node->left, space);
}

struct node *delete_a_node(int item, struct node *node){
    //this function deletes the node(item) and return the root node.

    struct node *temp;
    int inorder_successor;

    //Base Case
    if(node == NULL) return node;

    //If item is less than root, it will lie in left subtree
    if ( item < node->info ) node->left =  delete_a_node(item, node->left);

    //If item is larger than the root, it will lie in right subtree.
    else if ( item > node->info ) node->right = delete_a_node(item, node->right);

    //After reaching the node which has to be deleted,
    else {

        // case 1 : when node has no child
        // case 2 : when node has one child
        if ( node->left == NULL ){
            // If left side of a node is null, then right side's child will become the parent node.
            temp = node->right;
            free(node);
            return temp;
        }

        else if (node->right == NULL) {
            //If the right side of a node is null, then left side's child will become the parent node
            temp = node->left;
            free(node);
            return temp;

        }

        // case 3 : when the node to be deleted has two children

        //get inorder successor of the parent node which has to be deleted
        inorder_successor = get_inorder_successor(node->right);

        //parent node will be replaced by its inorder successor
        node->info = inorder_successor;

        //delete the inorder successor from right side of the tree.
        node->right = delete_a_node( inorder_successor, node->right );

    }



    return node;
}

int get_inorder_successor(struct node *node){
    //inorder successor of a node in BST is the left most element in the tree.

        /* loop down to find the leftmost leaf */
    while (node && node->left != NULL)
        node = node->left;


    return node->info;
}
