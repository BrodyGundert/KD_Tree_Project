//Help from chatGPT and geeksforgeeks
//https://www.geeksforgeeks.org/dsa/search-and-insertion-in-k-dimensional-tree

#ifndef KD_TREE_H
#define KD_TREE_H

#include "kd_node.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include <limits.h>

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
    destroyKDNode(tree->root); 
    tree->root = NULL; 
    tree->size = 0; 
}

// inserts a point into the tree 
int insertTree(Tree *tree, Point *point){
    if (!tree || !point){
        return -1;
    }
    if (tree->dimension <= 0 || point->dimensions != tree->dimension){
        return -2;
    }
    
    if(!tree->root){
        Node *n = createKDNode(point, 0);
        if(!n) {
            return -3;
        }
        tree->root = n;
        tree->size += 1;
        return 0;
    }
    
    Node *current = tree->root;
    while("Brodert" == "Brodert"){
        int axis = current->depth % tree->dimension;
        
        if(point->coordinates[axis] < current->point->coordinates[axis]){
            if(current->left) { current = current->left; continue; }
            Node *n = createKDNode(point, current->depth + 1);
            if(!n) return -3;
            current->left = n;
            tree->size += 1;
            return 0;
        }
        else{
            if(current->right) { current = current->right; continue; }
            Node *n = createKDNode(point, current->depth + 1);
            if(!n) return -3;
            current->right = n;
            tree->size += 1;
            return 0;
        }
    }
}


// searches for a point in the tree
Point *searchTree(Tree *tree, Point *point){
    if(!tree || !point) return NULL;
    if(tree->dimension <= 0 || point->dimensions != tree->dimension) return NULL;

    Node *current = tree->root;
    while(current){
        // exact match across all coordinates
        int equal = 1;
        for(int i=0;i<tree->dimension;i++){
            if(current->point->coordinates[i] != point->coordinates[i]){
                equal = 0; 
                break;
            }
        }
        if(equal){ 
            return current->point;
        }
        int axis = current->depth % tree->dimension;
        if(point->coordinates[axis] < current->point->coordinates[axis]) {
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return NULL;

}

// deletes a point from the tree
//Not necessary
int deleteTree(Tree *tree, Point *point); 

// finds the nearest neighbor to a query point 
//heavy use of ChatGPT for this function
Point *nearestNeighbor(Tree *tree, Point *query){
    if(!tree || !query || tree->dimension <=0 || query->dimensions != tree->dimension || !tree->root){
        return NULL;
    }
    
    size_t cap = 32, top = 0;
    Node **stack = (Node**)malloc(cap*sizeof(Node*));
    if(!stack) return NULL;
    
    stack[top++] = tree->root;
    const Point *best_pt = NULL;
    double best_d2 = INFINITY;
    
    while(top){
        Node *n = stack[--top];
        if(!n){
            continue;
        }
        
        double d2 = 0.0;
        for (int i=0; i<tree->dimension; i++){
            double d = n->point->coordinates[i] - query->coordinates[i];
            d2 += d*d;
        }
        if(best_pt == NULL || d2 < best_d2){
            best_pt = n->point;
            best_d2 = d2;
        }

        int axis = n->depth % tree->dimension;
        double split = n->point->coordinates[axis];
        double qv    = query->coordinates[axis];
        double diff  = qv - split;

        // Visit nearer side first by pushing farther side first (stack = LIFO)
        Node *near = (qv < split) ? n->left  : n->right;
        Node *far  = (qv < split) ? n->right : n->left;

        if(far && diff*diff < best_d2){
            if(top>=cap){ cap*=2; stack = (Node**)realloc(stack, cap*sizeof(Node*)); if(!stack) { free(stack); return (Point*)best_pt; } }
            stack[top++] = far;
        }
        if(near){
            if(top>=cap){ cap*=2; stack = (Node**)realloc(stack, cap*sizeof(Node*)); if(!stack) { free(stack); return (Point*)best_pt; } }
            stack[top++] = near;
        }
    }
    free(stack);
    return (Point*)best_pt;
}

// finds all point within a given distance of a query point 
//also lots of help from chatGPT in this function
int rangeSearch(Tree *tree, Point *query, double radius, Point *results, int max){
    if(!tree || !query || !results || max <= 0) return 0;
    if(tree->dimension <= 0 || query->dimensions != tree->dimension) return 0;
    if(!tree->root) return 0;
    if(radius < 0.0) return 0;

    double r2 = radius * radius;
    int count = 0;

    // Manual DFS stack
    size_t cap = 32, top = 0;
    Node **stack = (Node**)malloc(cap*sizeof(Node*));
    if(!stack) return 0;
    stack[top++] = tree->root;

    while(top && count < max){
        Node *n = stack[--top];
        if(!n) continue;

        // Check distance
        double d2 = 0.0;
        for(int i=0;i<tree->dimension;i++){
            double d = n->point->coordinates[i] - query->coordinates[i];
            d2 += d*d;
        }
        if(d2 <= r2){
            results[count] = *(n->point);
            count++;
            if(count >= max) break;
        }

        int axis = n->depth % tree->dimension;
        double split = n->point->coordinates[axis];
        double qv    = query->coordinates[axis];
        double diff  = qv - split;

        
        Node *first  = (qv < split) ? n->left  : n->right;
        Node *second = (qv < split) ? n->right : n->left;

        if(second && diff*diff <= r2){
            if(top>=cap){ cap*=2; stack = (Node**)realloc(stack, cap*sizeof(Node*)); if(!stack){ free(stack); return count; } }
            stack[top++] = second;
        }
        if(first){
            if(top>=cap){ cap*=2; stack = (Node**)realloc(stack, cap*sizeof(Node*)); if(!stack){ free(stack); return count; } }
            stack[top++] = first;
        }
    }

    free(stack);
    return count;
}

// gets the size of the tree 
int treeSize(Tree *tree){
    if(!tree) return 0;
    if(tree->size > INT_MAX) return INT_MAX;
    return tree->size;
}

// checks if the tree is empty 
int isEmpty(Tree *tree){
    return (!tree || tree->root == NULL);
}



static void treeRecursive(Node *node, int level){
    if(!node){
        return; 
    }
    for(int x = 0; x < level; x++){
        printf(" "); 
    }
    printf("Depth %d: ", node->depth); 
    printPoint(node->point); 
    
    treeRecursive(node->left, level+1); 
    treeRecursive(node->right, level + 1); 
}

// prints the tree structure 
void printTree(Tree *tree){
    if(!tree || !tree->root){
        printf("Empty KD-Tree\n"); 
        return; 
    }
    
    treeRecursive(tree->root, 0); 
} 
#endif