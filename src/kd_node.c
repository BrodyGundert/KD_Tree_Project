#include <stdio.h>
#include <stdlib.h>
#include "../include/kd_node.h"

KDNode *kd_node_create(Point *p, int depth) {
    if (p == NULL) {
        return NULL;
    }
    
    KDNode *node = (KDNode *)malloc(sizeof(KDNode));
    if (node == NULL) {
        return NULL;
    }
    
    node->point = p;
    node->left = NULL;
    node->right = NULL;
    node->depth = depth;
    
    return node;
}

void kd_node_destroy(KDNode *node) {
    if (node == NULL) {
        return;
    }
    
    kd_node_destroy(node->left);
    kd_node_destroy(node->right);
    
    // Free the point if you're managing it here
    // point_destroy(node->point);
    
    free(node);
}

void kd_node_destroy_single(KDNode *node) {
    if (node != NULL) {
        free(node);
    }
}

int kd_node_get_axis(KDNode *node) {
    if (node == NULL || node->point == NULL) {
        return -1;
    }
    return node->depth % node->point->dimensions;
}

double kd_node_get_coordinate(KDNode *node) {
    if (node == NULL || node->point == NULL) {
        return 0.0;
    }
    
    int axis = kd_node_get_axis(node);
    return node->point->coordinates[axis];
}

void kd_node_print(KDNode *node) {
    if (node == NULL) {
        printf("NULL");
        return;
    }
    
    printf("Node (depth=%d): ", node->depth);
    point_print(node->point);
}
