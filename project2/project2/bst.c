/*
The author of this file is Aditi Kanaujia. All the coding is done by me, Aditi. 
This file outputs methods of a binary search tree. The three methods are add which 
adds a node to the tree. Remove smallest which traverse all the way to the left of 
the tree and removes that value (because it is the smallest). Remove right which 
has the same logic and remove left but in the opposite direction. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

void add(bst_node **root, char *word) {
    if (*root == NULL) {
        *root = (bst_node *)malloc(sizeof(bst_node)); // allocates memory for a new node
        (*root)->data = strdup(word); //sets root data to word
        (*root)->left = NULL; //null left
        (*root)->right = NULL; //null right child
    } else {
        //recursively iterates through the tree until it finds desired spot
        int comp = strcmp(word, (*root)->data);
        if (comp > 0) {
            add(&((*root)->right), word);
        } else if (comp < 0) {
            add(&((*root)->left), word);
        }
    }
}
void inorder(bst_node *root) {
    if (root == NULL)
        return;
    //recursively traverses through tree printing data from left then from right
    inorder(root->left);
    printf("%s ", root->data);
    inorder(root->right);
} 

//keeps going to the left until it hits null and removes values
char *removeSmallest(bst_node **root) {
    if (*root == NULL)
        return NULL;

    // ff the left child is NULL, it means we've reached the smallest node
    if ((*root)->left == NULL) {
        char *removed = strdup((*root)->data); // store removed node's data to return
        free((*root)->data); // Free the memory allocated for data
        bst_node *temp = *root; // temporary pointer to store the current root
        *root = (*root)->right; // update the root to the right child
        free(temp);
        return removed; // Return the removed node's data
    }
    else {
        // continue recursively traversing to the left child until we find the smallest node
        return removeSmallest(&((*root)->left));
    }
}



//keepings going to the right until it hits null and removes the value
//same as removesmallest but instead this traverses right to find largest node
char *removeLargest(bst_node **root) {
    if (*root == NULL)
        return NULL;

    if ((*root)->right == NULL) {
        char *removed = strdup((*root)->data);
        free((*root)->data);
        free(*root);
        *root = NULL;
        return removed;
    }
    else {
        return removeLargest(&((*root)->right));
    }
}




