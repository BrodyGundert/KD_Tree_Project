#ifndef KD_NODE_H
#define KD_NODE_H

#include "point.h"

// structure representing a node in a KD-tree 
typedef struct Node{
    Point *point; 
    struct Node *left; 
    struct Node *right; 
    int depth; 
}Node; 

// creates a new KD tree node 
Node *createKDNode(Point *p, int depth){
    if(!p){
        printf("Error. Cannot create node with NULL point.\n"); 
        return NULL: 
    }
    
    Node *node = (Node *)malloc(sizeof(Node)); 
    if(!node){
        printf("Error. Memory allocation failed.\n"); 
        return NULL; 
    }
    
    node->point = p; 
    node->left = NULL; 
    node->right = NULL; 
    node->depth = depth; 
    
    return node; 
}

// free a KD tree and all its children  
void destroyKDNode(Node *node); 

// free a single node and doesn't free children 
void destroySingleKDNode(Node *node); 

// gets the splitting axis for a node based on its depth 
int getAxis(Node *node); 

// gets the coordinate value for the splitting acis 
double getCoordinate(Node *node); 

//prints a node, main purpose is for debugging 
void printKDNode(Node *node){
    if(!node){
        printf("(Null Node)\n"); 
        return; 
    }
    printf("Node (depth = %d, axis = %d): ", node->depth, getAxis(node)); 
    printPoint(node->point); 
} 

#endif
