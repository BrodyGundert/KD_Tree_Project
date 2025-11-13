#ifndef KD_NODE_H
#define KD_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
        return NULL; 
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

// free a single node and doesn't free children 
void destroySingleKDNode(Node *node) {
    if (!node) return;
    if (node->point) destroyPoint(node->point);
    free(node);
}

// free a KD tree and all its children  
void destroyKDNode(Node *node) {
    if (!node) return;
    destroyKDNode(node->left);
    destroyKDNode(node->right);
    destroySingleKDNode(node);
} 

// gets the splitting axis for a node based on its depth 
int getAxis(Node *node){
    if (!node || (!node->point) || (node->point->dimensions <= 0)){
        return -1;
    } 
    return node->depth % node->point->dimensions;
} 

// gets the coordinate value for the splitting acis 
double getCoordinate(Node *node) {
    int axis = getAxis(node);
    if (axis < 0){
        return NAN;
    }
    return node->point->coordinates[axis];
}

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


