#ifndef KD_TREE_H
#define KD_TREE_H

#include "kd_node.h"

/**
 * Structure representing a KD-tree
 */
typedef struct {
    KDNode *root;
    int dimension;  // Number of dimensions
    int size;       // Number of points in the tree
} KDTree;

/**
 * Create a new empty KD-tree
 * @param dim Number of dimensions
 * @return Pointer to new KDTree, or NULL on failure
 */
KDTree *kd_tree_create(int dim);

/**
 * Destroy a KD-tree and free all memory
 * @param tree Tree to destroy
 */
void kd_tree_destroy(KDTree *tree);

/**
 * Insert a point into the tree
 * @param tree Tree to insert into
 * @param point Point to insert
 * @return 0 on success, -1 on failure
 */
int kd_tree_insert(KDTree *tree, Point *point);

/**
 * Search for a point in the tree
 * @param tree Tree to search
 * @param point Point to search for
 * @return Pointer to found point, or NULL if not found
 */
Point *kd_tree_search(KDTree *tree, Point *point);

/**
 * Delete a point from the tree
 * @param tree Tree to delete from
 * @param point Point to delete
 * @return 0 on success, -1 if point not found
 */
int kd_tree_delete(KDTree *tree, Point *point);

/**
 * Find the nearest neighbor to a query point
 * @param tree Tree to search
 * @param query Query point
 * @return Pointer to nearest point, or NULL if tree is empty
 */
Point *kd_tree_nearest_neighbor(KDTree *tree, Point *query);

/**
 * Find all points within a given distance of a query point
 * @param tree Tree to search
 * @param query Query point
 * @param radius Maximum distance
 * @param results Array to store results
 * @param max_results Maximum number of results
 * @return Number of points found
 */
int kd_tree_range_search(KDTree *tree, Point *query, double radius, 
                         Point **results, int max_results);

/**
 * Get the size of the tree
 * @param tree Tree to check
 * @return Number of points in the tree
 */
int kd_tree_size(KDTree *tree);

/**
 * Check if the tree is empty
 * @param tree Tree to check
 * @return 1 if empty, 0 otherwise
 */
int kd_tree_is_empty(KDTree *tree);

/**
 * Print the tree structure (for debugging)
 * @param tree Tree to print
 */
void kd_tree_print(KDTree *tree);

#endif // KD_TREE_H
