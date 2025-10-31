#ifndef KD_TREE_H
#define KD_TREE_H

#include "kd_node.h"

// structure of representing a KD-tree 
typedef struct Tree{
    Node *root; 
    int dimension; 
    int size; 
} Tree; 

// creates a new empty KD-tree
Tree createTree(int dim){
    Tree tree; 
    tree.root = NULL; 
    tree.dimension = dim; 
    tree.size = 0; 
    return tree; 
} 

// destorys a KD-tree and free all memory 
void destroyTree(Tree *tree){
    if(!tree){
        return; 
    }
    destroyNode(tree->root); 
    tree->root = NULL; 
    tree->size = 0; 
}

// inserts a point into the tree 
int insertTree(Tree *tree, Point *point); 

// searches for a point in the tree
Point *searchTree(Tree *tree, Point *point); 

// deletes a point from the tree
int deleteTree(Tree *tree, Point *point); 

// finds the nearest neighbor to a query point 
Point *nearestNeighbor(Tree *tree, Point *query); 

// finds all point within a given distance of a query point 
int rangeSearch(Tree *tree, Point *query, double radius, Point *results, int max); 

// gets the size of the tree 
int treeSize(Tree *tree); 

// checks if the tree is empty 
int isEmpty(Tree *tree); 

// prints the tree structure 
void printTree(Tree *tree){
    if(!tree || !tree->root){
        printf("Empty KD-Tree\n"); 
        return; 
    }
    
    treeRecursive(tree->root, 0); 
} 

static void treeRecursive(Node *node, int level){
    if(!node){
        return; 
    }
    for(int x = 0; x < level, x++){
        printf(" "); 
    }
    printf("Depth %d: ", node->depth); 
    printPoint(node->point); 
    
    treeRecursive(node->left, level+1); 
    treeRecursive(node->right, level + 1); 
}

#endif
