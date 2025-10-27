#ifndef KD_NODE_H
#define KD_NODE_H

#include "point.h"

/**
 * Structure representing a node in a KD-tree
 */
typedef struct kd_node {
    Point *point;
    struct kd_node *left;
    struct kd_node *right;
    int depth;  // Depth of this node in the tree (determines splitting axis)
} KDNode;

/**
 * Create a new KD tree node
 * @param p Point to store in the node
 * @param depth Depth of the node
 * @return Pointer to new KDNode, or NULL on failure
 */
KDNode *kd_node_create(Point *p, int depth);

/**
 * Free a KD tree node and all its children
 * @param node Node to free
 */
void kd_node_destroy(KDNode *node);

/**
 * Free a single node (does not free children)
 * @param node Node to free
 */
void kd_node_destroy_single(KDNode *node);

/**
 * Get the splitting axis for a node based on its depth
 * @param node Node to get axis for
 * @return Split axis (0-based dimension index)
 */
int kd_node_get_axis(KDNode *node);

/**
 * Get the coordinate value for the splitting axis
 * @param node Node to get coordinate from
 * @return Coordinate value
 */
double kd_node_get_coordinate(KDNode *node);

/**
 * Print a node (for debugging)
 * @param node Node to print
 */
void kd_node_print(KDNode *node);

#endif // KD_NODE_H
