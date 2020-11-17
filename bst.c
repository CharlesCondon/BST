//Author: Charles Condon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/* A node structure to create a new node in an empty tree */
bst_node * newNode(char * word) {
    bst_node * temp = malloc(sizeof(bst_node));
    temp->data = word;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Recursive add function
 * Parameters:
 *  root - the pointer to the root of the tree
 *  word - user given string to add to the tree
 * Return value:
 *  none
 */
void add2 ( bst_node ** root, char * word) {
    char * temp = (*root) -> data;

    // check if given string is smaller than root
    if ( strcmp(temp, word) > 0 ) {

        // if at furthest left node then insert, otherwise call function on left
        if ((*root) -> left == NULL) {

            bst_node *current = newNode(word);
            ((*root) -> left) = current;
            return;
        }
        else {
            add2 ( (&(*root) -> left), word );

        }
    }
    else {
        // if at furthest right node then insert, otherwise call function on right
        if ((*root) -> right == NULL) {

            bst_node *current = newNode(word);
            ((*root) -> right) = current;
            return;
        }
        else {
            add2 ( (&(*root) -> right), word );

        }
    }
}

/* Wrapper add function
 * Parameters:
 *  root - the pointer to the root of the tree
 *  word - user given string to add to the tree
 * Return value:
 *  none
 */
void add ( bst_node ** root, char * word ) {

    // check if given word is null
    if (word == NULL) {
        return;
    }
    // check if root is null
    if ((*root) == NULL) {
        bst_node * n = newNode(word);
        (*root) = n;
        return;
    }
    // check if given word is equal to root
    char * temp = (*root) -> data;
    if ( strcmp(temp, word) == 0 ) {
        return;
    }
    else {
        add2( root, word );
        return;
    }
}


/* Prints the values stored in the bst to standard output according to
 * the inorder traversal. The values should be separated
 * by a single space.
 * Parameters:
 *  root - the root of the tree
 * Return value:
 *  none
 */
void inorder ( bst_node * root ) {
    if (root != NULL) {
        inorder( root -> left);
        printf ( "%s ", root -> data );
        inorder ( root -> right);
    }
}


/* Removes the node with the smallest value
 * in the tree.
 * Parameters:
 *  root - the pointer to the root of the tree
 * Return value:
 *  the string from the removed node or
 *  NULL if no node was removed.
 */
char * removeSmallest (  bst_node ** root ) {
    // tree is empty
    if ( (*root) == NULL) {
        return NULL;
    }

    bst_node * current = (*root);
    bst_node * parent = (*root);

    // begin iterating over left sub-tree
    while ( (current -> left) != NULL ) {
        parent = current;
        current = (current -> left);
    }

    // check if smallest node has a right child
    if ( current -> right != NULL ) {

        // if root only contains right sub-tree
        if ( current == (*root) ) {
            (*root) = (*root) -> right;
            char * min = current -> data;
            free(current);
            current = NULL;
            return min;
        }

        // replace smallest node with right sub-tree
        else{
            parent -> left = current -> right;
            char * min = current -> data;
            free(current);
            current = NULL;
            return min;
        }
    }

    // smallest node has no children
    else{
        // check if smallest is root
        if (current == *root){
            char * min = current -> data;
            free(current);
            current = NULL;
            parent = NULL;
            *root = NULL;
            return min;
        }

        // otherwise remove node as normal
        else{
            parent -> left = NULL;
            char * min = current -> data;
            free(current);
            current = NULL;
            return min;
        }
    }
}


/* Removes the node with the largest value
 * in the tree.
 * Parameters:
 *  root - the pointer to the root of the tree
 * Return value:
 *  the string from the removed node or
 *  NULL if no node was removed.
 */
char * removeLargest (  bst_node ** root ){
    // tree is empty
    if ( (*root) == NULL) {
        return NULL;
    }

    bst_node * current = (*root);
    bst_node * parent = (*root);

    // begin iterating over left sub-tree
    while ( (current -> right) != NULL ) {
        parent = current;
        current = (current -> right);
    }

    // check if smallest node has a left child
    if ( current -> left != NULL ) {

        // if root only contains left sub-tree
        if ( current == (*root) ) {
            (*root) = (*root) -> left;
            char * min = current -> data;
            free(current);
            current = NULL;
            return min;
        }

        // replace smallest node with left sub-tree
        else{
            parent -> right = current -> left;
            char * min = current -> data;
            free(current);
            current = NULL;
            return min;
        }
    }

    // smallest node has no children
    else{
        // check if smallest is root
        if (current == *root){
            char * min = current -> data;
            free(current);
            current = NULL;
            parent = NULL;
            *root = NULL;
            return min;
        }

        // otherwise remove node as normal
        else{
            parent -> right = NULL;
            char * min = current -> data;
            free(current);
            current = NULL;
            return min;
        }
    }
}
